#include "makephotoform.h"
#include "ui_makephotoform.h"
#include <QFile>
#include <QMessageBox>
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

void MakePhotoForm::updatePixmap(QPixmap mPixmap, int index)
{
	if (index != 0)
		return;
	QPixmap &pix = mPixmap;
	QRect rect((pix.width() - pix.height()) / 2, 0, pix.height(), pix.height());
	pix = pix.copy(rect);
	pixmap->setPixmap(pix);
	ui->PhotoView->fitInView(pixmap, Qt::KeepAspectRatio);
}

void MakePhotoForm::on_OKButton_clicked()
{
	if (ui->FilenameLE->text().length() == 0)
		QMessageBox::information(this, "Введите название файла", "Введите название файла");
	QFile file("./img/" + ui->FilenameLE->text() + ".jpg");
	if (file.exists())
		if (QMessageBox::StandardButton::Cancel == QMessageBox::question(this, "Файл уже существует", "Данный файл уже существует. Заменить?"))
			return;
	file.open(QIODevice::WriteOnly);
	QPixmap pix = pixmap->pixmap().scaled(QSize(112, 112), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	pix.save(&file, "jpeg");
	QMessageBox::information(this, "Сохранено", "Сохранено");
}
