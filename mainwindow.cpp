#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personalcardmanager.h"
#include <QtMultimedia/QCameraInfo>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->splitter->setStretchFactor(0, 1);
	ui->splitter->setStretchFactor(1, 0);
	ui->splitter->setStretchFactor(2, 0);

	makePhotoForm = new MakePhotoForm;
	connect(this, &MainWindow::pixmapUpdated, makePhotoForm, &MakePhotoForm::updatePixmap);

	cardManager = new PersonalCardManager;

	cardEditForm = new PersonalCardEditorForm;
	cardEditForm->connectCardManager(cardManager);
	cardManager->loadCards("Cards.json");


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

	connect(cardEditForm, &PersonalCardEditorForm::updateCardList, this, &MainWindow::updatePersonalCards);

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
	pixmapUpdated(pixmap);
}

void MainWindow::updateDetectedPerson(int id, double confidence, double similarity)
{
	ui->ConfidenceLE->setText(QString::number(confidence));
	ui->SimilarityLE->setText(QString::number(similarity));
	if (confidence < 0.4)
		return;
	QString fileName = m_LFRManager->fileNameByID(id);
	const QList<PersonalCard> *list = cardManager->personalCards();
	auto card = std::find_if(list->begin(), list->end(), [&](const PersonalCard &card) { return card.imagePath == fileName; });
	if (card == list->end())
	{
		cout << "Unknown filename" << endl;
		return;
	}
	ui->SurnameLE->setText(card->surname);
	ui->NameLE->setText(card->name);
	ui->LastnameLE->setText(card->lastname);
	ui->PostLE->setText(card->post);
	ui->SubdivisionLE->setText(card->subdivision);
	QPixmap pixmap(card->imagePath);
	ui->PhotoLable->setPixmap(pixmap);
}

void MainWindow::addMessage(QString message)
{
	ui->plainTextEdit->appendPlainText(message);
}

void MainWindow::updatePersonalCards(const QList<PersonalCard> &cards)
{
	cardManager->updateCards(cards);
	QStringList filenames;
	for (int i = 0; i < cards.size(); ++i)
		filenames.append(cards[i].imagePath);
	m_LFRManager->updatePersonalCards(filenames);
	cardManager->saveCards("Cards.json");
	cout << "2" << endl;
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
	videoDisplays.back()->widget->fitInView(videoDisplays.back()->pixmap, Qt::KeepAspectRatio);
	handler->connectDisplay(videoDisplays.back());
}


void MainWindow::on_OpenPersonalCardEditor_triggered()
{
	cardEditForm->show();
}

void MainWindow::on_MakePhoto_triggered()
{
	makePhotoForm->show();
}
