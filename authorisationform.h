#ifndef AUTHORISATIONFORM_H
#define AUTHORISATIONFORM_H

#include <QWidget>

namespace Ui {
class AuthorisationForm;
}

class AuthorisationForm : public QWidget
{
	Q_OBJECT

public:
	explicit AuthorisationForm(QWidget *parent = 0);
	~AuthorisationForm();

private:
	Ui::AuthorisationForm *ui;
};

#endif // AUTHORISATIONFORM_H
