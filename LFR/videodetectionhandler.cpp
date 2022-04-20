#include "videodetectionhandler.h"
#include <QThread>
#include <QDebug>
#include <atomic>

using namespace std;

VideoDetectionHandler::VideoDetectionHandler(QObject *parent) : QObject(parent)
{

}

void VideoDetectionHandler::connectReciever(LiveFaceReco::DetectionReceiver *reciever, int index)
{
	this->reciever = reciever;
	videoIndex = index;
}

void VideoDetectionHandler::connectDisplay(VideoDetectionHandler::VideoDisplay *display)
{
	this->display = display;
}

int VideoDetectionHandler::getVideoIndex()
{
	return videoIndex;
}

bool VideoDetectionHandler::running() const
{
	return m_running;
}

void VideoDetectionHandler::setCameraInputResolution(int x, int y)
{
	reciever->setInputSize(x, y);
}

void VideoDetectionHandler::setCameraOutputResolution(int x, int y)
{
	reciever->setFrameSize(x, y);
}

void VideoDetectionHandler::setBrightnessCorrection(int corr)
{
	reciever->setBrightnessCorrection(corr);
}

void VideoDetectionHandler::setContrastCorrection(int corr)
{
	reciever->setContrastCorrection(corr);
}

void VideoDetectionHandler::run()
{
	LiveFaceReco::FrameInfo info;
	DrawInfo drawInfo;

	std::queue<float> fps;
	double sumFPS = 0;
	int numFPS = 0;
	clock_t t = clock();
	double fps_mean;

	LiveFaceReco::DetectionInfo detInfo;
	bool identing = true;
	std::atomic<bool> done(true);
	std::thread identThread = std::thread([&]()
	{
		while(identing)
		{
			if (!done)
			{
				detInfo = reciever->identPerson(info.frame, info.faceInfo);
				done = true;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	});

	while (m_running)
	{
		if ((double)(clock() - t) >= 100000.0)
		{
			fps.push((double)numFPS * 1000000.0 / (double)(clock() - t));
			if(fps.size() < 5)
			{
				sumFPS += fps.back();
				fps_mean = sumFPS /  fps.size();
			}
			else
			{
				sumFPS += fps.back();
				sumFPS -= fps.front();
				fps_mean = sumFPS /  5;
				fps.pop();
			}
			t = clock();
			numFPS = 0;
		}
		//получение информации о кадре
		info = reciever->nextFrame();
		numFPS++;
		if (!info.frame.empty())
		{
			drawInfo.eye1 = info.eye1;
			drawInfo.eye2 = info.eye2;
			drawInfo.mouse1 = info.mouth1;
			drawInfo.mouse2 = info.mouth2;
			drawInfo.nose = info.nose;
			drawInfo.ld = info.ld;
			drawInfo.ru = info.ru;
			drawInfo.angle = info.angle;
			drawInfo.fps = fps_mean;
			//обновить кадр
			emit frameUpdated(display, info.frame, drawInfo);
		}
		if (done && info.isDetected)
		{
			//обновить информацию об идентифицированном человеке
			emit personDetected(detInfo.detected, detInfo.id, detInfo.confidence, detInfo.similarity, display);
			done = false;
		}
	}
	identing = false;
	identThread.join();
	emit finished();
}

void VideoDetectionHandler::setRunning(bool running)
{
	if (m_running == running)
		return;

	m_running = running;
	emit runningChanged(m_running);
}

VideoDetectionHandler::VideoDisplay::VideoDisplay(QWidget *parent)
{
	widget = new QGraphicsView(parent);
	scene = new QGraphicsScene(parent);
	widget->setScene(scene);
	pixmap = new QGraphicsPixmapItem;
	scene->addItem(pixmap);
	widget->fitInView(pixmap, Qt::KeepAspectRatio);
}

VideoDetectionHandler::VideoDisplay::~VideoDisplay()
{
	delete pixmap;
	delete scene;
	delete widget;
}

DrawInfo::DrawInfo()
{
}

DrawInfo::DrawInfo(const DrawInfo &other)
{
	eye1 = other.eye1;
	eye2 = other.eye2;
	mouse1 = other.mouse1;
	mouse2 = other.mouse2;
	nose = other.nose;
	ru = other.ru;
	ld = other.ld;
	fps = other.fps;
	angle = other.angle;
}

DrawInfo::~DrawInfo()
{
}
