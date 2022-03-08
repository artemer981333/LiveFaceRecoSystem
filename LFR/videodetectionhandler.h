#ifndef VIDEODETECTIONHANDLER_H
#define VIDEODETECTIONHANDLER_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "livefacereco.hpp"

class VideoDetectionHandler : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

	bool m_running;


	LiveFaceReco::DetectionReceiver *reciever;

public:

	struct VideoDisplay
	{
		VideoDisplay(QWidget *parent = 0);
		~VideoDisplay();
		QGraphicsView *widget;
		QGraphicsScene *scene;
		QGraphicsPixmapItem *pixmap;
	};

	explicit VideoDetectionHandler(QObject *parent = nullptr);

	void connectReciever(LiveFaceReco::DetectionReceiver *reciever);
	void connectDisplay(VideoDisplay *display);

	bool running() const;

signals:

	void finished();
	void runningChanged(bool running);
	void frameUpdated(VideoDisplay *display, QPixmap pixmap);
	void personDetected(int id, double confidence, double similarity);

public slots:
	void run();
	void setRunning(bool running);

private:

	VideoDisplay *display;

};

#endif // VIDEODETECTIONHANDLER_H
