//
// Created by markson zhang
//
//
// Edited by Xinghao Chen 2020/7/27
//
#include <iostream>
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
inline float CosineDistance(const cv::Mat &v1, const cv::Mat &v2) {
	double dot = v1.dot(v2);
	double denom_v1 = norm(v1);
	double denom_v2 = norm(v2);
	return dot / (denom_v1 * denom_v2);
}

/**
 * Calculating the turning angle of face
 *  */
inline double count_angle(float landmark[5][2]) {
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
	initialized = true;
	working = false;

	msgHandler.start();

	source = new DetectionSource(&msgHandler);

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

cv::Mat LiveFaceReco::VideoDetection::MTCNNDetection()
{
	if (!videoSrc.isOpened())
		return cv::Mat();
	cv::String name;
	std::string hi_name;
	std::string liveface;
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
			cv::circle(result_cnn, Point(faceInfo[i].ppoint[j]*ratio_x, faceInfo[i].ppoint[j + 5]*ratio_y), 3, scalar, FILLED, LINE_AA);
		}
	};

	auto putName = [&](cv::String imgName)
	{
		//put name
		name = imgName.substr(imgName.rfind('/') + 1, imgName.length() - 4);
		name = name.substr(0, imgName.length() - 4);
		hi_name = "Name: "+ name;
		drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
		return name;
	};



	count++;
	clock_t t = clock();

	videoSrc >> frame;
	cv::flip(frame, frame, 1);
	resize(frame, result_cnn, frame_size, INTER_LINEAR);

	if (count % 2 == 0)
	{
		mutDetect.lock();
		faceInfo = detect_mtcnn(frame);
		mutDetect.unlock();

		largest_number = findLargestFace(faceInfo);
	}

	//cout << this_thread::get_id() << ": " << faceInfo.size() << endl;

	int start_la, end_la;
	if (faceInfo.size() == 0)
	{
		start_la= 0;
		end_la= 0;
	}
	else if(largest_face_only)
	{
		start_la= largest_number;
		end_la= largest_number+1;
	}
	else
	{
		start_la=0;
		end_la=faceInfo.size();
	}

	//the faces to operate
	for (int i = start_la; i < end_la; ++i)
	{
		float x_ = faceInfo[i].x1, y_ = faceInfo[i].y1, x2_ = faceInfo[i].x2, y2_ = faceInfo[i].y2;
		int x = x_, y = y_, x2 = x2_, y2 = y2_;
		LiveFaceBox live_box = {x_, y_, x2_, y2_};

		//highlight the significant landmarks on face
		highlightLandmarks(i);
		cv::rectangle(result_cnn, Point(x*ratio_x, y*ratio_y), Point(x2*ratio_x,y2*ratio_y), cv::Scalar(0, 0, 255), 2);
		// Perspective Transformation
		float v2[5][2] =
		{{faceInfo[i].ppoint[0], faceInfo[i].ppoint[5]},
		 {faceInfo[i].ppoint[1], faceInfo[i].ppoint[6]},
		 {faceInfo[i].ppoint[2], faceInfo[i].ppoint[7]},
		 {faceInfo[i].ppoint[3], faceInfo[i].ppoint[8]},
		 {faceInfo[i].ppoint[4], faceInfo[i].ppoint[9]},
		};


		// compute the turning angle
		angle = count_angle(v2);

		//cout << this_thread::get_id() << ": " << angle << endl;
		//cout << this_thread::get_id() << "faces" << endl;


		/****************************jump*****************************************************/
		if (count % jump == 0)
		{
			cv::Mat dst(5, 2, CV_32FC1, v2);
			memcpy(dst.data, v2, 2 * 5 * sizeof(float));

			cv::Mat m = FacePreprocess::similarTransform(dst, m_source->src);
			cv::Mat aligned = frame.clone();
			cv::warpPerspective(frame, aligned, m, cv::Size(96, 112), INTER_LINEAR);
			resize(aligned, aligned, Size(112, 112), 0, 0, INTER_LINEAR);


			//set to 1 if you want to record your image
			if (record_face)
			{
				imshow("aligned face", aligned);
				waitKey(2000);
				imwrite(project_path+ format("/img/%d.jpg", count), aligned);
			}
			//features of camera image
			//mutArcface.lock();
			cv::Mat fc2 = m_source->reco.getFeature(aligned);
			//mutArcface.unlock();

			// normalize
			fc2 = Zscore(fc2);

			//the similarity score
			vector<double> scores;
			for (unsigned int compare_ = 0; compare_ < m_source->image_number; ++ compare_)
				scores.push_back(CosineDistance(m_source->faces[compare_], fc2));
			int maxPosition = max_element(scores.begin(), scores.end()) - scores.begin();
			similarity = scores[maxPosition];
			scores.clear();
			//cout << this_thread::get_id() << ": " << similarity << endl;

			if (similarity >= face_thre && y2-y >= distance_threshold)
			{
				name = putName(m_source->image_names[maxPosition]);
				m_msgHandler->addMessage(name);
				//determin whethe it is a fake face
				//mutLive.lock();
				confidence = m_source->live.Detect(frame, live_box);

				//mutLive.unlock();

				drawText(result_cnn, to_string(confidence), Point(x*ratio_x, y2*ratio_y+20), cv::Scalar(0,255,255));
				liveface = (confidence <= true_thre) ? ("Fake face!!") : ("True face");
				drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 0, 255));
				m_msgHandler->addMessage(liveface);
				stranger = false;
				close_enough = true;
			}
			else if(similarity >= face_thre && y2-y < distance_threshold)
			{
				putName(m_source->image_names[maxPosition]);
				//Ask be closer to avoid mis-reco
				drawText(result_cnn, "Closer please", Point(5, 60), cv::Scalar(0, 255, 255));
				m_msgHandler->addMessage("Ближе пожалуйста!");
				stranger = false;
				close_enough = false;
			}
			else
			{
				drawText(result_cnn, "Stranger", Point(5, 60), cv::Scalar(255, 0, 0));
				m_msgHandler->addMessage("Не уверен...");
				stranger = true;
			}
		}
		else
		{
			if(stranger)
			{
				drawText(result_cnn, "Stranger", Point(5, 60), cv::Scalar(255, 0, 0));
			}
			else if(close_enough)
			{
				drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
				drawText(result_cnn, to_string(confidence), Point(x*ratio_x, y2*ratio_y+20), cv::Scalar(0,255,255));
				if (liveface.length() == 9)
					drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 255, 0));
				else
					drawText(result_cnn, liveface, Point(5, 80), cv::Scalar(0, 0, 255));
			}
			else
			{
				drawText(result_cnn, hi_name, Point(5, 60), cv::Scalar(0, 255, 255));
				drawText(result_cnn, "Closer please", Point(5, 80), cv::Scalar(0, 255, 255));
			}

			if (count == 10 * jump - 1)
				count = 0;
		}
		drawText(result_cnn, to_string(similarity), Point(x*ratio_x, y2*ratio_y), cv::Scalar(0, 255, 0));

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

	result_cnn = draw_conclucion("FPS: ", fps_mean, result_cnn, 20);//20
	result_cnn = draw_conclucion("Angle: ", angle, result_cnn, 40);//65


	return result_cnn;

}

void LiveFaceReco::connectMessages(std::queue<string> *queue, mutex *mutex)
{
	msgHandler.connectQueue(queue, mutex);
}

bool LiveFaceReco::isInitialized() const
{
	return initialized;
}

bool LiveFaceReco::isWorking() const
{
	return working;
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

void LiveFaceReco::start()
{
	if (initialized)
		working = true;
	else
		working = false;
}

void LiveFaceReco::stop()
{
	working = false;
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

	readImages();
	convertImages();

	//OpenCV Version
	cout << "OpenCV Version: " << CV_MAJOR_VERSION << "."
		 << CV_MINOR_VERSION << "."
		 << CV_SUBMINOR_VERSION << endl;

	configureLiveDetection();
	initSourceMatrix();
}

bool LiveFaceReco::DetectionSource::readImages()
{
	// loading faces
	std::string pattern_jpg = project_path+ "/img/*.jpg";

	cv::glob(pattern_jpg, image_names);
	image_number = image_names.size();
	m_msgHandler->addMessage("loaded " + to_string(image_number) + " pictures...");
	//cout << "loaded " << image_number << " pictures..." << endl;
	if (image_number == 0)
		return false;
	return true;
}

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

bool LiveFaceReco::DetectionSource::convertImages()
{
	//convert to vector and store into fc, whcih is benefical to furthur operation
	Mat  face;
	char str[7];
	for (size_t i = 0; i < image_number; ++i)
	{
		face = cv::imread(image_names[i]);
		faces.push_back(reco.getFeature(face));
		faces[i] = Zscore(faces[i]);
		sprintf(str, "%4.2lf", i*100.0 / (double)(image_number - 1));
		m_msgHandler->addMessage("loading[" + string(str) + "%]");
		//printf("\rloading[%.2lf%%]",  i*100.0 / (image_number - 1));
	}
	//cout << endl;
	//float factor = 0.709f;
	//float threshold[3] = {0.7f, 0.6f, 0.6f};
	m_msgHandler->addMessage("loading succeed!" + to_string(image_number) + " pictures in total");
	//cout <<"loading succeed! "<<image_number<<" pictures in total"<<endl;
	return true;
}

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

Mat LiveFaceReco::DetectionReceiver::nextFrame()
{
	return videoDetection->MTCNNDetection();
}

LiveFaceReco::DetectionReceiver::DetectionReceiver(LiveFaceReco::VideoDetection *videoDetection)
{
	this->videoDetection = videoDetection;
}
