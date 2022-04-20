#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include <queue>
#include <mutex>

class LiveFaceReco;

class MessageHandler : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
	Q_PROPERTY(bool connected READ connected)

	bool m_running;

	std::queue<std::string> messages;
	std::mutex msgMutex;

	bool m_connected;

public:
	explicit MessageHandler(QObject *parent = nullptr);

	void message(const QString &msg);
	void message(const std::string &msg);
	void message(const char *msg);

	bool running() const;

	bool connected() const;

signals:

	void finished();
	void sendMessage(QString message);
	void runningChanged(bool running);
	void askForLFR();

public slots:
	void run();
	void setRunning(bool running);
	void connectToLFR(LiveFaceReco *lfr);
};

#endif // MESSAGEHANDLER_H
