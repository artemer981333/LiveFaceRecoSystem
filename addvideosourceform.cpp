#include "addvideosourceform.h"
#include "ui_addvideosourceform.h"

AddVideoSourceForm::AddVideoSourceForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AddVideoSourceForm)
{
	ui->setupUi(this);
}

AddVideoSourceForm::~AddVideoSourceForm()
{
	delete ui;
}
