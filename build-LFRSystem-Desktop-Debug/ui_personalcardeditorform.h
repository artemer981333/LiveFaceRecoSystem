/********************************************************************************
** Form generated from reading UI file 'personalcardeditorform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALCARDEDITORFORM_H
#define UI_PERSONALCARDEDITORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalCardEditorForm
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *CardsViewLayout;
    QHBoxLayout *SearchLayout;
    QLabel *label;
    QLineEdit *SearchLE;
    QListView *CardView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *CardLayout;
    QTabWidget *tabWidget;
    QWidget *ViewTab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QLineEdit *ViewSurnameLE;
    QLabel *label_11;
    QLineEdit *ViewNameLE;
    QLabel *label_14;
    QLineEdit *ViewLastnameLE;
    QLabel *label_10;
    QLineEdit *ViewPostLE;
    QLabel *label_8;
    QLineEdit *ViewSubdivisionLE;
    QLabel *label_12;
    QLineEdit *ViewImagePathLE;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QWidget *EditTab;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_23;
    QLineEdit *EditSurnameLE;
    QLabel *label_25;
    QLineEdit *EditNameLE;
    QLabel *label_28;
    QLineEdit *EditLastnameLE;
    QLabel *label_24;
    QLineEdit *EditPostLE;
    QLabel *label_22;
    QLineEdit *EditSubdivisionLE;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *EditSelectImageButton;
    QLineEdit *EditImagePathLE;
    QLabel *label_27;
    QSlider *EditBrightnessSlider;
    QSlider *EditContrastSlider;
    QPushButton *EditCardButton;
    QPushButton *DeleteCardButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *AddTab;
    QVBoxLayout *verticalLayout_5;
    QPushButton *ClearButton;
    QLabel *label_35;
    QLineEdit *AddSurnameLE;
    QLabel *label_34;
    QLineEdit *AddNameLE;
    QLabel *label_33;
    QLineEdit *AddLastnameLE;
    QLabel *label_30;
    QLineEdit *AddPostLE;
    QLabel *label_29;
    QLineEdit *AddSubdivisionLE;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddSelectImageButton;
    QLineEdit *AddImagePathLE;
    QLabel *label_32;
    QSlider *AddBrightnessSlider;
    QSlider *AddContrastSlider;
    QPushButton *AddCardButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *CancelButton;
    QPushButton *OKButton;

    void setupUi(QWidget *PersonalCardEditorForm)
    {
        if (PersonalCardEditorForm->objectName().isEmpty())
            PersonalCardEditorForm->setObjectName(QStringLiteral("PersonalCardEditorForm"));
        PersonalCardEditorForm->resize(915, 575);
        PersonalCardEditorForm->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(PersonalCardEditorForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(PersonalCardEditorForm);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        CardsViewLayout = new QVBoxLayout(verticalLayoutWidget);
        CardsViewLayout->setObjectName(QStringLiteral("CardsViewLayout"));
        CardsViewLayout->setContentsMargins(0, 0, 0, 0);
        SearchLayout = new QHBoxLayout();
        SearchLayout->setObjectName(QStringLiteral("SearchLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        SearchLayout->addWidget(label);

        SearchLE = new QLineEdit(verticalLayoutWidget);
        SearchLE->setObjectName(QStringLiteral("SearchLE"));

        SearchLayout->addWidget(SearchLE);


        CardsViewLayout->addLayout(SearchLayout);

        CardView = new QListView(verticalLayoutWidget);
        CardView->setObjectName(QStringLiteral("CardView"));
        CardView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        CardsViewLayout->addWidget(CardView);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        CardLayout = new QVBoxLayout(verticalLayoutWidget_2);
        CardLayout->setObjectName(QStringLiteral("CardLayout"));
        CardLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        ViewTab = new QWidget();
        ViewTab->setObjectName(QStringLiteral("ViewTab"));
        verticalLayout_2 = new QVBoxLayout(ViewTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_9 = new QLabel(ViewTab);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        ViewSurnameLE = new QLineEdit(ViewTab);
        ViewSurnameLE->setObjectName(QStringLiteral("ViewSurnameLE"));

        verticalLayout_2->addWidget(ViewSurnameLE);

        label_11 = new QLabel(ViewTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        ViewNameLE = new QLineEdit(ViewTab);
        ViewNameLE->setObjectName(QStringLiteral("ViewNameLE"));

        verticalLayout_2->addWidget(ViewNameLE);

        label_14 = new QLabel(ViewTab);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_2->addWidget(label_14);

        ViewLastnameLE = new QLineEdit(ViewTab);
        ViewLastnameLE->setObjectName(QStringLiteral("ViewLastnameLE"));

        verticalLayout_2->addWidget(ViewLastnameLE);

        label_10 = new QLabel(ViewTab);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        ViewPostLE = new QLineEdit(ViewTab);
        ViewPostLE->setObjectName(QStringLiteral("ViewPostLE"));

        verticalLayout_2->addWidget(ViewPostLE);

        label_8 = new QLabel(ViewTab);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        ViewSubdivisionLE = new QLineEdit(ViewTab);
        ViewSubdivisionLE->setObjectName(QStringLiteral("ViewSubdivisionLE"));

        verticalLayout_2->addWidget(ViewSubdivisionLE);

        label_12 = new QLabel(ViewTab);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        ViewImagePathLE = new QLineEdit(ViewTab);
        ViewImagePathLE->setObjectName(QStringLiteral("ViewImagePathLE"));

        verticalLayout_2->addWidget(ViewImagePathLE);

        label_13 = new QLabel(ViewTab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setEnabled(true);
        label_13->setScaledContents(false);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(label_13);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(ViewTab, QString());
        EditTab = new QWidget();
        EditTab->setObjectName(QStringLiteral("EditTab"));
        verticalLayout_4 = new QVBoxLayout(EditTab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_23 = new QLabel(EditTab);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_4->addWidget(label_23);

        EditSurnameLE = new QLineEdit(EditTab);
        EditSurnameLE->setObjectName(QStringLiteral("EditSurnameLE"));

        verticalLayout_4->addWidget(EditSurnameLE);

        label_25 = new QLabel(EditTab);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_4->addWidget(label_25);

        EditNameLE = new QLineEdit(EditTab);
        EditNameLE->setObjectName(QStringLiteral("EditNameLE"));

        verticalLayout_4->addWidget(EditNameLE);

        label_28 = new QLabel(EditTab);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout_4->addWidget(label_28);

        EditLastnameLE = new QLineEdit(EditTab);
        EditLastnameLE->setObjectName(QStringLiteral("EditLastnameLE"));

        verticalLayout_4->addWidget(EditLastnameLE);

        label_24 = new QLabel(EditTab);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_4->addWidget(label_24);

        EditPostLE = new QLineEdit(EditTab);
        EditPostLE->setObjectName(QStringLiteral("EditPostLE"));

        verticalLayout_4->addWidget(EditPostLE);

        label_22 = new QLabel(EditTab);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_4->addWidget(label_22);

        EditSubdivisionLE = new QLineEdit(EditTab);
        EditSubdivisionLE->setObjectName(QStringLiteral("EditSubdivisionLE"));

        verticalLayout_4->addWidget(EditSubdivisionLE);

        label_26 = new QLabel(EditTab);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout_4->addWidget(label_26);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        EditSelectImageButton = new QPushButton(EditTab);
        EditSelectImageButton->setObjectName(QStringLiteral("EditSelectImageButton"));

        horizontalLayout_4->addWidget(EditSelectImageButton);

        EditImagePathLE = new QLineEdit(EditTab);
        EditImagePathLE->setObjectName(QStringLiteral("EditImagePathLE"));

        horizontalLayout_4->addWidget(EditImagePathLE);


        verticalLayout_4->addLayout(horizontalLayout_4);

        label_27 = new QLabel(EditTab);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setEnabled(true);
        label_27->setScaledContents(false);
        label_27->setAlignment(Qt::AlignCenter);
        label_27->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_4->addWidget(label_27);

        EditBrightnessSlider = new QSlider(EditTab);
        EditBrightnessSlider->setObjectName(QStringLiteral("EditBrightnessSlider"));
        EditBrightnessSlider->setMinimum(-200);
        EditBrightnessSlider->setMaximum(200);
        EditBrightnessSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(EditBrightnessSlider);

        EditContrastSlider = new QSlider(EditTab);
        EditContrastSlider->setObjectName(QStringLiteral("EditContrastSlider"));
        EditContrastSlider->setMinimum(1);
        EditContrastSlider->setMaximum(400);
        EditContrastSlider->setValue(100);
        EditContrastSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(EditContrastSlider);

        EditCardButton = new QPushButton(EditTab);
        EditCardButton->setObjectName(QStringLiteral("EditCardButton"));

        verticalLayout_4->addWidget(EditCardButton);

        DeleteCardButton = new QPushButton(EditTab);
        DeleteCardButton->setObjectName(QStringLiteral("DeleteCardButton"));

        verticalLayout_4->addWidget(DeleteCardButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabWidget->addTab(EditTab, QString());
        AddTab = new QWidget();
        AddTab->setObjectName(QStringLiteral("AddTab"));
        verticalLayout_5 = new QVBoxLayout(AddTab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        ClearButton = new QPushButton(AddTab);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));

        verticalLayout_5->addWidget(ClearButton);

        label_35 = new QLabel(AddTab);
        label_35->setObjectName(QStringLiteral("label_35"));

        verticalLayout_5->addWidget(label_35);

        AddSurnameLE = new QLineEdit(AddTab);
        AddSurnameLE->setObjectName(QStringLiteral("AddSurnameLE"));

        verticalLayout_5->addWidget(AddSurnameLE);

        label_34 = new QLabel(AddTab);
        label_34->setObjectName(QStringLiteral("label_34"));

        verticalLayout_5->addWidget(label_34);

        AddNameLE = new QLineEdit(AddTab);
        AddNameLE->setObjectName(QStringLiteral("AddNameLE"));

        verticalLayout_5->addWidget(AddNameLE);

        label_33 = new QLabel(AddTab);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_5->addWidget(label_33);

        AddLastnameLE = new QLineEdit(AddTab);
        AddLastnameLE->setObjectName(QStringLiteral("AddLastnameLE"));

        verticalLayout_5->addWidget(AddLastnameLE);

        label_30 = new QLabel(AddTab);
        label_30->setObjectName(QStringLiteral("label_30"));

        verticalLayout_5->addWidget(label_30);

        AddPostLE = new QLineEdit(AddTab);
        AddPostLE->setObjectName(QStringLiteral("AddPostLE"));

        verticalLayout_5->addWidget(AddPostLE);

        label_29 = new QLabel(AddTab);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_5->addWidget(label_29);

        AddSubdivisionLE = new QLineEdit(AddTab);
        AddSubdivisionLE->setObjectName(QStringLiteral("AddSubdivisionLE"));

        verticalLayout_5->addWidget(AddSubdivisionLE);

        label_31 = new QLabel(AddTab);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout_5->addWidget(label_31);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AddSelectImageButton = new QPushButton(AddTab);
        AddSelectImageButton->setObjectName(QStringLiteral("AddSelectImageButton"));

        horizontalLayout_2->addWidget(AddSelectImageButton);

        AddImagePathLE = new QLineEdit(AddTab);
        AddImagePathLE->setObjectName(QStringLiteral("AddImagePathLE"));

        horizontalLayout_2->addWidget(AddImagePathLE);


        verticalLayout_5->addLayout(horizontalLayout_2);

        label_32 = new QLabel(AddTab);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setEnabled(true);
        label_32->setScaledContents(false);
        label_32->setAlignment(Qt::AlignCenter);
        label_32->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_5->addWidget(label_32);

        AddBrightnessSlider = new QSlider(AddTab);
        AddBrightnessSlider->setObjectName(QStringLiteral("AddBrightnessSlider"));
        AddBrightnessSlider->setMinimum(-200);
        AddBrightnessSlider->setMaximum(200);
        AddBrightnessSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(AddBrightnessSlider);

        AddContrastSlider = new QSlider(AddTab);
        AddContrastSlider->setObjectName(QStringLiteral("AddContrastSlider"));
        AddContrastSlider->setMinimum(1);
        AddContrastSlider->setMaximum(400);
        AddContrastSlider->setValue(100);
        AddContrastSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(AddContrastSlider);

        AddCardButton = new QPushButton(AddTab);
        AddCardButton->setObjectName(QStringLiteral("AddCardButton"));

        verticalLayout_5->addWidget(AddCardButton);

        verticalSpacer_3 = new QSpacerItem(20, 125, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        tabWidget->addTab(AddTab, QString());

        CardLayout->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CancelButton = new QPushButton(verticalLayoutWidget_2);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_3->addWidget(CancelButton);

        OKButton = new QPushButton(verticalLayoutWidget_2);
        OKButton->setObjectName(QStringLiteral("OKButton"));

        horizontalLayout_3->addWidget(OKButton);


        CardLayout->addLayout(horizontalLayout_3);

        splitter->addWidget(verticalLayoutWidget_2);

        horizontalLayout->addWidget(splitter);


        retranslateUi(PersonalCardEditorForm);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PersonalCardEditorForm);
    } // setupUi

    void retranslateUi(QWidget *PersonalCardEditorForm)
    {
        PersonalCardEditorForm->setWindowTitle(QApplication::translate("PersonalCardEditorForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\272\320\260\321\200\321\202", Q_NULLPTR));
        label->setText(QApplication::translate("PersonalCardEditorForm", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        label_9->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("PersonalCardEditorForm", "\320\230\320\274\321\217", Q_NULLPTR));
        label_14->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_10->setText(QApplication::translate("PersonalCardEditorForm", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_8->setText(QApplication::translate("PersonalCardEditorForm", "\320\237\320\276\320\264\321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_12->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\276\321\202\320\276", Q_NULLPTR));
        label_13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(ViewTab), QApplication::translate("PersonalCardEditorForm", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", Q_NULLPTR));
        label_23->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_25->setText(QApplication::translate("PersonalCardEditorForm", "\320\230\320\274\321\217", Q_NULLPTR));
        label_28->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_24->setText(QApplication::translate("PersonalCardEditorForm", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_22->setText(QApplication::translate("PersonalCardEditorForm", "\320\237\320\276\320\264\321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_26->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\276\321\202\320\276", Q_NULLPTR));
        EditSelectImageButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", Q_NULLPTR));
        label_27->setText(QString());
        EditCardButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        DeleteCardButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(EditTab), QApplication::translate("PersonalCardEditorForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        ClearButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        label_35->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_34->setText(QApplication::translate("PersonalCardEditorForm", "\320\230\320\274\321\217", Q_NULLPTR));
        label_33->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_30->setText(QApplication::translate("PersonalCardEditorForm", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_29->setText(QApplication::translate("PersonalCardEditorForm", "\320\237\320\276\320\264\321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_31->setText(QApplication::translate("PersonalCardEditorForm", "\320\244\320\276\321\202\320\276", Q_NULLPTR));
        AddSelectImageButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", Q_NULLPTR));
        label_32->setText(QString());
        AddCardButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AddTab), QApplication::translate("PersonalCardEditorForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        OKButton->setText(QApplication::translate("PersonalCardEditorForm", "\320\236\320\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PersonalCardEditorForm: public Ui_PersonalCardEditorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALCARDEDITORFORM_H
