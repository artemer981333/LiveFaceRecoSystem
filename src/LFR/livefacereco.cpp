#include <iostream>
#include <queue>
#include "include/FacePreprocess.h"
#include <numeric>
#include <math.h>
#include "livefacereco.hpp"
#include <time.h>
#include "arcface.h"
#include "mtcnn_new.h"
#include "live.h"
#include <unistd.h>


#define PI 3.14159265
using namespace std;
using namespace cv;

cv::Mat Zscore(const cv::Mat &fc)
{
	Mat mean, std;
	meanStdDev(fc, mean, std);
	Mat fc_norm = (fc - mean) / std;
	return fc_norm;
}

float CosineDistance(const cv::Mat &v1, const cv::Mat &v2)
{
	double dot = v1.dot(v2);
	double denom_v1 = norm(v1);
	double denom_v2 = norm(v2);
	return dot / (denom_v1 * denom_v2);
}

double count_angle(float landmark[5][2])
{
	double a = landmark[2][1] - (landmark[0][1] + landmark[1][1]) / 2;
	double b = landmark[2][0] - (landmark[0][0] + landmark[1][0]) / 2;
	double angle = atan(abs(b) / a) * 180 / PI;
	return angle;
}

void brightnessCorrection(const cv::Mat bgr_image, int brtCorr, int contrCorr)
{
	cv::Mat dst;
	bgr_image.convertTo(dst, -1, contrCorr / 100.0, brtCorr); //decrease the brightness
	dst.copyTo(bgr_image);
}

LiveFaceReco::LiveFaceReco()
{
	msgHandler.start();

	source = new DetectionSource(&msgHandler);
	source->personalInfos = &personalInfos;
}

LiveFaceReco::~LiveFaceReco()
{
	msgHandler.stop();
	for (int i = 0; i < videoDetections.size(); i++)
		deleteVideoSource(i);
	delete source;
}

LiveFaceReco::VideoDetection::VideoDetection(LFRMsgHandler *msgHandler, LiveFaceReco::DetectionSource *source)
{
	m_msgHandler = msgHandler;
	m_source = source;

	output_size = cv::Size(320, 240);
//	output_size = cv::Size(640, 480);
//	input_size = cv::Size(640, 480);
	input_size = cv::Size(320, 240);

	flipping = false;
	brtCorr = -50;
	contrCorr = 100;
	count = 0;
	prevMaxPos = -1;
}

LiveFaceReco::VideoDetection::~VideoDetection()
{
	videoSrc.release();
}

bool LiveFaceReco::VideoDetection::connectCamera(int cameraIndex)
{
	return initCamera(cameraIndex);
}

bool LiveFaceReco::VideoDetection::connectCamera(const string &path)
{
	return initCamera(path);
}

void LiveFaceReco::VideoDetection::connectMessages(LFRMsgHandler *msgHandler)
{
	m_msgHandler = msgHandler;
}

LiveFaceReco::FrameInfo LiveFaceReco::VideoDetection::MTCNNDetection()
{
	LiveFaceReco::FrameInfo ret;
	ret.isDetected = false;
	ret.angle = 0;
	if (!videoSrc.isOpened())
		return LiveFaceReco::FrameInfo();

	count++;

	//получение кадра
	mut.lock();
	if (videoSrc.isOpened())
		videoSrc >> ret.frame;
	mut.unlock();

	if (ret.frame.empty())
	{
		videoSrc.release();
		ret.frame = cv::Mat(output_size, CV_32FC1);
		ret.frame.setTo(cv::Scalar(0, 0, 0));
		return ret;
	}

	if (flipping)
		cv::flip(ret.frame, ret.frame, 1);
	brightnessCorrection(ret.frame, brtCorr, contrCorr);

	//распознавание лиц происходит через кадр
	if (count == 3)
	{
		faceInfos = detect_mtcnn(ret.frame);

		largest_number = findLargestFace(faceInfos);
		count = 0;
	}

	if (!faceInfos.empty())
	{
		//определение координат точек для идентификации и рисования
		Bbox &faceInfo = faceInfos[largest_number];
		float x_ = faceInfo.x1, y_ = faceInfo.y1, x2_ = faceInfo.x2, y2_ = faceInfo.y2;
		int x = x_, y = y_, x2 = x2_, y2 = y2_;

		ret.ld = Point(x, y);
		ret.ru = Point(x2, y2);
		ret.eye1 = Point(faceInfo.ppoint[0], faceInfo.ppoint[5]);
		ret.eye2 = Point(faceInfo.ppoint[1], faceInfo.ppoint[6]);
		ret.nose = Point(faceInfo.ppoint[2], faceInfo.ppoint[7]);
		ret.mouth1 = Point(faceInfo.ppoint[3], faceInfo.ppoint[8]);
		ret.mouth2 = Point(faceInfo.ppoint[4], faceInfo.ppoint[9]);
		float v2[5][2] =
		{{faceInfo.ppoint[0], faceInfo.ppoint[5]},
		 {faceInfo.ppoint[1], faceInfo.ppoint[6]},
		 {faceInfo.ppoint[2], faceInfo.ppoint[7]},
		 {faceInfo.ppoint[3], faceInfo.ppoint[8]},
		 {faceInfo.ppoint[4], faceInfo.ppoint[9]},
		};

		ret.isDetected = true;
		ret.faceInfo = faceInfo;

		//вычисление угла поворота лица
		ret.angle = count_angle(v2);
	}

	return ret;
}

LiveFaceReco::DetectionInfo LiveFaceReco::VideoDetection::IdentPerson(cv::Mat frame, Bbox faceInfo)
{
	LiveFaceReco::DetectionInfo ret;
	ret.detected = false;
	ret.confidence = 0;
	ret.similarity = 0;
	ret.id = -1;

	float x_ = faceInfo.x1, y_ = faceInfo.y1, x2_ = faceInfo.x2, y2_ = faceInfo.y2;
	int x = x_, y = y_, x2 = x2_, y2 = y2_;
	LiveFaceBox live_box = {x_, y_, x2_, y2_};

	float v2[5][2] =
	{{faceInfo.ppoint[0], faceInfo.ppoint[5]},
	 {faceInfo.ppoint[1], faceInfo.ppoint[6]},
	 {faceInfo.ppoint[2], faceInfo.ppoint[7]},
	 {faceInfo.ppoint[3], faceInfo.ppoint[8]},
	 {faceInfo.ppoint[4], faceInfo.ppoint[9]},
	};

	cv::Mat dst(5, 2, CV_32FC1, v2);
	memcpy(dst.data, v2, 2 * 5 * sizeof(float));

	cv::Mat m = FacePreprocess::similarTransform(dst, m_source->src);
	cv::warpPerspective(frame, frame, m, cv::Size(96, 112), INTER_LINEAR);
	resize(frame, frame, Size(112, 112), 0, 0, INTER_LINEAR);

	//получение данных о лице
	cv::Mat fc2 = Zscore(m_source->reco->getFeature(frame));

	vector<double> scores;
	for (unsigned int i = 0; i < m_source->personalInfos->size(); ++i)
		scores.push_back(CosineDistance(m_source->personalInfos->at(i).face, fc2));
	int maxPosition = max_element(scores.begin(), scores.end()) - scores.begin();
	if (maxPosition == prevMaxPos)
	{
		ret.id = m_source->personalInfos->at(maxPosition).id;
		ret.similarity = scores[maxPosition];

		if (ret.similarity >= 0.4/* && y2 - y >= distance_threshold*/)
			ret.confidence = m_source->live->Detect(frame, live_box);
		ret.detected = true;
	}
	prevMaxPos = maxPosition;
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

int LiveFaceReco::addVideoSource(string path)
{
	VideoDetection *vd = new VideoDetection(&msgHandler, source);
	if (vd->connectCamera(path) == false)
	{
		delete vd;
		return -1;
	}
	videoDetections.push_back(vd);
	videoDetections.back()->setFlipping(false);
	return videoDetections.size() - 1;
}

void LiveFaceReco::deleteVideoSource(int index)
{
	if (videoDetections.size() <= index)
		return;
	if (videoDetections[index] == nullptr)
		return;
	delete videoDetections[index];
	videoDetections[index] = nullptr;
}

void LiveFaceReco::loadTmpInfoFromFile(const string &fileName)
{
	msgHandler.addMessage("Start loading TMP");
	ifstream file(fileName, ios::binary | ios::ate);
	if (!file.is_open())
	{
		msgHandler.addMessage("Loading failed (can't open file)");
		string path;
		path.resize(1000);
		readlink("/proc/self/exe", &path[0], path.size());
		msgHandler.addMessage(path);
		return;
	}
	personalInfos.clear();
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
		ptr += (info.fileName.size() + 1) * sizeof(char);
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
		fileSize += personalInfos[i].fileName.size() + 1;
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
		memcpy(ptr, personalInfos[i].fileName.c_str(), personalInfos[i].fileName.size() + 1);
		ptr += (personalInfos[i].fileName.size() + 1) * sizeof(char);
	}
	file.write(bytes, fileSize);
	file.close();
	msgHandler.addMessage("TMP saved: " + to_string(personalInfos.size()) + ", size = " + to_string(fileSize));
	delete[] bytes;
}

void LiveFaceReco::updatePersonalInfos(const vector<string> &filenames, const vector<int> &brtCorrs, const vector<int> &contrCorrs)
{
	personalInfos.clear();
	PersonalInfo info;
	cv::Mat img;
	for (int i = 0; i < filenames.size(); ++i)
	{
		img = cv::imread("./img/" + filenames[i]);
		brightnessCorrection(img, brtCorrs[i], contrCorrs[i]);
		info.face = Zscore(source->reco->getFeature(img));
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
	return new DetectionReceiver(videoDetections[videoIndex]);
}

void LiveFaceReco::VideoDetection::setFlipping(bool flipping)
{
	this->flipping = flipping;
}

void LiveFaceReco::VideoDetection::setFrameSize(int x, int y)
{
	output_size = cv::Size(x, y);
}

void LiveFaceReco::VideoDetection::setInputSize(int x, int y)
{
	input_size = cv::Size(x, y);
	mut.lock();
	videoSrc.set(CAP_PROP_FRAME_WIDTH, input_size.width);
	videoSrc.set(CAP_PROP_FRAME_HEIGHT, input_size.height);
	mut.unlock();
}

void LiveFaceReco::VideoDetection::setBrightnessCorrection(int corr)
{
	brtCorr = corr;
}

void LiveFaceReco::VideoDetection::setContrastCorrection(int corr)
{
	contrCorr = corr;
}

std::vector<Bbox> LiveFaceReco::VideoDetection::detect_mtcnn(const Mat &cv_img)
{
	ncnn::Mat ncnn_img = ncnn::Mat::from_pixels(cv_img.data, ncnn::Mat::PIXEL_BGR2RGB, cv_img.cols, cv_img.rows);
	std::vector<Bbox> finalBbox;
	mm.detect(ncnn_img, finalBbox);
	return finalBbox;
}

bool LiveFaceReco::VideoDetection::initCamera(int cameraIndex)
{
	if (videoSrc.isOpened())
		videoSrc.release();
	videoSrc.open(cameraIndex);
	videoSrc.set(CAP_PROP_FRAME_WIDTH, input_size.width);
	videoSrc.set(CAP_PROP_FRAME_HEIGHT, input_size.height);
	videoSrc.set(CAP_PROP_FPS, 90);
	return videoSrc.isOpened();
}

bool LiveFaceReco::VideoDetection::initCamera(const string &path)
{
	if (videoSrc.isOpened())
		videoSrc.release();
	videoSrc.open(path);
	videoSrc.set(CAP_PROP_FRAME_WIDTH, input_size.width);
	videoSrc.set(CAP_PROP_FRAME_HEIGHT, input_size.height);
	videoSrc.set(CAP_PROP_FPS, 90);
	return videoSrc.isOpened();
}

int LiveFaceReco::VideoDetection::findLargestFace(const vector<Bbox> &faceInfo)
{
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

LiveFaceReco::DetectionSource::DetectionSource(LFRMsgHandler *msgHandler)
{
	live = new Live;
	reco = new Arcface;
	m_msgHandler = msgHandler;

	cout << "OpenCV Version: " << CV_MAJOR_VERSION << "."
		 << CV_MINOR_VERSION << "."
		 << CV_SUBMINOR_VERSION << endl;

	configureLiveDetection();
	initSourceMatrix();
}

LiveFaceReco::DetectionSource::~DetectionSource()
{
	delete live;
	delete reco;
}

bool LiveFaceReco::DetectionSource::configureLiveDetection()
{
	ModelConfig config1 = {2.7f, 0.0f, 0.0f, 80, 80, "model_1", false};
	ModelConfig config2 = {4.0f, 0.0f, 0.0f, 80, 80, "model_2", false};
	vector<ModelConfig> configs;
	configs.emplace_back(config1);
	configs.emplace_back(config2);
	live->LoadModel(configs);
	return true;
}

bool LiveFaceReco::DetectionSource::initSourceMatrix()
{
	//магия чисел
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

LiveFaceReco::FrameInfo LiveFaceReco::DetectionReceiver::nextFrame()
{
	return videoDetection->MTCNNDetection();
}

LiveFaceReco::DetectionInfo LiveFaceReco::DetectionReceiver::identPerson(Mat frame, Bbox faceInfo)
{
	return videoDetection->IdentPerson(frame, faceInfo);
}

void LiveFaceReco::DetectionReceiver::setFrameSize(int x, int y)
{
	videoDetection->setFrameSize(x, y);
}

void LiveFaceReco::DetectionReceiver::setInputSize(int x, int y)
{
	videoDetection->setInputSize(x, y);
}

void LiveFaceReco::DetectionReceiver::setBrightnessCorrection(int corr)
{
	videoDetection->setBrightnessCorrection(corr);
}

void LiveFaceReco::DetectionReceiver::setContrastCorrection(int corr)
{
	videoDetection->setContrastCorrection(corr);
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
