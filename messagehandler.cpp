#include "messagehandler.h"
#include "LFR/livefacereco.hpp"
#include <QThread>

MessageHandler::MessageHandler(QObject *parent) : QObject(parent)
{
	m_connected = false;
	m_running = false;
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
	while(m_running)
	{
		if (!messages.empty())
		{
			emit sendMessage(QString(messages.front().c_str()));
			messages.pop();
		}
		QThread::msleep(10);
	}
	emit finished();
}

void MessageHandler::setRunning(bool running)
{
	if (m_running == running)
		return;

	m_running = running;
	emit runningChanged(m_running);
}
