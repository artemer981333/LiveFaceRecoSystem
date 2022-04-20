#ifndef VIDEODETECTIONHANDLER_H
#define VIDEODETECTIONHANDLER_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "livefacereco.hpp"
#include "opencv2/opencv.hpp"
#include <mutex>

struct DrawInfo
{
	DrawInfo();
	DrawInfo(const DrawInfo &other);
	~DrawInfo();
	cv::Point ld, ru, eye1, eye2, nose, mouse1, mouse2;
	double fps, angle;
};

//класс обработчика видеопотока
class VideoDetectionHandler : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

	bool m_running;


	LiveFaceReco::DetectionReceiver *reciever;
	int videoIndex;

public:

	static std::mutex mut;

	struct VideoDisplay
	{
		VideoDisplay(QWidget *parent = 0);
		~VideoDisplay();
		QGraphicsView *widget;
		QGraphicsScene *scene;
		QGraphicsPixmapItem *pixmap;
	};

	explicit VideoDetectionHandler(QObject *parent = nullptr);

	void connectReciever(LiveFaceReco::DetectionReceiver *reciever, int index);
	void connectDisplay(VideoDisplay *display);

	int getVideoIndex();

	bool running() const;

signals:

	void finished();
	void runningChanged(bool running);
	//сигналы об обновлении кадра и идентификации человека
	void frameUpdated(VideoDisplay *display, cv::Mat pixmap, DrawInfo info);
	void personDetected(bool detected, int id, double confidence, double similarity, VideoDetectionHandler::VideoDisplay *videoDisplay);

public slots:

	void setCameraInputResolution(int x, int y);
	void setCameraOutputResolution(int x, int y);
	void setBrightnessCorrection(int corr);
	void setContrastCorrection(int corr);


	void run();
	void setRunning(bool running);

private:

	VideoDisplay *display;

};


#endif // VIDEODETECTIONHANDLER_H
