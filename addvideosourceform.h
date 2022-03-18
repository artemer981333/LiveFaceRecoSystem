#ifndef ADDVIDEOSOURCEFORM_H
#define ADDVIDEOSOURCEFORM_H

#include <QWidget>

namespace Ui {
class AddVideoSourceForm;
}

class AddVideoSourceForm : public QWidget
{
	Q_OBJECT

public:
	explicit AddVideoSourceForm(QWidget *parent = 0);
	~AddVideoSourceForm();

private:
	Ui::AddVideoSourceForm *ui;
};

#endif // ADDVIDEOSOURCEFORM_H
