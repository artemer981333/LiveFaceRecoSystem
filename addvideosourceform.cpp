#include "addvideosourceform.h"
#include "ui_addvideosourceform.h"
#include <QtMultimedia/QCameraInfo>
#include <iostream>
#include <thread>

using namespace std;

void AddVideoSourceForm::deleteDelVideoItem(int index)
{
	emit videoSourceDeleted(index);
	deleteVideoItems[index].button->hide();
	deleteVideoItems[index].picture->hide();
	deleteVideoItems[index].label->hide();
	ui->DeleteableVideoSourcesLayout->removeItem(deleteVideoItems[index].layout);
	ui->DeleteableVideoSourcesLayout->removeWidget(deleteVideoItems[index].button);
	delete deleteVideoItems[index].pixmap;
	delete deleteVideoItems[index].scene;
	deleteVideoItems[index].pixmap = nullptr;
	deleteVideoItems[index].scene = nullptr;
}

AddVideoSourceForm::AddVideoSourceForm(QWidget *parent, DevicesManager *manager) :
	QWidget(parent),
	ui(new Ui::AddVideoSourceForm)
{
	ui->setupUi(this);
	this->devicesManager = manager;

	std::thread t = std::thread([&]()
	{
		QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
		ui->CamerasCB->clear();
		for (int i = 0; i < cameras.size(); ++i)
			ui->CamerasCB->addItem(QString::number(i) + ": " + cameras[i].description());
		QList<QCameraInfo> newCameras;
		while (true)
		{
			newCameras = QCameraInfo::availableCameras();
			if (cameras.size() != newCameras.size())
			{
				cameras = QCameraInfo::availableCameras();
				ui->CamerasCB->clear();
				for (int i = 0; i < cameras.size(); ++i)
					ui->CamerasCB->addItem(QString::number(i) + ": " + cameras[i].description());
			}
			this_thread::sleep_for(chrono::seconds(1));
		}
	});
	t.detach();

//	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
//	for (int i = 0; i < cameras.size(); ++i)
//		ui->CamerasCB->addItem(QString::number(i) + ": " + cameras[i].description());
}

AddVideoSourceForm::~AddVideoSourceForm()
{
	delete ui;
}

void AddVideoSourceForm::addDeleteableVideoSource(int index, QString name, bool enterance)
{
	DeleteVideoItem item;
	item.layout = new QVBoxLayout;
	item.label = new QLabel(this);
	item.picture = new QGraphicsView(this);
	item.scene = new QGraphicsScene(this);
	item.pixmap = new QGraphicsPixmapItem;
	item.picture->setScene(item.scene);
	item.scene->addItem(item.pixmap);
	item.button = new QPushButton(this);
	item.button->setText("Удалить\nвидеопоток");
	connect(item.button, &QPushButton::clicked, this, [this, index](bool)
	{
		deleteDelVideoItem(index);
	});
	item.label->setText("ID: " + QString::number(index) + "\nИмя: " + name + "\n" + ((enterance) ? ("Вход") : ("Выход")));
	item.index = index;
	item.layout->addWidget(item.button);
	item.layout->addWidget(item.label);
	deleteVideoItems.append(item);
	int row = ui->DeleteableVideoSourcesLayout->rowCount();
	ui->DeleteableVideoSourcesLayout->addLayout(item.layout, row, 0);
	ui->DeleteableVideoSourcesLayout->addWidget(item.picture, row, 1);
}

void AddVideoSourceForm::updatePixmap(QPixmap pixmap, int index)
{
	if (deleteVideoItems[index].pixmap == nullptr)
		return;
	deleteVideoItems[index].pixmap->setPixmap(pixmap);
	deleteVideoItems[index].picture->fitInView(deleteVideoItems[index].pixmap, Qt::KeepAspectRatio);
}

void AddVideoSourceForm::on_AddButton_clicked()
{
	QUuid releID;
	if (ui->AddRele->isChecked())
		releID = devicesManager->getReles()[ui->RelesList->currentIndex()].id;
	if (ui->USBButton->isChecked())
		emit VideoSourceAddedByIndex(ui->CamerasCB->currentIndex(), ui->CamNameLE->text(), ui->EnteranceRB->isChecked(), releID);
	if (ui->RTSPButton->isChecked())
		emit VideoSourceAddedByPath("rtsp://" + ui->IPAddresLE->text(), ui->CamNameLE->text(), ui->EnteranceRB->isChecked(), releID);
}

void AddVideoSourceForm::on_AddRele_clicked(bool checked)
{
	if (!checked)
	{
		ui->RelesList->clear();
		return;
	}
	const QList<DevicesManager::Rele> &reles = devicesManager->getReles();
	for (int i = 0; i < reles.size(); ++i)
	{
		ui->RelesList->addItem(reles[i].name);
	}
}
