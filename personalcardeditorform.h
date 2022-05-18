#ifndef PERSONALCARDEDITORFORM_H
#define PERSONALCARDEDITORFORM_H

#include <QWidget>
#include <QStringListModel>
#include "personalcardmanager.h"
#include <opencv2/opencv.hpp>

namespace Ui {
class PersonalCardEditorForm;
}

class PersonalCardEditorForm : public QWidget
{
	Q_OBJECT

	PersonalCardManager *manager;

	QStringList cardList, findingCardList;
	QStringListModel *listModel;
	QList<PersonalCard> newCardList;

	cv::Mat addPic, editPic;

	void updateCardListModel(const QStringList &list);

public:
	explicit PersonalCardEditorForm(QWidget *parent = 0);
	~PersonalCardEditorForm();

	void connectCardManager(PersonalCardManager *manager);

signals:
	void updateCardList(QList<PersonalCard> cards);

public slots:
	void showEvent(QShowEvent *event);

private slots:
	void on_AddCardButton_clicked();
	void on_EditCardButton_clicked();
	void on_SearchLE_textChanged(const QString &arg1);
	void on_OKButton_clicked();
	void on_CancelButton_clicked();
	void on_AddSelectImageButton_clicked();
	void on_EditSelectImageButton_clicked();
	void on_DeleteCardButton_clicked();
	void on_ClearButton_clicked();
	void on_CardView_clicked(const QModelIndex &index);

	void on_EditBrightnessSlider_actionTriggered(int action);

	void on_EditContrastSlider_actionTriggered(int action);

	void on_AddBrightnessSlider_actionTriggered(int action);

	void on_AddContrastSlider_actionTriggered(int action);

private:
	Ui::PersonalCardEditorForm *ui;
};

#endif // PERSONALCARDEDITORFORM_H
