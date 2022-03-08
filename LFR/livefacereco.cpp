//
// Created by markson zhang
//
//
// Edited by Xinghao Chen 2020/7/27
//
#include <iostream>
#include <fstream>
#include <queue>
#include <stdio.h>
#include "include/FacePreprocess.h"
#include <numeric>
#include <math.h>
#include "livefacereco.hpp"
#include <time.h>
#include "live.h"
#include "mtcnn_new.h"

#define PI 3.14159265
using namespace std;
using namespace cv;

/**
 * This is a normalize function before calculating the cosine distance. Experiment has proven it can destory the
 * original distribution in order to make two feature more distinguishable.
 * mean value is set to 0 and std is set to 1
 */
Mat Zscore(const Mat &fc)
{
	Mat mean, std;
	meanStdDev(fc, mean, std);
	//cout <<"mean is :"<< mean <<"std is :"<< std << endl;
	Mat fc_norm = (fc - mean) / std;
	return fc_norm;
}

/**
 * This module is using to computing the cosine distance between input feature and ground truth feature
 *  */
inline float CosineDistance(const cv::Mat &v1, const cv::Mat &v2)
{
	double dot = v1.dot(v2);
	double denom_v1 = norm(v1);
	double denom_v2 = norm(v2);
	return dot / (denom_v1 * denom_v2);
}

/**
 * Calculating the turning angle of face
 *  */
inline double count_angle(float landmark[5][2])
{
	double a = landmark[2][1] - (landmark[0][1] + landmark[1][1]) / 2;
	double b = landmark[2][0] - (landmark[0][0] + landmark[1][0]) / 2;
	double angle = atan(abs(b) / a) * 180 / PI;
	return angle;
}


/**
 * Formatting output structure
 */
inline cv::Mat draw_conclucion(String intro, double input, cv::Mat result_cnn, int position) {
	char string[10];
	sprintf(string, "%.2f", input);
	std::string introString(intro);
	introString += string;
	putText(result_cnn, introString, cv::Point(5, position), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 255, 255),2);
	return result_cnn;
}
/**
 * Face Recognition pipeline using camera.
 * Firstly, it will use MTCNN face detector to detect the faces [x,y,x2,y2] and [eyes, nose, cheeks] landmarks
 * Then, face alignment will be implemented for wraping the face into decided center point
 * Next, the aligned face will be sent into ncnn-mobilefacenet-arcface model and campare with faces in database
 * Finally, some imformation will be shown on the frame
 *
 */

LiveFaceReco::LiveFaceReco()
{
	msgHandler.start();

	source = new DetectionSource(&msgHandler);
	source->personalInfos = &personalInfos;

	//OpenCV Version
	cout << "OpenCV Version: " << CV_MAJOR_VERSION << "."
		 << CV_MINOR_VERSION << "."
		 << CV_SUBMINOR_VERSION << endl;
}

LiveFaceReco::~LiveFaceReco()
{
	msgHandler.stop();
	for (int i = 0; i < videoDetections.size(); i++)
	{
		delete videoDetections[i];
	}
	delete source;
}

LiveFaceReco::VideoDetection::VideoDetection(LFRMsgHandler *msgHandler, LiveFaceReco::DetectionSource *source)
{
	m_msgHandler = msgHandler;
	m_source = source;

	drawingText = true;
	recieverConnected = false;
	count = 0;
	similarity = 0;
	sumFPS = 0;
}

LiveFaceReco::VideoDetection::~VideoDetection()
{
	videoSrc.release();
}

bool LiveFaceReco::VideoDetection::connectCamera(int cameraIndex)
{
	return initCamera(cameraIndex);
}

void LiveFaceReco::VideoDetection::connectMessages(LFRMsgHandler *msgHandler)
{
	m_msgHandler = msgHandler;
}

std::mutex mutDetect, mutLive, mutArcface;

LiveFaceReco::DetectionInfo LiveFaceReco::VideoDetection::MTCNNDetection()
{
	LiveFaceReco::DetectionInfo ret;
	ret.detected = false;
	ret.confidence = 0;
	ret.similarity = 0;
	ret.id = -1;
	if (!videoSrc.isOpened())
		return LiveFaceReco::DetectionInfo();
	//cv::String name;
	//std::string hi_name;
	//std::string liveface;
	bool stranger, close_enough;
	Mat frame;
	Mat result_cnn;
	double angle = 0;

	//static int count = 0;

	auto highlightLandmarks = [&](int i)
	{
		//highlight the significant landmarks on face
		Scalar scalar;
		for (int j = 0; j < 5; ++j)
		{
			if (j == 0 or j == 3)
				scalar = Scalar(0, 255, 0);
			else if (j == 2)
				scalar = Scalar(255, 0, 0);
			else
				scalar = Scalar(0, 0, 255);
			cv::circle(result_cnn, Point(faceInfos[i].ppoint[j]*ratio_x, faceInfos[i].ppoint[j + 5]*ratio_y), 3, scalar, FILLED, LINE_AA);
		}
	};

	//	auto putName = [&](cv::String imgName)
	//	{
	//		//put name
	//		name = imgName.substr(imgName.rfind('/') + 1, imgName.length() - 4);
	//		name = name.substr(0, imgName.length() - 4);
	//		hi_name = "Name: "+ name;
	//		drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
	//		return name;
	//	};



	count++;
	clock_t t = clock();

	videoSrc >> frame;
	cv::flip(frame, frame, 1);
	resize(frame, result_cnn, frame_size, INTER_LINEAR);

	if (count % 2 == 0)
	{
		mutDetect.lock();
		faceInfos = detect_mtcnn(frame);
		mutDetect.unlock();

		largest_number = findLargestFace(faceInfos);
	}

	if (!faceInfos.empty())
	{

		//the faces to operate
		Bbox faceInfo = faceInfos[largest_number];
		float x_ = faceInfo.x1, y_ = faceInfo.y1, x2_ = faceInfo.x2, y2_ = faceInfo.y2;
		int x = x_, y = y_, x2 = x2_, y2 = y2_;
		LiveFaceBox live_box = {x_, y_, x2_, y2_};

		//highlight the significant landmarks on face
		highlightLandmarks(largest_number);
		cv::rectangle(result_cnn, Point(x * ratio_x, y * ratio_y), Point(x2 * ratio_x, y2 * ratio_y), cv::Scalar(0, 0, 255), 2);
		// Perspective Transformation
		float v2[5][2] =
		{{faceInfo.ppoint[0], faceInfo.ppoint[5]},
		 {faceInfo.ppoint[1], faceInfo.ppoint[6]},
		 {faceInfo.ppoint[2], faceInfo.ppoint[7]},
		 {faceInfo.ppoint[3], faceInfo.ppoint[8]},
		 {faceInfo.ppoint[4], faceInfo.ppoint[9]},
		};


		// compute the turning angle
		angle = count_angle(v2);

		/****************************jump*****************************************************/
		if (count % jump == 0 && !m_source->personalInfos->empty())
		{

			cv::Mat dst(5, 2, CV_32FC1, v2);
			memcpy(dst.data, v2, 2 * 5 * sizeof(float));

			cv::Mat m = FacePreprocess::similarTransform(dst, m_source->src);
			cv::Mat aligned = frame.clone();
			cv::warpPerspective(frame, aligned, m, cv::Size(96, 112), INTER_LINEAR);
			resize(aligned, aligned, Size(112, 112), 0, 0, INTER_LINEAR);


			//features of camera image
			cv::Mat fc2 = m_source->reco.getFeature(aligned);

			// normalize
			fc2 = Zscore(fc2);

			//the similarity score
			vector<double> scores;
			for (unsigned int i = 0; i < m_source->personalInfos->size(); ++ i)
				scores.push_back(CosineDistance(m_source->personalInfos->at(i).face, fc2));
			int maxPosition = max_element(scores.begin(), scores.end()) - scores.begin();
			ret.id = m_source->personalInfos->at(maxPosition).id;
			similarity = scores[maxPosition];
			ret.similarity = similarity;
			scores.clear();

			if (similarity >= face_thre && y2-y >= distance_threshold)
			{

				//name = putName(m_source->image_names[maxPosition]);
				//m_msgHandler->addMessage(name);
				//determin whethe it is a fake face
				confidence = m_source->live.Detect(frame, live_box);
				ret.confidence = confidence;


				//drawText(result_cnn, to_string(confidence), Point(x*ratio_x, y2*ratio_y+20), cv::Scalar(0,255,255));
				//liveface = (confidence <= true_thre) ? ("Fake face!!") : ("True face");
				//drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 0, 255));
				//m_msgHandler->addMessage(liveface);
				stranger = false;
				close_enough = true;
			}
			else if(similarity >= face_thre && y2-y < distance_threshold)
			{
				//putName(m_source->image_names[maxPosition]);
				//Ask be closer to avoid mis-reco
				//drawText(result_cnn, "Closer please", Point(5, 60), cv::Scalar(0, 255, 255));
				//m_msgHandler->addMessage("Ближе пожалуйста!");
				stranger = false;
				close_enough = false;
			}
			else
			{
				//drawText(result_cnn, "Stranger", Point(5, 60), cv::Scalar(255, 0, 0));
				//m_msgHandler->addMessage("Не уверен...");
				stranger = true;
			}
		}
		else
		{
			//			if(stranger)
			//			{
			//				//drawText(result_cnn, "Stranger", Point(5, 60), cv::Scalar(255, 0, 0));
			//			}
			//			else if(close_enough)
			//			{
			//				drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
			//				drawText(result_cnn, to_string(confidence), Point(x*ratio_x, y2*ratio_y+20), cv::Scalar(0,255,255));
			//				if (liveface.length() == 9)
			//					drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 255, 0));
			//				else
			//					drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 0, 255));
			//			}
			//			else
			//			{
			//				drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
			//				drawText(result_cnn, "Closer please", Point(5, 80), cv::Scalar(0, 255, 255));
			//			}

			if (count == 10 * jump - 1)
				count = 0;
		}
		//drawText(result_cnn, to_string(similarity), Point(x*ratio_x, y2*ratio_y), cv::Scalar(0, 255, 0));
	}


	fps.push(1000000.0 / (double)(clock() - t));
	int fpsnum_ = fps.size();
	float fps_mean;
	//compute average fps value
	if(fpsnum_ <= 30)
	{
		sumFPS += fps.back();
		fps_mean = sumFPS /  fpsnum_;
	}
	else
	{
		sumFPS += fps.back();
		sumFPS -= fps.front();
		fps_mean = sumFPS /  30;
		fps.pop();
	}

	ret.fps = fps_mean;
	ret.angle = angle;

	result_cnn = draw_conclucion("FPS: ", fps_mean, result_cnn, 20);//20
	result_cnn = draw_conclucion("Angle: ", angle, result_cnn, 40);//65

	ret.frame = result_cnn.clone();

	return ret;

}

void LiveFaceReco::connectMessages(std::queue<string> *queue, mutex *mutex)
{
	msgHandler.connectQueue(queue, mutex);
}

int LiveFaceReco::addVideoSource(int cameraIndex)
{
	VideoDetection *vd = new VideoDetection(&msgHandler, source);
	if (vd->connectCamera(cameraIndex) == false)
	{
		delete vd;
		return -1;
	}
	videoDetections.push_back(vd);
	return videoDetections.size() - 1;
}

void LiveFaceReco::loadTmpInfoFromFile(const string &fileName)
{
	msgHandler.addMessage("Start loading TMP");
	personalInfos.clear();
	ifstream file(fileName, ios::binary | ios::ate);
	if (!file.is_open())
	{
		msgHandler.addMessage("Loading failed (can't open file)");
		return;
	}
	int fileSize = file.tellg();
	char *bytes = new char[fileSize];
	char *ptr = bytes;
	file.seekg(0, ios_base::beg);
	file.read(bytes, fileSize);
	int cardsCount = *((int *)ptr);
	ptr += sizeof(int);
	PersonalInfo info;
	int matWidth, matHeight, matType, matSize;
	for (int i = 0; i < cardsCount; ++i)
	{
		matSize = *((int *)ptr);
		ptr += sizeof(int);
		matWidth = *((int *)ptr);
		ptr += sizeof(int);
		matHeight = *((int *)ptr);
		ptr += sizeof(int);
		matType = *((int *)ptr);
		ptr += sizeof(int);
		info.id = *((int *)ptr);
		ptr += sizeof(int);
		info.face = cv::Mat(matHeight, matWidth, matType, ptr).clone();
		ptr += matSize * sizeof(char);
		info.fileName = string(ptr);
		ptr += info.fileName.size() * sizeof(char);
		personalInfos.push_back(info);
	}
	file.close();
	msgHandler.addMessage("TMP loaded: " + to_string(personalInfos.size()));
	delete[] bytes;
}

void LiveFaceReco::saveTmpInfoToFile(const string &fileName)
{
	if (personalInfos.empty())
		return;
	msgHandler.addMessage("Start saving TMP");
	int matSize = personalInfos[0].face.cols * personalInfos[0].face.rows * personalInfos[0].face.elemSize();
	int fileSize = sizeof(int) + personalInfos.size() * (5 * sizeof(int) + matSize);
	for (int i = 0; i < personalInfos.size(); ++i)
		fileSize += personalInfos[i].fileName.size();
	ofstream file(fileName, ios::binary);
	char *bytes = new char[fileSize];
	char *ptr = bytes;
	*((int *)ptr) = (int)personalInfos.size();
	ptr += sizeof(int);
	for (int i = 0; i < personalInfos.size(); ++i)
	{
		*((int *)ptr) = matSize;
		ptr += sizeof(int);
		*((int *)ptr) = personalInfos[i].face.cols;
		ptr += sizeof(int);
		*((int *)ptr) = personalInfos[i].face.rows;
		ptr += sizeof(int);
		*((int *)ptr) = personalInfos[i].face.type();
		ptr += sizeof(int);
		*((int *)ptr) = personalInfos[i].id;
		ptr += sizeof(int);
		memcpy(ptr, personalInfos[i].face.data, matSize);
		ptr += matSize * sizeof(char);
		memcpy(ptr, personalInfos[i].fileName.c_str(), personalInfos[i].fileName.size());
		ptr += personalInfos[i].fileName.size() * sizeof(char);
	}
	file.write(bytes, fileSize);
	file.close();
	msgHandler.addMessage("TMP saved: " + to_string(personalInfos.size()) + "size = " + to_string(fileSize));
	delete[] bytes;
}

void LiveFaceReco::addPersonalInfo(const string &filename)
{
	PersonalInfo info;
	info.face = Zscore(reco.getFeature(cv::imread(filename)));
	info.id = personalInfos.size();
	personalInfos.push_back(info);
}

void LiveFaceReco::updatePersonalInfos(const vector<string> &filenames)
{
	PersonalInfo info;
	for (int i = 0; i < filenames.size(); ++i)
	{
		info.face = Zscore(reco.getFeature(cv::imread(filenames[i])));
		info.fileName = filenames[i];
		info.id = i;
		personalInfos.push_back(info);
	}
}

string LiveFaceReco::fileNameByID(int id)
{
	return personalInfos[id].fileName;
}

LiveFaceReco::DetectionReceiver *LiveFaceReco::createDetectionReciever(int videoIndex)
{
	if (videoIndex >= videoDetections.size())
		return nullptr;
	if (videoDetections[videoIndex]->isRecieverConnected())
		return nullptr;
	return new DetectionReceiver(videoDetections[videoIndex]);
}

void LiveFaceReco::VideoDetection::setDrawing(bool drawing)
{
	drawingText = drawing;
}

bool LiveFaceReco::VideoDetection::isRecieverConnected() const
{
	return recieverConnected;
}

void LiveFaceReco::VideoDetection::setRecieverConnected(bool connected)
{
	recieverConnected = connected;
}

bool LiveFaceReco::VideoDetection::initCamera(int cameraIndex)
{
	videoSrc.open(cameraIndex);
	videoSrc.set(CAP_PROP_FRAME_WIDTH, input_width);
	videoSrc.set(CAP_PROP_FRAME_HEIGHT, input_height);
	videoSrc.set(CAP_PROP_FPS, 90);
	return videoSrc.isOpened();
}

int LiveFaceReco::VideoDetection::findLargestFace(const vector<Bbox> &faceInfo)
{
	//find the laggest face
	int lagerest_face = 0, largest_number = 0;
	for (int i = 0; i < faceInfo.size(); i++)
	{
		int y_ = faceInfo[i].y2;
		int h_ = faceInfo[i].y1;
		if (h_ - y_ > lagerest_face)
		{
			lagerest_face = h_ - y_;
			largest_number = i;
		}
	}
	return largest_number;
}

void LiveFaceReco::VideoDetection::drawText(const Mat &img, const string &text, const Point &point, const Scalar &color)
{
	if (drawingText)
		putText(img, text, point, cv::FONT_HERSHEY_SIMPLEX,0.75, color,2);
}

LiveFaceReco::DetectionSource::DetectionSource(LFRMsgHandler *msgHandler)
{
	m_msgHandler = msgHandler;

	//OpenCV Version
	cout << "OpenCV Version: " << CV_MAJOR_VERSION << "."
		 << CV_MINOR_VERSION << "."
		 << CV_SUBMINOR_VERSION << endl;

	configureLiveDetection();
	initSourceMatrix();
}

//bool LiveFaceReco::DetectionSource::readImages()
//{
//	// loading faces
//	std::string pattern_jpg = project_path+ "/img/*.jpg";

//	cv::glob(pattern_jpg, image_names);
//	image_number = image_names.size();
//	m_msgHandler->addMessage("loaded " + to_string(image_number) + " pictures...");
//	//cout << "loaded " << image_number << " pictures..." << endl;
//	if (image_number == 0)
//		return false;
//	return true;
//}

bool LiveFaceReco::DetectionSource::configureLiveDetection()
{
	//Live detection configs
	ModelConfig config1 = {2.7f, 0.0f, 0.0f, 80, 80, "model_1", false};
	ModelConfig config2 = {4.0f, 0.0f, 0.0f, 80, 80, "model_2", false};
	vector<ModelConfig> configs;
	configs.emplace_back(config1);
	configs.emplace_back(config2);
	live.LoadModel(configs);
	return true;
}

//bool LiveFaceReco::DetectionSource::convertImages()
//{
//	//convert to vector and store into fc, whcih is benefical to furthur operation
//	Mat  face;
//	char str[7];
//	for (size_t i = 0; i < image_number; ++i)
//	{
//		face = cv::imread(image_names[i]);
//		faces.push_back(reco.getFeature(face));
//		faces[i] = Zscore(faces[i]);
//		sprintf(str, "%4.2lf", i*100.0 / (double)(image_number - 1));
//		m_msgHandler->addMessage("loading[" + string(str) + "%]");
//		//printf("\rloading[%.2lf%%]",  i*100.0 / (image_number - 1));
//	}
//	//cout << endl;
//	//float factor = 0.709f;
//	//float threshold[3] = {0.7f, 0.6f, 0.6f};
//	m_msgHandler->addMessage("loading succeed!" + to_string(image_number) + " pictures in total");
//	//cout <<"loading succeed! "<<image_number<<" pictures in total"<<endl;
//	return true;
//}

bool LiveFaceReco::DetectionSource::initSourceMatrix()
{
	// gt face landmark
	//	v1 = {
	//		{30.2946f, 51.6963f},
	//		{65.5318f, 51.5014f},
	//		{48.0252f, 71.7366f},
	//		{33.5493f, 92.3655f},
	//		{62.7299f, 92.2041f}};
	v1[0][0] = 30.2946f;
	v1[0][1] = 51.6963f;
	v1[1][0] = 65.5318f;
	v1[1][1] = 51.5014f;
	v1[2][0] = 48.0252f;
	v1[2][1] = 71.7366f;
	v1[3][0] = 33.5493f;
	v1[3][1] = 92.3655f;
	v1[4][0] = 62.7299f;
	v1[4][1] = 92.2041f;

	src = Mat(5, 2, CV_32FC1, v1);
	memcpy(src.data, v1, 2 * 5 * sizeof(float));
	return true;
}

LiveFaceReco::DetectionInfo LiveFaceReco::DetectionReceiver::nextFrame()
{
	return videoDetection->MTCNNDetection();
}

LiveFaceReco::DetectionReceiver::DetectionReceiver(LiveFaceReco::VideoDetection *videoDetection)
{
	this->videoDetection = videoDetection;
}

LiveFaceReco::PersonalInfo::PersonalInfo()
{

}

LiveFaceReco::PersonalInfo::PersonalInfo(int id, string fileName, Mat face)
{
	this->id = id;
	this->fileName = fileName;
	this->face = face;
}
