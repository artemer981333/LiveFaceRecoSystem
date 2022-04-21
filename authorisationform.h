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

	bool auth;

	void authorisation();

signals:
	void authorised(QString login);

private slots:
	void on_pushButton_clicked();

private:
	Ui::AuthorisationForm *ui;
};

#endif // AUTHORISATIONFORM_H
