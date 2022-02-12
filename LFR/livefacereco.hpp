#ifndef LIVEFACERECO_H
#define LIVEFACERECO_H
//
// Created by Xinghao Chen 2020/7/27
//
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <queue>
#include "arcface.h"
#include "mtcnn_new.h"
#include "live.h"
#include "lfrmsghandler.h"


// Adjustable Parameters
const bool largest_face_only=true;
const bool record_face=false;
const int distance_threshold = 10;
const float face_thre=0.40;
const float true_thre=0.89;
const int jump=10;
const int input_width = 320;
const int input_height = 240;
const int output_width = 640;
const int output_height = 480;
const string project_path="/home/koss/LiveFaceReco_RaspberryPi";
//end

const cv::Size frame_size = cv::Size(output_width,output_height);
const float ratio_x = (float)output_width/ input_width;
const float ratio_y = (float)output_height/ input_height;


class LiveFaceReco
{
public:


	LiveFaceReco();
	~LiveFaceReco();

	void connectMessages(std::queue<std::string> *queue, std::mutex *mutex);

	bool isInitialized() const;
	bool isWorking() const;

	int addVideoSource(int cameraIndex);
	int addVideoSource(std::string path);
//	{
//		VideoDetection *vd = new VideoDetection(m_msgHandler, source, path);
//		videoDetections.push_back(vd);
//		return videoDetections.size() - 1;
//	}


	void start();
	void stop();

protected:

	class DetectionSource
	{
	public:
		DetectionSource(LFRMsgHandler *msgHandler = nullptr);

		Live live;
		Arcface reco;
		vector<cv::Mat> faces;
		cv::Mat src;
		float v1[5][2];

		std::vector<cv::String> image_names;
		int image_number;

	protected:

		bool readImages();
		bool configureLiveDetection();
		bool convertImages();
		bool initSourceMatrix();

		LFRMsgHandler *m_msgHandler;
	};

	class VideoDetection
	{
	public:
		VideoDetection(LFRMsgHandler *msgHandler, DetectionSource *m_source);
		~VideoDetection();

		bool connectCamera(int cameraIndex = 0);

		void connectMessages(LFRMsgHandler *msgHandler);

		cv::Mat MTCNNDetection();

		void setDrawing(bool drawing);

		bool isRecieverConnected() const;
		void setRecieverConnected(bool connected);

	private:

		int findLargestFace(const vector<Bbox> &faceInfo);

		void drawText(const cv::Mat &img, const string &text, const cv::Point &point, const cv::Scalar &color);

		bool initCamera(int cameraIndex);

		bool drawingText;

		int count;
		std::queue<float> fps;
		double sumFPS;
		vector<Bbox> faceInfo;
		int largest_number;

		double similarity;
		float confidence;

		DetectionSource *m_source;
		cv::VideoCapture videoSrc;

		LFRMsgHandler *m_msgHandler;

		bool recieverConnected;

	};

	vector<VideoDetection *> videoDetections;
	DetectionSource *source;
	LFRMsgHandler msgHandler;

	bool initialized;
	bool working;

public:

	class DetectionReceiver
	{
	public:

		cv::Mat nextFrame();

		friend class LiveFaceReco;

	private:

		DetectionReceiver(VideoDetection *videoDetection);

		VideoDetection *videoDetection;

	};

	DetectionReceiver *createDetectionReciever(int videoIndex);
};

#endif // LIVEFACERECO_H



