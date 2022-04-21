/********************************************************************************
** Form generated from reading UI file 'makephotoform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEPHOTOFORM_H
#define UI_MAKEPHOTOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakePhotoForm
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *PhotoView;
    QLineEdit *FilenameLE;
    QPushButton *OKButton;

    void setupUi(QWidget *MakePhotoForm)
    {
        if (MakePhotoForm->objectName().isEmpty())
            MakePhotoForm->setObjectName(QStringLiteral("MakePhotoForm"));
        MakePhotoForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(MakePhotoForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        PhotoView = new QGraphicsView(MakePhotoForm);
        PhotoView->setObjectName(QStringLiteral("PhotoView"));

        verticalLayout->addWidget(PhotoView);

        FilenameLE = new QLineEdit(MakePhotoForm);
        FilenameLE->setObjectName(QStringLiteral("FilenameLE"));
        FilenameLE->setClearButtonEnabled(false);

        verticalLayout->addWidget(FilenameLE);

        OKButton = new QPushButton(MakePhotoForm);
        OKButton->setObjectName(QStringLiteral("OKButton"));

        verticalLayout->addWidget(OKButton);


        retranslateUi(MakePhotoForm);

        QMetaObject::connectSlotsByName(MakePhotoForm);
    } // setupUi

    void retranslateUi(QWidget *MakePhotoForm)
    {
        MakePhotoForm->setWindowTitle(QApplication::translate("MakePhotoForm", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\276\321\202\320\276", Q_NULLPTR));
        FilenameLE->setPlaceholderText(QApplication::translate("MakePhotoForm", "Name_Surname", Q_NULLPTR));
        OKButton->setText(QApplication::translate("MakePhotoForm", "\320\236\320\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MakePhotoForm: public Ui_MakePhotoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEPHOTOFORM_H
