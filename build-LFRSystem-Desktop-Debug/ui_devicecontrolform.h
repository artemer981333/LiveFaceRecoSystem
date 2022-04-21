/********************************************************************************
** Form generated from reading UI file 'devicecontrolform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONTROLFORM_H
#define UI_DEVICECONTROLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceControlForm
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *AddingTab;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *ReleNameLE;
    QLabel *label_2;
    QLineEdit *QueryLE;
    QPushButton *AddButton;
    QSpacerItem *verticalSpacer;
    QWidget *EditingTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QListView *DevicesList;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLineEdit *EditNameLE;
    QLabel *label_4;
    QLineEdit *EditIDLE;
    QLabel *label_5;
    QLineEdit *EditQueueLE;
    QPushButton *EditButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *OKButton;

    void setupUi(QWidget *DeviceControlForm)
    {
        if (DeviceControlForm->objectName().isEmpty())
            DeviceControlForm->setObjectName(QStringLiteral("DeviceControlForm"));
        DeviceControlForm->resize(900, 514);
        horizontalLayout = new QHBoxLayout(DeviceControlForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(DeviceControlForm);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        AddingTab = new QWidget();
        AddingTab->setObjectName(QStringLiteral("AddingTab"));
        verticalLayout = new QVBoxLayout(AddingTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(AddingTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        ReleNameLE = new QLineEdit(groupBox);
        ReleNameLE->setObjectName(QStringLiteral("ReleNameLE"));

        verticalLayout_2->addWidget(ReleNameLE);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        QueryLE = new QLineEdit(groupBox);
        QueryLE->setObjectName(QStringLiteral("QueryLE"));

        verticalLayout_2->addWidget(QueryLE);

        AddButton = new QPushButton(groupBox);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        verticalLayout_2->addWidget(AddButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);

        tabWidget->addTab(AddingTab, QString());
        EditingTab = new QWidget();
        EditingTab->setObjectName(QStringLiteral("EditingTab"));
        verticalLayout_3 = new QVBoxLayout(EditingTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(EditingTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        DevicesList = new QListView(groupBox_2);
        DevicesList->setObjectName(QStringLiteral("DevicesList"));

        horizontalLayout_2->addWidget(DevicesList);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        EditNameLE = new QLineEdit(groupBox_2);
        EditNameLE->setObjectName(QStringLiteral("EditNameLE"));

        verticalLayout_5->addWidget(EditNameLE);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        EditIDLE = new QLineEdit(groupBox_2);
        EditIDLE->setObjectName(QStringLiteral("EditIDLE"));
        EditIDLE->setReadOnly(true);

        verticalLayout_5->addWidget(EditIDLE);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        EditQueueLE = new QLineEdit(groupBox_2);
        EditQueueLE->setObjectName(QStringLiteral("EditQueueLE"));

        verticalLayout_5->addWidget(EditQueueLE);

        EditButton = new QPushButton(groupBox_2);
        EditButton->setObjectName(QStringLiteral("EditButton"));

        verticalLayout_5->addWidget(EditButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        OKButton = new QPushButton(groupBox_2);
        OKButton->setObjectName(QStringLiteral("OKButton"));

        verticalLayout_5->addWidget(OKButton);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_3->addWidget(groupBox_2);

        tabWidget->addTab(EditingTab, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(DeviceControlForm);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DeviceControlForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceControlForm)
    {
        DeviceControlForm->setWindowTitle(QApplication::translate("DeviceControlForm", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DeviceControlForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\273\320\265", Q_NULLPTR));
        label->setText(QApplication::translate("DeviceControlForm", "\320\230\320\274\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("DeviceControlForm", "\320\242\320\265\320\272\321\201\321\202 \320\267\320\260\320\277\321\200\320\276\321\201\320\260 \320\275\320\260 \320\276\321\202\320\272\321\200\321\213\321\202\320\270\320\265", Q_NULLPTR));
        AddButton->setText(QApplication::translate("DeviceControlForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\273\320\265", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AddingTab), QApplication::translate("DeviceControlForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DeviceControlForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262", Q_NULLPTR));
        label_3->setText(QApplication::translate("DeviceControlForm", "\320\230\320\274\321\217 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("DeviceControlForm", "ID \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("DeviceControlForm", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", Q_NULLPTR));
        EditButton->setText(QApplication::translate("DeviceControlForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        OKButton->setText(QApplication::translate("DeviceControlForm", "\320\236\320\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(EditingTab), QApplication::translate("DeviceControlForm", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260\320\274\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeviceControlForm: public Ui_DeviceControlForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONTROLFORM_H
