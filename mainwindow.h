#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QThread>

#include "LFR/lfrmanager.h"
#include "LFR/videodetectionhandler.h"
#include "messagehandler.h"
#include "personalcardeditorform.h"

#include "opencv2/opencv.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QList<VideoDetectionHandler::VideoDisplay *> videoDisplays;

	Ui::MainWindow *ui;

	LFRManager *m_LFRManager;

	MessageHandler *m_MessageHandler;
	QThread messageHandlerThread;

	PersonalCardEditorForm *cardEditForm;
	PersonalCardManager *cardManager;

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void closeEvent(QCloseEvent *event);

public slots:
	void updatePixmap(VideoDetectionHandler::VideoDisplay  *videoDisplay, QPixmap mPixmap);
	void addMessage(QString message);
private slots:
	void on_AddCameraButton_clicked();
	void on_OpenPersonalCardEditor_triggered();
};

#endif // MAINWINDOW_H

//карточки, добавление источников разных, интерфейс, QSS, реле, сохранение конфигурации и логов, кринжовая авторизация
//ВИКИ (ОПИСАНИЕ), ДОКУМЕНТАЦИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
