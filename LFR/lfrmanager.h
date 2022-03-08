#ifndef LFRHANDLER_H
#define LFRHANDLER_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include <vector>
#include "livefacereco.hpp"
#include "messagehandler.h"

class VideoDetectionHandler;

class LFRManager : public QObject
{
	Q_OBJECT

	LiveFaceReco *m_LiveFaceReco;

	QList<QThread *> videoThreads;
	QList<VideoDetectionHandler *> handlers;
	QList<LiveFaceReco::DetectionReceiver *> receivers;

	QThread msgThread;

public:
	explicit LFRManager(QObject *parent = nullptr);
	~LFRManager();

	VideoDetectionHandler *addVideoSource(int cameraIndex);
	void addVideoSource(const QString &path);
	void updatePersonalCards(QStringList filenames);
	void addPersonalCard(const QString &filename);
	QString fileNameByID(int id);

signals:
	void sendLFR(LiveFaceReco *liveFaceReco);
	void videoSourceConnected();

public slots:
	void askForLFR();
};

#endif // LFRHANDLER_H
