#ifndef ADDVIDEOSOURCEFORM_H
#define ADDVIDEOSOURCEFORM_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLayout>
#include <QLabel>
#include "devicesmanager.h"

namespace Ui {
class AddVideoSourceForm;
}

class AddVideoSourceForm : public QWidget
{
	Q_OBJECT

	struct DeleteVideoItem
	{
		QGraphicsView *picture;
		QGraphicsScene *scene;
		QGraphicsPixmapItem *pixmap;
		QPushButton *button;
		QVBoxLayout *layout;
		QLabel *label;
		int index;
	};

	QList<DeleteVideoItem> deleteVideoItems;

	void deleteDelVideoItem(int index);

public:
	explicit AddVideoSourceForm(QWidget *parent = 0, DevicesManager *manager = nullptr);
	~AddVideoSourceForm();

public slots:
	void addDeleteableVideoSource(int index, QString name, bool enterance);
	void updatePixmap(QPixmap pixmap, int index);

private slots:
	void on_AddButton_clicked();

	void on_AddRele_clicked(bool checked);

private:
	Ui::AddVideoSourceForm *ui;
	DevicesManager *devicesManager;

signals:
	void videoSourceDeleted(int index);
	void VideoSourceAddedByIndex(int index, QString name, bool enterance, QUuid releID);
	void VideoSourceAddedByPath(const QString &path, QString name, bool enterance, QUuid releID);
};

#endif // ADDVIDEOSOURCEFORM_H
