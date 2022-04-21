#ifndef LFRMSGHANDLER_H
#define LFRMSGHANDLER_H

#include <thread>
#include <mutex>
#include <queue>

class LFRMsgHandler
{
public:
	LFRMsgHandler(std::queue<std::string> *queue = nullptr, std::mutex *mutex = nullptr);
	~LFRMsgHandler();

	bool isRunning() const;
	void start();
	void stop();


	bool connectQueue(std::queue<std::string> *queue, std::mutex *mutex);

	void addMessage(std::string message);

private:

	void handle();

	std::thread th;

	bool m_running;
	std::queue<std::string> m_queueSrc;
	std::mutex m_mutexSrc;

	std::queue<std::string> *m_queueDest;
	std::mutex *m_mutexDest;
};

#endif // LFRMSGHANDLER_H
