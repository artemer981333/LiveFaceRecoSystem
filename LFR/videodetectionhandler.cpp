#include "videodetectionhandler.h"
#include <QThread>
#include <QDebug>

VideoDetectionHandler::VideoDetectionHandler(QObject *parent) : QObject(parent)
{

}

void VideoDetectionHandler::connectReciever(LiveFaceReco::DetectionReceiver *reciever)
{
	this->reciever = reciever;
}

void VideoDetectionHandler::connectDisplay(VideoDetectionHandler::VideoDisplay *display)
{
	this->display = display;
}

bool VideoDetectionHandler::running() const
{
	return m_running;
}

void VideoDetectionHandler::run()
{
	LiveFaceReco::DetectionInfo info;
	cv::Mat &frame = info.frame;
	clock_t t = clock();
	while (m_running)
	{
		info = reciever->nextFrame();
		t = clock();
		if (!frame.empty())
		{
			emit frameUpdated(
						display,
						QPixmap::fromImage(
							QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888).rgbSwapped()));
			emit personDetected(info.id, info.confidence, info.similarity);
		}
	}
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
