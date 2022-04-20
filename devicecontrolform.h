#ifndef DEVICECONTROLFORM_H
#define DEVICECONTROLFORM_H

#include <QWidget>

namespace Ui {
class DeviceControlForm;
}

class DeviceControlForm : public QWidget
{
	Q_OBJECT

public:
	explicit DeviceControlForm(QWidget *parent = 0);
	~DeviceControlForm();

private:
	Ui::DeviceControlForm *ui;
};

#endif // DEVICECONTROLFORM_H
