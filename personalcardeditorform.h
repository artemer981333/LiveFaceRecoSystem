#ifndef PERSONALCARDEDITORFORM_H
#define PERSONALCARDEDITORFORM_H

#include <QWidget>
#include "personalcardmanager.h"

namespace Ui {
class PersonalCardEditorForm;
}

class PersonalCardEditorForm : public QWidget
{
	Q_OBJECT

	PersonalCardManager *manager;

public:
	explicit PersonalCardEditorForm(QWidget *parent = 0);
	~PersonalCardEditorForm();

	void connectCardManager(PersonalCardManager *manager);

public slots:

	void showEvent(QShowEvent *event);

private slots:

	void on_AddCardButton_clicked();

	void on_CardList_currentRowChanged(int currentRow);

private:
	Ui::PersonalCardEditorForm *ui;
};

#endif // PERSONALCARDEDITORFORM_H
