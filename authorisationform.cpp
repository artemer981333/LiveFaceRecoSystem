#include "authorisationform.h"
#include "ui_authorisationform.h"

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
