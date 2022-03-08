#include "personalcardeditorform.h"
#include "ui_personalcardeditorform.h"
#include <QMessageBox>
#include <QPicture>
#include <QFileDialog>
#include <QRegExp>
#include <iostream>

PersonalCardEditorForm::PersonalCardEditorForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PersonalCardEditorForm)
{
	ui->setupUi(this);
	listModel = new QStringListModel;
	ui->CardView->setModel(listModel);
}

PersonalCardEditorForm::~PersonalCardEditorForm()
{
	delete listModel;
	delete ui;
}

void PersonalCardEditorForm::connectCardManager(PersonalCardManager *manager)
{
	this->manager = manager;
}

void PersonalCardEditorForm::updateCardListModel(const QStringList &list)
{
	listModel->setStringList(list);
}

void PersonalCardEditorForm::showEvent(QShowEvent *event)
{
	cardList.clear();
	newCardList = QList<PersonalCard>(*(manager->personalCards()));
	for (int i = 0; i < newCardList.size(); ++i)
		cardList.append(newCardList[i].surname + " " + newCardList[i].name + " " + newCardList[i].lastname);
	updateCardListModel(cardList);
}

void PersonalCardEditorForm::on_AddCardButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение добавления", "Вы действительно хотите добавить данную карточку?"))
		return;
	PersonalCard card;
	card.surname = ui->AddSurnameLE->text();
	card.name = ui->AddNameLE->text();
	card.lastname = ui->AddLastnameLE->text();
	card.post = ui->AddPostLE->text();
	card.subdivision = ui->AddSubdivisionLE->text();
	card.imagePath = ui->AddImagePathLE->text();
	card.id = QUuid::createUuid();
	newCardList.append(card);
	cardList.append(newCardList.back().surname + " " + newCardList.back().name + " " + newCardList.back().lastname);
	updateCardListModel(cardList);
}

void PersonalCardEditorForm::on_EditCardButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение редактирования", "Вы действительно хотите редактировать данную карточку?"))
		return;
	PersonalCard &editingCard = newCardList[ui->CardView->currentIndex().row()];
	editingCard.imagePath = ui->EditImagePathLE->text();
	editingCard.lastname = ui->EditLastnameLE->text();
	editingCard.name = ui->EditNameLE->text();
	editingCard.post = ui->EditPostLE->text();
	editingCard.subdivision = ui->EditSubdivisionLE->text();
	editingCard.surname = ui->EditSurnameLE->text();
	cardList[ui->CardView->currentIndex().row()] = newCardList.back().surname + " " + newCardList.back().name + " " + newCardList.back().lastname;
	updateCardListModel(cardList);
}

void PersonalCardEditorForm::on_SearchLE_textChanged(const QString &arg1)
{
//	QRegExp exp(".*" + arg1 + ".*");
//	for (int i = 0; i < cardList.size(); ++i)
//		if(exp.exactMatch(cardList[i]))
//			findingCardList.append(cardList[i]);
//	updateCardListModel(findingCardList);
}

void PersonalCardEditorForm::on_OKButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение изменений", "Вы действительно хотите внести сделанные изменения?"))
		return;
	updateCardList(newCardList);
	this->close();
}

void PersonalCardEditorForm::on_CancelButton_clicked()
{
	if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Подтверждение отмены изменений", "Вы действительно хотите отменить сделанные изменения?"))
		return;
	this->close();
}

void PersonalCardEditorForm::on_CardView_clicked(const QModelIndex &index)
{
	const PersonalCard &card = newCardList[index.row()];
	ui->ViewSurnameLE->setText(card.surname);
	ui->ViewNameLE->setText(card.name);
	ui->ViewLastnameLE->setText(card.lastname);
	ui->ViewPostLE->setText(card.post);
	ui->ViewSubdivisionLE->setText(card.subdivision);
	ui->ViewImagePathLE->setText(card.imagePath);
	QPixmap pixmap(card.imagePath);
	ui->label_13->setPixmap(pixmap);

	ui->EditSurnameLE->setText(card.surname);
	ui->EditNameLE->setText(card.name);
	ui->EditLastnameLE->setText(card.lastname);
	ui->EditPostLE->setText(card.post);
	ui->EditSubdivisionLE->setText(card.subdivision);
	ui->EditImagePathLE->setText(card.imagePath);
	ui->label_27->setPixmap(pixmap);
}

void PersonalCardEditorForm::on_AddSelectImageButton_clicked()
{
	QString selfilter = tr("JPEG (*.jpg *.jpeg)");
	QString fileName = QFileDialog::getOpenFileName(
			this,
			"Выбор файла",
			"./",
			tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif)" ),
			&selfilter
	);
	ui->AddImagePathLE->setText(fileName);
	QPixmap pixmap(fileName);
	ui->label_32->setPixmap(pixmap);
}

void PersonalCardEditorForm::on_EditSelectImageButton_clicked()
{
	QString selfilter = tr("JPEG (*.jpg *.jpeg)");
	QString fileName = QFileDialog::getOpenFileName(
			this,
			"Выбор файла",
			"./",
			tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif)" ),
			&selfilter
	);
	ui->EditImagePathLE->setText(fileName);
	QPixmap pixmap(fileName);
	ui->label_27->setPixmap(pixmap);
}
