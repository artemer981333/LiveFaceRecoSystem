#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personalcardmanager.h"
#include "LFR/videodetectionhandler.h"
#include <iostream>
#include <QLayout>
#include <QTextStream>

using namespace std;

Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(cv::Point)
Q_DECLARE_METATYPE(DrawInfo)
Q_DECLARE_METATYPE(PassingEvent)

void MainWindow::addCameraSource(int index, QString name, bool enterance, QUuid releID, bool showingMessage)
{
	if (index == -1)
	{
		if (showingMessage)
			QMessageBox::information(this, "Невозможно подключить камеру", "Невозможно подключить камеру");
		return;
	}
	videoSourcesNumber++;
	VideoDetectionHandler *handler = m_LFRManager->handlerByIndex(index);
	connect(this, &MainWindow::setCamerasInputResolution, handler, &VideoDetectionHandler::setCameraInputResolution, Qt::ConnectionType::DirectConnection);
	connect(this, &MainWindow::setCamerasOutputResolution, handler, &VideoDetectionHandler::setCameraOutputResolution, Qt::ConnectionType::DirectConnection);
	connect(this, &MainWindow::setBrightnessCorrection, handler, &VideoDetectionHandler::setBrightnessCorrection, Qt::ConnectionType::DirectConnection);
	connect(this, &MainWindow::setContrastCorrection, handler, &VideoDetectionHandler::setContrastCorrection, Qt::ConnectionType::DirectConnection);
	Camera cam;
	cam.enterance = enterance;
	cam.id = index;
	cam.name = name;
	cam.releID = releID;
	cam.display = new VideoDetectionHandler::VideoDisplay(this);
	if (videoSourcesNumber <= 2)
		ui->VideoLayout1->addWidget(cam.display->widget);
	else
		ui->VideoLayout2->addWidget(cam.display->widget);
	handler->connectDisplay(cam.display);
	cameras.append(cam);
	emit deleteableVideoSourceAdded(index, name, enterance);
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if (QMessageBox::StandardButton::No != QMessageBox::question(this, "Сохранение текущей конфигурации", "Сохранить текущую конфигурацию?"))
		config.saveConfig();

	addVideoSourceForm->close();
	makePhotoForm->close();

	event->accept();
}

void MainWindow::init()
{
	//регистрация типов для сигналов/слотов
	qRegisterMetaType<cv::Mat>();
	qRegisterMetaType<cv::Point>();
	qRegisterMetaType<DrawInfo>();
	qRegisterMetaType<PassingEvent>();

	videoSourcesNumber = 0;
	ui->setupUi(this);
	ui->LicenseLabel->setText("Лицензия действительна до " + licenseDate.toString("dd.MM.yyyy"));


	//помещение элементов для отображения карт в массивы
	{
		imageLabels.append(ui->CardPic1);
		imageLabels.append(ui->CardPic2);
		imageLabels.append(ui->CardPic3);
		imageLabels.append(ui->CardPic4);
		imageLabels.append(ui->CardPic5);

		fioLabels.append(ui->CardFIO1);
		fioLabels.append(ui->CardFIO2);
		fioLabels.append(ui->CardFIO3);
		fioLabels.append(ui->CardFIO4);
		fioLabels.append(ui->CardFIO5);

		dtLabels.append(ui->CardDT1);
		dtLabels.append(ui->CardDT2);
		dtLabels.append(ui->CardDT3);
		dtLabels.append(ui->CardDT4);
		dtLabels.append(ui->CardDT5);

		camLabels.append(ui->CardCam1);
		camLabels.append(ui->CardCam2);
		camLabels.append(ui->CardCam3);
		camLabels.append(ui->CardCam4);
		camLabels.append(ui->CardCam5);
	}

	ui->splitter->setStretchFactor(0, 1);
	ui->splitter->setStretchFactor(1, 0);
	ui->splitter->setStretchFactor(2, 0);



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

	config.log = m_MessageHandler;


	makePhotoForm = new MakePhotoForm;
	connect(this, &MainWindow::pixmapUpdated, makePhotoForm, &MakePhotoForm::updatePixmap);

	cardManager = new PersonalCardManager;

	cardEditForm = new PersonalCardEditorForm;
	connect(cardEditForm, &PersonalCardEditorForm::updateCardList, cardManager, &PersonalCardManager::updateCards);
	cardEditForm->connectCardManager(cardManager);
	//загрузка персональных карт
	cardManager->loadCards("Cards.json");

	addVideoSourceForm = new AddVideoSourceForm(nullptr, &devicesManager);
	connect(addVideoSourceForm, &AddVideoSourceForm::VideoSourceAddedByIndex, this, &MainWindow::addCameraSourceByIndex);
	connect(addVideoSourceForm, &AddVideoSourceForm::VideoSourceAddedByPath, this, &MainWindow::addCameraSourceByPath);
	connect(addVideoSourceForm, &AddVideoSourceForm::videoSourceDeleted, this, &MainWindow::deleteVideoSource);
	connect(this, &MainWindow::deleteableVideoSourceAdded, addVideoSourceForm, &AddVideoSourceForm::addDeleteableVideoSource);
	connect(this, &MainWindow::pixmapUpdated, addVideoSourceForm, &AddVideoSourceForm::updatePixmap);


	deviceControlForm = new DeviceControlForm(nullptr, &devicesManager);
	deviceControlForm->connectDevicesManager(&devicesManager);
	connect(deviceControlForm, &DeviceControlForm::relesListUpdated, this, &MainWindow::updateReles);

	showingCardManager.connectDevicesManager(&devicesManager);

	loadConfig();

	//настройка соединения с сервером
	connection = new ConnectionToServer();

	connect(cardManager, &PersonalCardManager::personalCardAdded, connection, &ConnectionToServer::addPersonalCard, Qt::ConnectionType::DirectConnection);
	connect(cardManager, &PersonalCardManager::personalCardEdited, connection, &ConnectionToServer::editPersonalCard, Qt::ConnectionType::DirectConnection);
	connect(cardManager, &PersonalCardManager::personalCardDeleted, connection, &ConnectionToServer::deletePersonalCard, Qt::ConnectionType::DirectConnection);

	connect(connection, &ConnectionToServer::personalCardAdded, cardManager, &PersonalCardManager::personalCardAddedSlot, Qt::ConnectionType::DirectConnection);
	connect(connection, &ConnectionToServer::personalCardEdited, cardManager, &PersonalCardManager::personalCardEditedSlot, Qt::ConnectionType::DirectConnection);
	connect(connection, &ConnectionToServer::personalCardDeleted, cardManager, &PersonalCardManager::personalCardDeletedSlot, Qt::ConnectionType::DirectConnection);

	connect(&showingCardManager, &ShowingCardManager::newPassingEvent, connection, &ConnectionToServer::newPassingEvent, Qt::ConnectionType::DirectConnection);

	connection->connect("192.168.1.34", "8080");
	connection->moveToThread(&connectionThread);
	connection->run();
	cout << "RUNNING" << endl;
}

void MainWindow::loadConfig()
{
	config.loadConfig();
	int index;

	for (int i = 0; i < config.cameras.size(); ++i)
	{
		if (config.cameras[i].rtspConnectionAddres == "null")
			index = m_LFRManager->addVideoSource(config.cameras[i].videoSourceindex);
		else
			index = m_LFRManager->addVideoSource(config.cameras[i].rtspConnectionAddres);
		if (index == -1)
		{
			//log
			continue;
		}
		addCameraSource(index, config.cameras[i].name, config.cameras[i].enterance, config.cameras[i].releID, false);
		config.cameras[i].id = index;
	}
	devicesManager.updateDevices(config.reles);
}

void MainWindow::onAuthorised(QString login)
{
	init();
	this->show();
	m_MessageHandler->message(login + " authorised");
}

void MainWindow::updatePixmap(VideoDetectionHandler::VideoDisplay *videoDisplay, cv::Mat frame, DrawInfo info)
{
	int index = std::find_if(cameras.begin(), cameras.end(), [&](const Camera &cam) { return cam.display == videoDisplay; }) - cameras.begin();
	emit pixmapUpdated(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888).rgbSwapped()), index);

	cv::rectangle(frame, info.ld, info.ru, cv::Scalar(0, 0, 255), 2);
	cv::circle(frame, info.eye1, 3, cv::Scalar(0, 255, 0), cv::FILLED, cv::LINE_AA);
	cv::circle(frame, info.eye2, 3, cv::Scalar(0, 255, 0), cv::FILLED, cv::LINE_AA);
	cv::circle(frame, info.mouse1, 3, cv::Scalar(0, 0, 255), cv::FILLED, cv::LINE_AA);
	cv::circle(frame, info.mouse2, 3, cv::Scalar(0, 0, 255), cv::FILLED, cv::LINE_AA);
	cv::circle(frame, info.nose, 3, cv::Scalar(255, 0, 0), cv::FILLED, cv::LINE_AA);

	std::string fps = "FPS: " + std::to_string((int)info.fps);
	std::string angle = "Angle: " + std::to_string((int)info.angle);
	cv::putText(frame, fps, cv::Point(5, 20), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);
	cv::putText(frame, angle, cv::Point(5, 40), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);


	QPixmap pixmap = QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888).rgbSwapped());
	videoDisplay->pixmap->setPixmap(pixmap);
	videoDisplay->widget->fitInView(videoDisplay->pixmap, Qt::KeepAspectRatio);

}

void MainWindow::updateDetectedPerson(bool detected, int id, double confidence, double similarity, VideoDetectionHandler::VideoDisplay *videoDisplay)
{
	if (!detected)
		return;
	ui->ConfidenceLE->setText(QString::number(confidence));
	ui->SimilarityLE->setText(QString::number(similarity));
	//проверки на порог схожести и достоверности
	if(similarity < 0.4)
		return;
	bool fakeFace = false;
	if (confidence >= 0.75)
	{
		ui->RealFaceLabel->setText("Настоящее лицо");
		ui->RealFaceLabel->setStyleSheet("background-color: #00ff00;");
	}
	else
	{
		ui->RealFaceLabel->setText("Попытка обмана (лицо ненастоящее)");
		ui->RealFaceLabel->setStyleSheet("background-color: #ff0000;");
		if (ui->SpuffingCB->isChecked())
			fakeFace = true;
	}
	//нахождение карточки идентифицированного человека
	QString fileName = m_LFRManager->fileNameByID(id);
	const QList<PersonalCard> *list = cardManager->personalCards();
	auto card = std::find_if(list->begin(), list->end(), [&](const PersonalCard &card) { return card.imagePath == fileName; });
	if (card == list->end())
	{
		m_MessageHandler->message("Unknown filename");
		return;
	}
	auto cam = std::find_if(cameras.begin(), cameras.end(), [&](const Camera &cam) { return cam.display == videoDisplay; });

	ShowingCardManager::DetectionResult detResult =
			showingCardManager.personDetected(card->id, card->surname + " " + card->name + " " + card->lastname, card->imagePath, cam->id, cam->enterance, cam->releID, fakeFace);

	ui->Repass->setText("Проходите");
	ui->Repass->setStyleSheet("background-color: #00ff00;");
	switch (detResult)
	{
	case ShowingCardManager::DetectionResult::Reentering:
	{
		ui->Repass->setText("Несанкционированный вход");
		ui->Repass->setStyleSheet("background-color: #ff0000;");
		break;
	}
	case ShowingCardManager::DetectionResult::Reexiting:
	{
		ui->Repass->setText("Несанкционированный выход");
		ui->Repass->setStyleSheet("background-color: #ff0000;");
		break;
	}
	case ShowingCardManager::DetectionResult::FakeFace:
	{
		ui->Repass->setText("Спуфинг");
		ui->Repass->setStyleSheet("background-color: #ff0000;");
		break;
	}
	}
	//отображение последних распознанных карточек
	for (int i = 0; i < showingCardManager.cardsNumber(); ++i)
	{
		imageLabels[i]->setPixmap(showingCardManager.getCardOnPosition(i).image.scaled(imageLabels[i]->size(), Qt::KeepAspectRatio));
		fioLabels[i]->setText(showingCardManager.getCardOnPosition(i).fio());
		dtLabels[i]->setText(showingCardManager.getCardOnPosition(i).dt());
		camLabels[i]->setText(showingCardManager.getCardOnPosition(i).cam());
	}
	ui->EnteredLE->setText(QString::number(showingCardManager.entered()));
	ui->ExitedLE->setText(QString::number(showingCardManager.exited()));
	ui->NowLE->setText(QString::number(std::max(0, showingCardManager.entered() - showingCardManager.exited())));
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void MainWindow::addMessage(QString message)
{
	ui->plainTextEdit->appendPlainText(message);
}

void MainWindow::updatePersonalCards(const QList<PersonalCard> &cards)
{
	cardManager->updateCards(cards);
	QStringList filenames;
	QList<int> brightnessCorrs, contrastCorrs;
	for (int i = 0; i < cards.size(); ++i)
	{
		filenames.append(cards[i].imagePath);
		brightnessCorrs.append(cards[i].brightnessCorrection);
		contrastCorrs.append(cards[i].contrastCorrection);
	}
	m_LFRManager->updatePersonalCards(filenames, brightnessCorrs, contrastCorrs);
	cardManager->saveCards("Cards.json");
}

void MainWindow::updateReles(const QList<DevicesManager::Rele> &reles)
{
	devicesManager.updateDevices(reles);
	config.reles = reles;
}

void MainWindow::addCameraSourceByIndex(int sourceIndex, QString name, bool enterance, QUuid releID)
{
	int index = m_LFRManager->addVideoSource(sourceIndex);
	if (index == -1)
	{
		QMessageBox::information(this, "Can't connect camera", "Chosen camera can not be conected");
		return;
	}
	Configure::Cam newCam(sourceIndex, "null", name, enterance, index, releID);
	addCameraSource(newCam.id, newCam.name, newCam.enterance, releID);
	config.cameras.append(newCam);
}

void MainWindow::addCameraSourceByPath(const QString &path, QString name, bool enterance, QUuid releID)
{
	int index = m_LFRManager->addVideoSource(path);
	if (index == -1)
	{
		QMessageBox::information(this, "Can't connect camera", "Chosen camera can not be conected");
		return;
	}
	Configure::Cam newCam(-1, path, name, enterance, index, releID);
	addCameraSource(newCam.id, newCam.name, newCam.enterance, releID);
	config.cameras.append(newCam);
}

void MainWindow::deleteVideoSource(int index)
{
	cameras[index].display->widget->hide();
	if (videoSourcesNumber >= 2)
		ui->VideoLayout2->removeWidget(cameras[index].display->widget);
	else
		ui->VideoLayout1->removeWidget(cameras[index].display->widget);
	m_LFRManager->deleteVideoSource(index);
	for (int i = 0; i < config.cameras.size(); ++i)
		if (config.cameras[i].id == index)
			config.cameras.removeAt(i);
	videoSourcesNumber--;
}

MainWindow::~MainWindow()
{
	for (int i = 0; i < cameras.size(); ++i)
		delete cameras[i].display;
	delete cardEditForm;
	delete cardManager;
	delete m_LFRManager;
	delete ui;

	m_MessageHandler->setRunning(false);
	delete m_MessageHandler;
	messageHandlerThread.quit();
	messageHandlerThread.wait();
}

void MainWindow::setLicenseDate(QDate date)
{
	licenseDate = date;
}

void MainWindow::on_OpenPersonalCardEditor_triggered()
{
	cardEditForm->show();
}

void MainWindow::on_MakePhoto_triggered()
{
	makePhotoForm->show();
}

void MainWindow::Configure::saveConfig()
{
	log->message("Saving config");
	QFile f("config.lfr");
	f.open(QIODevice::WriteOnly);
	QTextStream s(&f);
	s << cameras.size() << endl;
	for (int i = 0; i < cameras.size(); ++i)
	{
		s << cameras[i].enterance << endl;
		s << cameras[i].name << endl;
		s << cameras[i].rtspConnectionAddres << endl;
		s << cameras[i].videoSourceindex << endl;
		s << cameras[i].releID.toString() << endl;
	}
	s << reles.size() << endl;
	for (int i = 0; i < reles.size(); ++i)
	{
		s << reles[i].id.toString() << endl;
		s << reles[i].name << endl;
		s << reles[i].query << endl;
	}

	f.close();
	log->message("Config saved");
}

void MainWindow::Configure::loadConfig()
{
	log->message("Loading config");
	QFile f("config.lfr");
	if (!f.exists())
	{
		log->message("Config file does not exist");
		return;
	}
	f.open(QIODevice::ReadOnly);
	QTextStream s(&f);

	int camerasNumber, relesNumber;
	Configure::Cam cam;
	QString releName, releQuery, releIDString;
	s >> camerasNumber;
	for (int i = 0; i < camerasNumber; ++i)
	{
		s >> (int &)cam.enterance;
		s >> cam.name;
		s >> cam.rtspConnectionAddres;
		s >> cam.videoSourceindex;
		s >> releIDString;
		cam.releID = QUuid(releIDString);
		cameras.append(cam);
	}
	s >> relesNumber;
	for (int i = 0; i < relesNumber; ++i)
	{
		s >> releIDString;
		s >> releName;
		releQuery = s.readLine();
		releQuery = s.readLine();
		reles.append(DevicesManager::Rele(releName, releQuery, QUuid(releIDString)));
	}

	f.close();
	log->message("Config loaded");
}

MainWindow::Configure::Cam::Cam(int videoSourceindex, const QString &rtspConnectionAddres, const QString &name, bool enterance, int id, QUuid releID) :
	videoSourceindex(videoSourceindex),
	rtspConnectionAddres(rtspConnectionAddres),
	name(name),
	enterance(enterance),
	id(id),
	releID(releID)
{
	if (this->name == "")
		this->name = "Cam" + QString::number(id);
}

MainWindow::Configure::Cam::Cam() { name = "Cam"; rtspConnectionAddres = "null"; }

void MainWindow::on_DeviceControlAction_triggered()
{
	deviceControlForm->show();
}

void MainWindow::on_CameraControlAction_triggered()
{
	addVideoSourceForm->show();
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
	emit setBrightnessCorrection(ui->horizontalSlider->value());
}

void MainWindow::on_horizontalSlider_2_actionTriggered(int action)
{
	emit setContrastCorrection(ui->horizontalSlider_2->value());
}
