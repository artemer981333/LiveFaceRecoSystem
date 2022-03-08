#ifndef MAKEPHOTOFORM_H
#define MAKEPHOTOFORM_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsPixmapItem>

namespace Ui {
class MakePhotoForm;
}

class MakePhotoForm : public QWidget
{
	Q_OBJECT

	QGraphicsScene *scene;
	QGraphicsPixmapItem *pixmap;

public:
	explicit MakePhotoForm(QWidget *parent = 0);
	~MakePhotoForm();

public slots:
	void updatePixmap(QPixmap mPixmap);

private slots:
	void on_OKButton_clicked();

private:
	Ui::MakePhotoForm *ui;
};

#endif // MAKEPHOTOFORM_H
