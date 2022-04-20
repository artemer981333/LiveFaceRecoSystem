#include "lfrmanager.h"
#include <QGraphicsPixmapItem>

#include "opencv2/opencv.hpp"
#include "mainwindow.h"
#include "videodetectionhandler.h"

using namespace std;


LFRManager::LFRManager(QObject *parent) : QObject(parent)
{
	m_LiveFaceReco = new LiveFaceReco();
	m_LiveFaceReco->loadTmpInfoFromFile("Faces.tmp");
}

LFRManager::~LFRManager()
{
	m_LiveFaceReco->saveTmpInfoToFile("Faces.tmp");
	for (int i = 0; i < streams.size(); ++i)
	{
		deleteVideoSource(i);
	}
	delete m_LiveFaceReco;
}

int LFRManager::addVideoSource(int cameraIndex)
{
	int videoIndex = m_LiveFaceReco->addVideoSource(cameraIndex);
	if (videoIndex == -1)
		return -1;
	VideoStream stream;
	stream.receiver = m_LiveFaceReco->createDetectionReciever(videoIndex);
	stream.videoThread = new QThread();
	stream.handler = new VideoDetectionHandler();
	stream.handler->connectReciever(stream.receiver, videoIndex);
	stream.handler->moveToThread(stream.videoThread);
	connect(stream.videoThread, &QThread::started, stream.handler, &VideoDetectionHandler::run);
	connect(stream.handler, &VideoDetectionHandler::frameUpdated, (const MainWindow*)this->parent(), &MainWindow::updatePixmap);
	connect(stream.handler, &VideoDetectionHandler::personDetected, (const MainWindow*)this->parent(), &MainWindow::updateDetectedPerson);

	stream.handler->setRunning(true);
	stream.videoThread->start();
	streams.append(stream);
	return streams.size() - 1;
}

int LFRManager::addVideoSource(const QString &path)
{
	int videoIndex = m_LiveFaceReco->addVideoSource(path.toStdString());
	if (videoIndex == -1)
		return -1;
	VideoStream stream;
	stream.receiver = m_LiveFaceReco->createDetectionReciever(videoIndex);
	stream.videoThread = new QThread();
	stream.handler = new VideoDetectionHandler();
	stream.handler->connectReciever(stream.receiver, videoIndex);
	stream.handler->moveToThread(stream.videoThread);
	connect(stream.videoThread, &QThread::started, stream.handler, &VideoDetectionHandler::run);
	connect(stream.handler, &VideoDetectionHandler::frameUpdated, (const MainWindow*)this->parent(), &MainWindow::updatePixmap);
	connect(stream.handler, &VideoDetectionHandler::personDetected, (const MainWindow*)this->parent(), &MainWindow::updateDetectedPerson);

	stream.handler->setRunning(true);
	stream.videoThread->start();
	streams.append(stream);
	return streams.size() - 1;
}

void LFRManager::deleteVideoSource(int index)
{
	if (streams[index].handler == nullptr)
		return;
	streams[index].handler->setRunning(false);
	streams[index].videoThread->quit();
	streams[index].videoThread->wait();
	m_LiveFaceReco->deleteVideoSource(streams[index].handler->getVideoIndex());
	delete streams[index].videoThread;
	delete streams[index].handler;
	streams[index].handler = nullptr;
}

VideoDetectionHandler *LFRManager::handlerByIndex(int index)
{
	return streams[index].handler;
}

void LFRManager::updatePersonalCards(const QStringList &filenames, const QList<int> &brightnesCorrs, const QList<int> &contrastCorrs)
{
	vector<string> vect1;
	for (int i = 0; i < filenames.size(); ++i)
		vect1.push_back(filenames.at(i).toStdString());
	vector<int> vect2 = brightnesCorrs.toVector().toStdVector();
	vector<int> vect3 = contrastCorrs.toVector().toStdVector();
//	for (int i = 0; i < filenames.size(); ++i)
//		vect.push_back(filenames[i].toStdString());
	m_LiveFaceReco->updatePersonalInfos(vect1, vect2, vect3);
	m_LiveFaceReco->saveTmpInfoToFile("Faces.tmp");
}

QString LFRManager::fileNameByID(int id)
{
	return QString(m_LiveFaceReco->fileNameByID(id).c_str());
}

void LFRManager::askForLFR()
{
	emit sendLFR(m_LiveFaceReco);
}
