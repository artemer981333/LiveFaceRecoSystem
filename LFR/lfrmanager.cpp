#include "lfrmanager.h"
#include <QGraphicsPixmapItem>

#include "opencv2/opencv.hpp"
#include "mainwindow.h"
#include "videodetectionhandler.h"


LFRManager::LFRManager(QObject *parent) : QObject(parent)
{
	m_LiveFaceReco = new LiveFaceReco();
	m_LiveFaceReco->loadTmpInfoFromFile("Faces.tmp");
}

LFRManager::~LFRManager()
{
	m_LiveFaceReco->saveTmpInfoToFile("Faces.tmp");
	for (int i = 0; i < videoThreads.size(); ++i)
	{
		handlers[i]->setRunning(false);
		delete receivers[i];
		delete handlers[i];
		videoThreads[i]->quit();
		videoThreads[i]->wait();
		delete videoThreads[i];
	}
	delete m_LiveFaceReco;
}

VideoDetectionHandler *LFRManager::addVideoSource(int cameraIndex)
{
	int videoIndex = m_LiveFaceReco->addVideoSource(cameraIndex);
	if (videoIndex == -1)
		return nullptr;
	receivers.append(m_LiveFaceReco->createDetectionReciever(videoIndex));
	videoThreads.append(new QThread());
	handlers.append(new VideoDetectionHandler());
	handlers.back()->connectReciever(receivers.back());
	handlers.back()->moveToThread(videoThreads.back());
	connect(videoThreads.back(), &QThread::started, handlers.back(), &VideoDetectionHandler::run);
	connect(handlers.back(), &VideoDetectionHandler::frameUpdated, (const MainWindow*)this->parent(), &MainWindow::updatePixmap);
	connect(handlers.back(), &VideoDetectionHandler::personDetected, (const MainWindow*)this->parent(), &MainWindow::updateDetectedPerson);

	handlers.back()->setRunning(true);
	videoThreads.back()->start();
	return handlers.back();
}

void LFRManager::updatePersonalCards(QStringList filenames)
{
	vector<string> vect;
	for (int i = 0; i < filenames.size(); ++i)
	{
		vect.push_back(filenames[i].toStdString());
	}
	m_LiveFaceReco->updatePersonalInfos(vect);
	m_LiveFaceReco->saveTmpInfoToFile("Faces.tmp");
}

void LFRManager::addPersonalCard(const QString &filename)
{
	m_LiveFaceReco->addPersonalInfo(filename.toStdString());
}

QString LFRManager::fileNameByID(int id)
{
	return QString(m_LiveFaceReco->fileNameByID(id).c_str());
}

void LFRManager::addVideoSource(const QString &path)
{

}

void LFRManager::askForLFR()
{
	emit sendLFR(m_LiveFaceReco);
}
