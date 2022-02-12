#include "personalcardeditorform.h"
#include "ui_personalcardeditorform.h"

PersonalCardEditorForm::PersonalCardEditorForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PersonalCardEditorForm)
{
	ui->setupUi(this);
}

PersonalCardEditorForm::~PersonalCardEditorForm()
{
	delete ui;
}

void PersonalCardEditorForm::connectCardManager(PersonalCardManager *manager)
{
	this->manager = manager;
	manager->loadCards("Cards.json");
}

void PersonalCardEditorForm::showEvent(QShowEvent *event)
{
	const QList<PersonalCard> *cards = manager->personalCards();
	QStringList list;
	for (int i = 0; i < cards->size(); ++i)
	{
		list.append(cards->at(i).surname + " " + cards->at(i).name + " " + cards->at(i).lastname);
	}
	ui->CardList->addItems(list);
}

void PersonalCardEditorForm::on_AddCardButton_clicked()
{
	PersonalCard card;
//	card.surname = ui->lineEdit->text();
//	card.name = ui->lineEdit_2->text();
//	card.lastname = ui->lineEdit_3->text();
//	card.post = ui->lineEdit_4->text();
//	card.subdivision = ui->lineEdit_5->text();
//	card.imagePath = ui->lineEdit_6->text();
	manager->addCard(card);
	manager->saveCards("Cards.json");
}

void PersonalCardEditorForm::on_CardList_currentRowChanged(int currentRow)
{
	PersonalCard card = manager->personalCards()->at(currentRow);
//	ui->lineEdit->setText(card.surname);
//	ui->lineEdit_2->setText(card.name);
//	ui->lineEdit_3->setText(card.lastname);
//	ui->lineEdit_4->setText(card.post);
//	ui->lineEdit_5->setText(card.subdivision);
//	ui->lineEdit_6->setText(card.imagePath);
}

