#ifndef LIVEFACERECO_H
#define LIVEFACERECO_H
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <queue>
#include "lfrmsghandler.h"
#include "mtcnn_new.h"


const int distance_threshold = 90;	//дистанция отсечения
//const float face_thre = 0.40;
//const float true_thre = 0.89;
const int jump = 10;	//период (в кадрах), через который происходит идентификация

void brightnessCorrection(const cv::Mat bgr_image, int brtCorr = -30, int contrCorr = 1);

class Live;
class Arcface;
class Bbox;

//главный класс LFR
class LiveFaceReco
{
public:

	LiveFaceReco();
	~LiveFaceReco();

	void connectMessages(std::queue<std::string> *queue, std::mutex *mutex);

	//работа с видеопотоками
	int addVideoSource(int cameraIndex);
	int addVideoSource(std::string path);
	void deleteVideoSource(int index);

	//работа с темп файлом
	void loadTmpInfoFromFile(const std::string &fileName);
	void saveTmpInfoToFile(const std::string &fileName);

	void updatePersonalInfos(const std::vector<std::string> &filenames, const std::vector<int> &brtCorrs, const std::vector<int> &contrCorrs);

	std::string fileNameByID(int id);

	struct PersonalInfo
	{
		PersonalInfo();
		PersonalInfo(int id, std::string fileName, cv::Mat face);
		int id;
		std::string fileName;
		cv::Mat face;
	};

	struct FrameInfo
	{
		cv::Mat frame;
		cv::Point ld, ru, eye1, eye2, nose, mouth1, mouth2;
		double angle;
		Bbox faceInfo;
		bool isDetected;
	};

	struct DetectionInfo
	{
		double confidence, similarity;
		int id;
		bool detected;
	};

protected:

	//класс, содержащий распознаватель
	class DetectionSource
	{
	public:
		DetectionSource(LFRMsgHandler *msgHandler = nullptr);
		~DetectionSource();

		Live *live;
		Arcface *reco;
		cv::Mat src;
		float v1[5][2];

		std::vector<PersonalInfo> *personalInfos;

	protected:
		bool configureLiveDetection();
		bool initSourceMatrix();

		LFRMsgHandler *m_msgHandler;
	};

	//класс, отвечающий за прием кадров, распознавание и идентификацию
	class VideoDetection
	{
	public:
		VideoDetection(LFRMsgHandler *msgHandler, DetectionSource *m_source);
		~VideoDetection();

		bool connectCamera(int cameraIndex = 0);
		bool connectCamera(const std::string &path);

		void connectMessages(LFRMsgHandler *msgHandler);

		//главный метод, возвращает кадр и информацию об идентифицированном человеке
		FrameInfo MTCNNDetection();
		DetectionInfo IdentPerson(cv::Mat frame, Bbox faceInfo);

		void setFlipping(bool flipping);
		void setFrameSize(int x, int y);
		void setInputSize(int x, int y);
		void setBrightnessCorrection(int corr);
		void setContrastCorrection(int corr);

	private:
		std::vector<Bbox> detect_mtcnn(const cv::Mat &cv_img);


		int findLargestFace(const std::vector<Bbox> &faceInfos);

		bool initCamera(int cameraIndex);
		bool initCamera(const std::string &path);

		bool flipping;
		int brtCorr, contrCorr;

		int count;
		std::vector<Bbox> faceInfos;
		int largest_number;
		int prevMaxPos;

		DetectionSource *m_source;
		cv::VideoCapture videoSrc;
		cv::Size output_size;
		cv::Size input_size;

		std::mutex mut;

		LFRMsgHandler *m_msgHandler;

		mtcnn mm;

	};

	std::vector<VideoDetection *> videoDetections;
	DetectionSource *source;
	std::vector<PersonalInfo> personalInfos;
	LFRMsgHandler msgHandler;
	//Arcface *reco;

public:
	//класс, объект которого является приемником информации из VideoDetection
	class DetectionReceiver
	{
	public:
		FrameInfo nextFrame();
		DetectionInfo identPerson(cv::Mat frame, Bbox faceInfo);

		void setFrameSize(int x, int y);
		void setInputSize(int x, int y);
		void setBrightnessCorrection(int corr);
		void setContrastCorrection(int corr);

		friend class LiveFaceReco;

	private:
		DetectionReceiver(VideoDetection *videoDetection);

		VideoDetection *videoDetection;
	};

	//метод создания приемника, связанного с конкретным видеопотоком по id
	DetectionReceiver *createDetectionReciever(int videoIndex);
};

#endif // LIVEFACERECO_H



