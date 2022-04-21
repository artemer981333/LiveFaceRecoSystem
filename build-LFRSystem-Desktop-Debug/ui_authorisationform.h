/********************************************************************************
** Form generated from reading UI file 'authorisationform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORISATIONFORM_H
#define UI_AUTHORISATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorisationForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *LoginLE;
    QLabel *label_2;
    QLineEdit *PasswordLE;
    QPushButton *pushButton;

    void setupUi(QWidget *AuthorisationForm)
    {
        if (AuthorisationForm->objectName().isEmpty())
            AuthorisationForm->setObjectName(QStringLiteral("AuthorisationForm"));
        AuthorisationForm->resize(300, 151);
        AuthorisationForm->setMinimumSize(QSize(300, 151));
        AuthorisationForm->setMaximumSize(QSize(300, 151));
        verticalLayout = new QVBoxLayout(AuthorisationForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AuthorisationForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        LoginLE = new QLineEdit(AuthorisationForm);
        LoginLE->setObjectName(QStringLiteral("LoginLE"));

        verticalLayout->addWidget(LoginLE);

        label_2 = new QLabel(AuthorisationForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        PasswordLE = new QLineEdit(AuthorisationForm);
        PasswordLE->setObjectName(QStringLiteral("PasswordLE"));

        verticalLayout->addWidget(PasswordLE);

        pushButton = new QPushButton(AuthorisationForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(AuthorisationForm);

        QMetaObject::connectSlotsByName(AuthorisationForm);
    } // setupUi

    void retranslateUi(QWidget *AuthorisationForm)
    {
        AuthorisationForm->setWindowTitle(QApplication::translate("AuthorisationForm", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("AuthorisationForm", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        label_2->setText(QApplication::translate("AuthorisationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AuthorisationForm", "\320\222\320\276\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthorisationForm: public Ui_AuthorisationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORISATIONFORM_H
