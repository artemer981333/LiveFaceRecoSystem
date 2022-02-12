#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/QCameraInfo>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	cardManager = new PersonalCardManager();

	cardEditForm = new PersonalCardEditorForm;
	cardEditForm->connectCardManager(cardManager);


	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	for (int i = 0; i < cameras.size(); ++i)
		ui->CamerasComboBox->addItem(QString::number(i) + ": " + cameras[i].description());

	m_MessageHandler = new MessageHandler;
	m_LFRManager = new LFRManager(this);

	connect(m_LFRManager, &LFRManager::sendLFR, m_MessageHandler, &MessageHandler::connectToLFR, Qt::ConnectionType::DirectConnection);
	connect(m_MessageHandler, &MessageHandler::askForLFR, m_LFRManager, &LFRManager::askForLFR, Qt::ConnectionType::DirectConnection);
	connect(&messageHandlerThread, &QThread::started, m_MessageHandler, &MessageHandler::run);
	connect(m_MessageHandler, &MessageHandler::finished, &messageHandlerThread, &QThread::quit);
	connect(m_MessageHandler, &MessageHandler::sendMessage, this, &MainWindow::addMessage);

	m_MessageHandler->moveToThread(&messageHandlerThread);

	m_MessageHandler->setRunning(true);

	messageHandlerThread.start();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	m_MessageHandler->setRunning(false);
	delete m_MessageHandler;
	messageHandlerThread.quit();

	event->accept();
}

void MainWindow::updatePixmap(VideoDetectionHandler::VideoDisplay *videoDisplay, QPixmap pixmap)
{
	videoDisplay->pixmap->setPixmap(pixmap);
}

void MainWindow::addMessage(QString message)
{
	ui->plainTextEdit->appendPlainText(message);
}

MainWindow::~MainWindow()
{
	messageHandlerThread.wait();
	for (int i = 0; i < videoDisplays.size(); ++i)
		delete videoDisplays[i];
	delete cardEditForm;
	delete cardManager;
	delete m_LFRManager;
	delete ui;
}

void MainWindow::on_AddCameraButton_clicked()
{
	VideoDetectionHandler *handler = m_LFRManager->addVideoSource(ui->CamerasComboBox->currentIndex());
	if (handler == nullptr)
	{
		QMessageBox::information(this, "Can't connect camera", "Chosen camera can not be conected");
		return;
	}
	videoDisplays.append(new VideoDetectionHandler::VideoDisplay(this));
	ui->VideoLayout->addWidget(videoDisplays.back()->widget);
	handler->connectDisplay(videoDisplays.back());
}


void MainWindow::on_OpenPersonalCardEditor_triggered()
{
	cardEditForm->show();
}
