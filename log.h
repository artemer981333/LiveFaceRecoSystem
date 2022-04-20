#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <queue>
#include <mutex>

class Log : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
	bool m_running;

	std::queue<std::string> messages;
	std::mutex msgMutex;

public:
	explicit Log(QObject *parent = nullptr);

	bool running() const;

signals:

	void runningChanged(bool running);

public slots:
	void setRunning(bool running);
};

#endif // LOG_H
