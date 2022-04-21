#include "lfrmsghandler.h"

using namespace std;

LFRMsgHandler::LFRMsgHandler(std::queue<std::string> *queue, std::mutex *mutex)
{
	m_running = false;
	m_queueDest = nullptr;
	m_mutexDest = nullptr;
	connectQueue(queue, mutex);
}

LFRMsgHandler::~LFRMsgHandler()
{
	stop();
	th.join();
}

bool LFRMsgHandler::isRunning() const
{
	return m_running;
}

void LFRMsgHandler::start()
{
	if (m_running)
		return;
	if (th.joinable())
		th.join();
	m_running = true;
	th = std::thread([&]()
	{
		handle();
	});
}

void LFRMsgHandler::stop()
{
	if (!m_running)
		return;
	m_running = false;
}

bool LFRMsgHandler::connectQueue(std::queue<std::string> *queue, std::mutex *mutex)
{
	if (m_queueDest != nullptr || m_mutexDest != nullptr)
		return false;
	m_queueDest = queue;
	m_mutexDest = mutex;
}

void LFRMsgHandler::addMessage(std::string message)
{
	m_mutexSrc.lock();
	m_queueSrc.push(message);
	m_mutexSrc.unlock();
}

void LFRMsgHandler::handle()
{
	while (m_queueDest == nullptr || m_mutexDest == nullptr)
		std::this_thread::sleep_for(std::chrono::microseconds(5));
	while (m_running)
	{
		while (m_running && m_queueSrc.empty())
			std::this_thread::sleep_for(std::chrono::microseconds(5));
		if (!m_running)
			break;
		m_mutexSrc.lock();
		std::string s = m_queueSrc.front();
		m_queueSrc.pop();
		m_mutexSrc.unlock();
		m_mutexDest->lock();
		m_queueDest->push(s);
		m_mutexDest->unlock();
	}
}
