#ifndef DEVICECONTROLFORM_H
#define DEVICECONTROLFORM_H

#include <QWidget>
#include <QStringListModel>
#include "devicesmanager.h"

namespace Ui {
class DeviceControlForm;
}

class DeviceControlForm : public QWidget
{
	Q_OBJECT

	QStringList relesList;
	QStringListModel *listModel;
	QList<DevicesManager::Rele> newRelesList;

	void updateDevicesListModel(const QStringList &list);

public:
	explicit DeviceControlForm(QWidget *parent = 0, DevicesManager *devicesManager = nullptr);
	~DeviceControlForm();

	void connectDevicesManager(DevicesManager *manager);

signals:
	void relesListUpdated(const QList<DevicesManager::Rele> &reles);

public slots:

	void showEvent(QShowEvent *event);

private slots:
	void on_AddButton_clicked();

	void on_DevicesList_clicked(const QModelIndex &index);

	void on_EditButton_clicked();

	void on_OKButton_clicked();

private:
	Ui::DeviceControlForm *ui;
	DevicesManager *devicesManager;
};

#endif // DEVICECONTROLFORM_H
