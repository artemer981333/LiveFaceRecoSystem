#include "devicecontrolform.h"
#include "ui_devicecontrolform.h"

DeviceControlForm::DeviceControlForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DeviceControlForm)
{
	ui->setupUi(this);
}

DeviceControlForm::~DeviceControlForm()
{
	delete ui;
}
