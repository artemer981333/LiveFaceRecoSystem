#include "devicecontrolform.h"
#include "ui_devicecontrolform.h"
#include <QMessageBox>

DeviceControlForm::DeviceControlForm(QWidget *parent, DevicesManager *manager) :
	QWidget(parent),
	ui(new Ui::DeviceControlForm)
{
	ui->setupUi(this);
	this->devicesManager = manager;
	listModel = new QStringListModel;
	ui->DevicesList->setModel(listModel);
}

void DeviceControlForm::updateDevicesListModel(const QStringList &list)
{
	listModel->setStringList(list);
}

DeviceControlForm::~DeviceControlForm()
{
	delete ui;
}

void DeviceControlForm::connectDevicesManager(DevicesManager *manager)
{
	devicesManager = manager;
}

void DeviceControlForm::showEvent(QShowEvent *event)
{
	relesList.clear();
	newRelesList = QList<DevicesManager::Rele>(devicesManager->getReles());
	for (int i = 0; i < newRelesList.size(); ++i)
		relesList.append(newRelesList[i].name);
	updateDevicesListModel(relesList);
}

void DeviceControlForm::on_AddButton_clicked()
{
	if (ui->ReleNameLE->text() == "")
	{
		QMessageBox::information(this, "Введите имя", "Введите имя");
		return;
	}
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение добавления", "Вы действительно хотите добавить данную карточку?"))
		return;
	DevicesManager::Rele rele(ui->ReleNameLE->text(), ui->QueryLE->text());
	newRelesList.append(rele);
	relesList.append(newRelesList.back().name);
	updateDevicesListModel(relesList);
}

void DeviceControlForm::on_DevicesList_clicked(const QModelIndex &index)
{
	const DevicesManager::Rele &rele = newRelesList[index.row()];
	ui->EditIDLE->setText(rele.id.toString());
	ui->EditNameLE->setText(rele.name);
	ui->EditQueueLE->setText(rele.query);
}

void DeviceControlForm::on_EditButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение редактирования", "Вы действительно хотите редактировать информацию о данном устройстве?"))
		return;
	DevicesManager::Rele &rele = newRelesList[ui->DevicesList->currentIndex().row()];
	rele.name = ui->EditNameLE->text();
	rele.query = ui->EditQueueLE->text();
	relesList[ui->DevicesList->currentIndex().row()] = rele.name;
	updateDevicesListModel(relesList);
}

void DeviceControlForm::on_OKButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение изменений", "Вы действительно хотите внести сделанные изменения?"))
		return;
	emit relesListUpdated(newRelesList);
	this->close();
}
