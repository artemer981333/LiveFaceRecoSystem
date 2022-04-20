#ifndef LFRHANDLER_H
#define LFRHANDLER_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include <vector>
#include "livefacereco.hpp"
#include "messagehandler.h"

class VideoDetectionHandler;

//менеджер взаимодействия QT приложения с LFR
class LFRManager : public QObject
{
	Q_OBJECT

	LiveFaceReco *m_LiveFaceReco;

	//структура видеопотока
	struct VideoStream
	{
		QThread *videoThread;	//поток, в котором происходит обработка одного видеопотока
		VideoDetectionHandler *handler;	//обработчик
		LiveFaceReco::DetectionReceiver *receiver;	//приемник информации, выдаваемый LFR
	};

	QList<VideoStream> streams;

	QThread msgThread;

public:
	explicit LFRManager(QObject *parent = nullptr);
	~LFRManager();

	int addVideoSource(int cameraIndex);	//возвращает id видеопотока(номер в массиве)
	int addVideoSource(const QString &path);	//возвращает id видеопотока(номер в массиве)
	void deleteVideoSource(int index);	//удаляет видеопоток по id

	VideoDetectionHandler *handlerByIndex(int index);	//возвращает обработчик, отвечающий за видеопоток с данным id

	void updatePersonalCards(const QStringList &filenames, const QList<int> &brightnesCorrs, const QList<int> &contrastCorrs);
	QString fileNameByID(int id);

signals:
	void sendLFR(LiveFaceReco *liveFaceReco);
	void videoSourceConnected();

public slots:
	void askForLFR();
};

#endif // LFRHANDLER_H
