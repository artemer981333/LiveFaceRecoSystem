#include "makephotoform.h"
#include "ui_makephotoform.h"
#include <QFileDialog>
#include <QPixmap>
#include <QRect>

MakePhotoForm::MakePhotoForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MakePhotoForm)
{
	ui->setupUi(this);

	pixmap = new QGraphicsPixmapItem;
	scene = new QGraphicsScene;

	scene->addItem(pixmap);
	ui->PhotoView->setScene(scene);
}

MakePhotoForm::~MakePhotoForm()
{
	delete pixmap;
	delete scene;
	delete ui;
}

void MakePhotoForm::updatePixmap(QPixmap mPixmap)
{
	QPixmap &pix = mPixmap;
	QRect rect((pix.width() - pix.height()) / 2, 0, pix.height(), pix.height());
	pix = pix.copy(rect);
	pixmap->setPixmap(pix);
	ui->PhotoView->fitInView(pixmap, Qt::KeepAspectRatio);
}

void MakePhotoForm::on_OKButton_clicked()
{
	QString filename = QFileDialog::getSaveFileName(
				this,
				"Сохранение...",
				"./"
				);
	if (filename.isNull() || filename.isEmpty())
		return;
	QFile file(filename);
	file.open(QIODevice::WriteOnly);
//	QPixmap pix = pixmap->pixmap();
//	QRect rect((pix.width() - pix.height()) / 2, pix.height(), pix.width() - (pix.width() - pix.height()) / 2, 0);
//	pix = pix.copy(rect);
//	pix = pix.scaled(QSize(112, 112), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	QPixmap pix = pixmap->pixmap().scaled(QSize(112, 112), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	pix.save(&file, "jpeg");
}
