/********************************************************************************
** Form generated from reading UI file 'addvideosourceform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVIDEOSOURCEFORM_H
#define UI_ADDVIDEOSOURCEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddVideoSourceForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *USBButton;
    QRadioButton *RTSPButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QComboBox *CamerasCB;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *IPAddresLE;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *CamNameLE;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *EnteranceRB;
    QRadioButton *ExitRB;
    QCheckBox *AddRele;
    QComboBox *RelesList;
    QSpacerItem *verticalSpacer_3;
    QPushButton *AddButton;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QGridLayout *DeleteableVideoSourcesLayout;

    void setupUi(QWidget *AddVideoSourceForm)
    {
        if (AddVideoSourceForm->objectName().isEmpty())
            AddVideoSourceForm->setObjectName(QStringLiteral("AddVideoSourceForm"));
        AddVideoSourceForm->resize(917, 532);
        horizontalLayout_2 = new QHBoxLayout(AddVideoSourceForm);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(AddVideoSourceForm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        USBButton = new QRadioButton(groupBox);
        USBButton->setObjectName(QStringLiteral("USBButton"));
        USBButton->setChecked(true);

        verticalLayout_5->addWidget(USBButton);

        RTSPButton = new QRadioButton(groupBox);
        RTSPButton->setObjectName(QStringLiteral("RTSPButton"));

        verticalLayout_5->addWidget(RTSPButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_2->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        CamerasCB = new QComboBox(groupBox_5);
        CamerasCB->setObjectName(QStringLiteral("CamerasCB"));

        verticalLayout_8->addWidget(CamerasCB);


        verticalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        IPAddresLE = new QLineEdit(groupBox_6);
        IPAddresLE->setObjectName(QStringLiteral("IPAddresLE"));

        verticalLayout_9->addWidget(IPAddresLE);


        verticalLayout_3->addWidget(groupBox_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        CamNameLE = new QLineEdit(groupBox_3);
        CamNameLE->setObjectName(QStringLiteral("CamNameLE"));

        verticalLayout_4->addWidget(CamNameLE);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        EnteranceRB = new QRadioButton(groupBox_2);
        EnteranceRB->setObjectName(QStringLiteral("EnteranceRB"));
        EnteranceRB->setChecked(true);

        verticalLayout_6->addWidget(EnteranceRB);

        ExitRB = new QRadioButton(groupBox_2);
        ExitRB->setObjectName(QStringLiteral("ExitRB"));

        verticalLayout_6->addWidget(ExitRB);

        AddRele = new QCheckBox(groupBox_2);
        AddRele->setObjectName(QStringLiteral("AddRele"));

        verticalLayout_6->addWidget(AddRele);

        RelesList = new QComboBox(groupBox_2);
        RelesList->setObjectName(QStringLiteral("RelesList"));

        verticalLayout_6->addWidget(RelesList);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_3);

        AddButton = new QPushButton(groupBox_2);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        verticalLayout_6->addWidget(AddButton);


        verticalLayout_4->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(AddVideoSourceForm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DeleteableVideoSourcesLayout = new QGridLayout();
        DeleteableVideoSourcesLayout->setObjectName(QStringLiteral("DeleteableVideoSourcesLayout"));

        verticalLayout->addLayout(DeleteableVideoSourcesLayout);


        horizontalLayout_2->addWidget(groupBox_4);


        retranslateUi(AddVideoSourceForm);

        QMetaObject::connectSlotsByName(AddVideoSourceForm);
    } // setupUi

    void retranslateUi(QWidget *AddVideoSourceForm)
    {
        AddVideoSourceForm->setWindowTitle(QApplication::translate("AddVideoSourceForm", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\320\260\320\274\320\270", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("AddVideoSourceForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AddVideoSourceForm", "\320\237\321\200\320\276\321\202\320\276\320\272\320\276\320\273", Q_NULLPTR));
        USBButton->setText(QApplication::translate("AddVideoSourceForm", "USB", Q_NULLPTR));
        RTSPButton->setText(QApplication::translate("AddVideoSourceForm", "RTSP", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("AddVideoSourceForm", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 USB \320\272\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("AddVideoSourceForm", "IP \320\260\320\264\321\200\320\265\321\201 (\320\261\320\265\320\267 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\320\260)", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddVideoSourceForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        CamNameLE->setPlaceholderText(QApplication::translate("AddVideoSourceForm", "\320\232\320\260\320\274\320\265\321\200\320\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("AddVideoSourceForm", "\320\242\320\270\320\277", Q_NULLPTR));
        EnteranceRB->setText(QApplication::translate("AddVideoSourceForm", "\320\222\321\205\320\276\320\264", Q_NULLPTR));
        ExitRB->setText(QApplication::translate("AddVideoSourceForm", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        AddRele->setText(QApplication::translate("AddVideoSourceForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\273\320\265", Q_NULLPTR));
        AddButton->setText(QApplication::translate("AddVideoSourceForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("AddVideoSourceForm", "\320\220\320\272\321\202\320\270\320\262\320\275\321\213\320\265 \320\272\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddVideoSourceForm: public Ui_AddVideoSourceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVIDEOSOURCEFORM_H
