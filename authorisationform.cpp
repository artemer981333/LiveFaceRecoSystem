#include "authorisationform.h"
#include "ui_authorisationform.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

AuthorisationForm::AuthorisationForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AuthorisationForm)
{
	ui->setupUi(this);
}

AuthorisationForm::~AuthorisationForm()
{
	delete ui;
}

void AuthorisationForm::on_pushButton_clicked()
{
	QFile f("users.lfr");
	if (!f.exists())
	{
		QMessageBox::information(this, "Файл пользователей не найден", "Файл пользователей не найден");
		return;
	}
	f.open(QIODevice::ReadOnly);
	QTextStream s(&f);
	QString login, password;
	s >> login;
	s >> password;
	if (login != ui->LoginLE->text() || password != ui->PasswordLE->text())
	{
		QMessageBox::information(this, "Неверный логин или пароль", "Неверный логин или пароль");
		return;
	}
	emit authorised(ui->LoginLE->text());
	this->close();
}
