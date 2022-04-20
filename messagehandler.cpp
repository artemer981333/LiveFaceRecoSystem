#include "messagehandler.h"
#include "LFR/livefacereco.hpp"
#include <QThread>
#include <QFile>
#include <QTextStream>

MessageHandler::MessageHandler(QObject *parent) : QObject(parent)
{
	m_connected = false;
	m_running = false;
}

void MessageHandler::message(const QString &msg)
{
	msgMutex.lock();
	messages.push(msg.toStdString());
	msgMutex.unlock();
}

void MessageHandler::message(const std::string &msg)
{
	msgMutex.lock();
	messages.push(msg);
	msgMutex.unlock();
}

void MessageHandler::message(const char *msg)
{
	msgMutex.lock();
	messages.push(std::string(msg));
	msgMutex.unlock();
}

void MessageHandler::connectToLFR(LiveFaceReco *lfr)
{
	lfr->connectMessages(&messages, &msgMutex);
}

bool MessageHandler::running() const
{
	return m_running;
}

bool MessageHandler::connected() const
{
	return m_connected;
}

void MessageHandler::run()
{
	if (!m_connected)
		emit askForLFR();
	QFile f("log.lfr");
	f.open(QIODevice::WriteOnly);
	QTextStream s(&f);

	while(m_running)
	{
		if (!messages.empty())
		{
			s << QString::fromStdString(messages.front());
			emit sendMessage(QString::fromStdString(messages.front()));
			messages.pop();
		}
		QThread::msleep(10);
	}
	f.close();
	emit finished();
}

void MessageHandler::setRunning(bool running)
{
	if (m_running == running)
		return;

	m_running = running;
	emit runningChanged(m_running);
}
