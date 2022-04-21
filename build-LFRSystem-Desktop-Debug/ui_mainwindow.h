/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *OpenPersonalCardEditor;
    QAction *MakePhoto;
    QAction *CameraControlAction;
    QAction *DeviceControlAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *VideoLayout1;
    QHBoxLayout *VideoLayout2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout;
    QLabel *CardDT1;
    QLabel *CardDT4;
    QLabel *CardCam1;
    QFrame *line_10;
    QLabel *CardCam3;
    QLabel *CardDT2;
    QLabel *CardPic1;
    QLabel *CardPic2;
    QLabel *CardFIO5;
    QFrame *line_3;
    QLabel *CardPic3;
    QLabel *CardFIO3;
    QLabel *CardFIO2;
    QFrame *line_2;
    QLabel *CardFIO4;
    QLabel *CardPic4;
    QFrame *line;
    QLabel *CardPic5;
    QFrame *line_4;
    QLabel *CardCam4;
    QFrame *line_23;
    QFrame *line_21;
    QFrame *line_22;
    QFrame *line_12;
    QFrame *line_11;
    QFrame *line_24;
    QFrame *line_9;
    QLabel *CardFIO1;
    QLabel *CardCam5;
    QLabel *CardDT5;
    QLabel *CardCam2;
    QLabel *CardDT3;
    QFrame *line_25;
    QFrame *line_26;
    QFrame *line_27;
    QFrame *line_28;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *Repass;
    QLabel *RealFaceLabel;
    QLabel *label_6;
    QLineEdit *ConfidenceLE;
    QLabel *label_8;
    QLineEdit *SimilarityLE;
    QLabel *label_9;
    QLineEdit *EnteredLE;
    QLabel *label_10;
    QLineEdit *ExitedLE;
    QLabel *label_11;
    QLineEdit *NowLE;
    QCheckBox *SpuffingCB;
    QLabel *LicenseLabel;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(953, 719);
        OpenPersonalCardEditor = new QAction(MainWindow);
        OpenPersonalCardEditor->setObjectName(QStringLiteral("OpenPersonalCardEditor"));
        MakePhoto = new QAction(MainWindow);
        MakePhoto->setObjectName(QStringLiteral("MakePhoto"));
        CameraControlAction = new QAction(MainWindow);
        CameraControlAction->setObjectName(QStringLiteral("CameraControlAction"));
        DeviceControlAction = new QAction(MainWindow);
        DeviceControlAction->setObjectName(QStringLiteral("DeviceControlAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        VideoLayout1 = new QHBoxLayout();
        VideoLayout1->setSpacing(6);
        VideoLayout1->setObjectName(QStringLiteral("VideoLayout1"));

        verticalLayout_5->addLayout(VideoLayout1);

        VideoLayout2 = new QHBoxLayout();
        VideoLayout2->setSpacing(6);
        VideoLayout2->setObjectName(QStringLiteral("VideoLayout2"));

        verticalLayout_5->addLayout(VideoLayout2);


        verticalLayout_4->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CardDT1 = new QLabel(groupBox);
        CardDT1->setObjectName(QStringLiteral("CardDT1"));

        gridLayout->addWidget(CardDT1, 0, 2, 1, 1);

        CardDT4 = new QLabel(groupBox);
        CardDT4->setObjectName(QStringLiteral("CardDT4"));

        gridLayout->addWidget(CardDT4, 8, 2, 1, 1);

        CardCam1 = new QLabel(groupBox);
        CardCam1->setObjectName(QStringLiteral("CardCam1"));

        gridLayout->addWidget(CardCam1, 0, 3, 1, 1);

        line_10 = new QFrame(groupBox);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_10, 3, 1, 1, 1);

        CardCam3 = new QLabel(groupBox);
        CardCam3->setObjectName(QStringLiteral("CardCam3"));

        gridLayout->addWidget(CardCam3, 6, 3, 1, 1);

        CardDT2 = new QLabel(groupBox);
        CardDT2->setObjectName(QStringLiteral("CardDT2"));

        gridLayout->addWidget(CardDT2, 2, 2, 1, 1);

        CardPic1 = new QLabel(groupBox);
        CardPic1->setObjectName(QStringLiteral("CardPic1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CardPic1->sizePolicy().hasHeightForWidth());
        CardPic1->setSizePolicy(sizePolicy);
        CardPic1->setScaledContents(false);

        gridLayout->addWidget(CardPic1, 0, 0, 1, 1);

        CardPic2 = new QLabel(groupBox);
        CardPic2->setObjectName(QStringLiteral("CardPic2"));
        sizePolicy.setHeightForWidth(CardPic2->sizePolicy().hasHeightForWidth());
        CardPic2->setSizePolicy(sizePolicy);
        CardPic2->setScaledContents(false);

        gridLayout->addWidget(CardPic2, 2, 0, 1, 1);

        CardFIO5 = new QLabel(groupBox);
        CardFIO5->setObjectName(QStringLiteral("CardFIO5"));

        gridLayout->addWidget(CardFIO5, 10, 1, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_3, 1, 2, 1, 1);

        CardPic3 = new QLabel(groupBox);
        CardPic3->setObjectName(QStringLiteral("CardPic3"));
        sizePolicy.setHeightForWidth(CardPic3->sizePolicy().hasHeightForWidth());
        CardPic3->setSizePolicy(sizePolicy);
        CardPic3->setScaledContents(false);

        gridLayout->addWidget(CardPic3, 6, 0, 1, 1);

        CardFIO3 = new QLabel(groupBox);
        CardFIO3->setObjectName(QStringLiteral("CardFIO3"));

        gridLayout->addWidget(CardFIO3, 6, 1, 1, 1);

        CardFIO2 = new QLabel(groupBox);
        CardFIO2->setObjectName(QStringLiteral("CardFIO2"));

        gridLayout->addWidget(CardFIO2, 2, 1, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_2, 1, 1, 1, 1);

        CardFIO4 = new QLabel(groupBox);
        CardFIO4->setObjectName(QStringLiteral("CardFIO4"));

        gridLayout->addWidget(CardFIO4, 8, 1, 1, 1);

        CardPic4 = new QLabel(groupBox);
        CardPic4->setObjectName(QStringLiteral("CardPic4"));
        sizePolicy.setHeightForWidth(CardPic4->sizePolicy().hasHeightForWidth());
        CardPic4->setSizePolicy(sizePolicy);
        CardPic4->setScaledContents(false);

        gridLayout->addWidget(CardPic4, 8, 0, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        CardPic5 = new QLabel(groupBox);
        CardPic5->setObjectName(QStringLiteral("CardPic5"));
        sizePolicy.setHeightForWidth(CardPic5->sizePolicy().hasHeightForWidth());
        CardPic5->setSizePolicy(sizePolicy);
        CardPic5->setScaledContents(false);

        gridLayout->addWidget(CardPic5, 10, 0, 1, 1);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_4, 1, 3, 1, 1);

        CardCam4 = new QLabel(groupBox);
        CardCam4->setObjectName(QStringLiteral("CardCam4"));

        gridLayout->addWidget(CardCam4, 8, 3, 1, 1);

        line_23 = new QFrame(groupBox);
        line_23->setObjectName(QStringLiteral("line_23"));
        line_23->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_23->setFrameShadow(QFrame::Plain);
        line_23->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_23, 7, 2, 1, 1);

        line_21 = new QFrame(groupBox);
        line_21->setObjectName(QStringLiteral("line_21"));
        line_21->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_21->setFrameShadow(QFrame::Plain);
        line_21->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_21, 7, 0, 1, 1);

        line_22 = new QFrame(groupBox);
        line_22->setObjectName(QStringLiteral("line_22"));
        line_22->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_22->setFrameShadow(QFrame::Plain);
        line_22->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_22, 7, 1, 1, 1);

        line_12 = new QFrame(groupBox);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_12->setFrameShadow(QFrame::Plain);
        line_12->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_12, 3, 3, 1, 1);

        line_11 = new QFrame(groupBox);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_11->setFrameShadow(QFrame::Plain);
        line_11->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_11, 3, 2, 1, 1);

        line_24 = new QFrame(groupBox);
        line_24->setObjectName(QStringLiteral("line_24"));
        line_24->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_24->setFrameShadow(QFrame::Plain);
        line_24->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_24, 7, 3, 1, 1);

        line_9 = new QFrame(groupBox);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_9, 3, 0, 1, 1);

        CardFIO1 = new QLabel(groupBox);
        CardFIO1->setObjectName(QStringLiteral("CardFIO1"));

        gridLayout->addWidget(CardFIO1, 0, 1, 1, 1);

        CardCam5 = new QLabel(groupBox);
        CardCam5->setObjectName(QStringLiteral("CardCam5"));

        gridLayout->addWidget(CardCam5, 10, 3, 1, 1);

        CardDT5 = new QLabel(groupBox);
        CardDT5->setObjectName(QStringLiteral("CardDT5"));

        gridLayout->addWidget(CardDT5, 10, 2, 1, 1);

        CardCam2 = new QLabel(groupBox);
        CardCam2->setObjectName(QStringLiteral("CardCam2"));

        gridLayout->addWidget(CardCam2, 2, 3, 1, 1);

        CardDT3 = new QLabel(groupBox);
        CardDT3->setObjectName(QStringLiteral("CardDT3"));

        gridLayout->addWidget(CardDT3, 6, 2, 1, 1);

        line_25 = new QFrame(groupBox);
        line_25->setObjectName(QStringLiteral("line_25"));
        line_25->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_25->setFrameShadow(QFrame::Plain);
        line_25->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_25, 9, 0, 1, 1);

        line_26 = new QFrame(groupBox);
        line_26->setObjectName(QStringLiteral("line_26"));
        line_26->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_26->setFrameShadow(QFrame::Plain);
        line_26->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_26, 9, 1, 1, 1);

        line_27 = new QFrame(groupBox);
        line_27->setObjectName(QStringLiteral("line_27"));
        line_27->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_27->setFrameShadow(QFrame::Plain);
        line_27->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_27, 9, 2, 1, 1);

        line_28 = new QFrame(groupBox);
        line_28->setObjectName(QStringLiteral("line_28"));
        line_28->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        line_28->setFrameShadow(QFrame::Plain);
        line_28->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_28, 9, 3, 1, 1);


        verticalLayout_7->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox);

        verticalLayout_4->setStretch(0, 4);
        verticalLayout_4->setStretch(1, 6);
        splitter->addWidget(verticalLayoutWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setAcceptDrops(false);

        verticalLayout_6->addWidget(plainTextEdit);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(-200);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalSlider_2 = new QSlider(groupBox_3);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        Repass = new QLabel(groupBox_3);
        Repass->setObjectName(QStringLiteral("Repass"));

        verticalLayout_2->addWidget(Repass);

        RealFaceLabel = new QLabel(groupBox_3);
        RealFaceLabel->setObjectName(QStringLiteral("RealFaceLabel"));

        verticalLayout_2->addWidget(RealFaceLabel);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        ConfidenceLE = new QLineEdit(groupBox_3);
        ConfidenceLE->setObjectName(QStringLiteral("ConfidenceLE"));
        ConfidenceLE->setReadOnly(true);

        verticalLayout_2->addWidget(ConfidenceLE);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        SimilarityLE = new QLineEdit(groupBox_3);
        SimilarityLE->setObjectName(QStringLiteral("SimilarityLE"));
        SimilarityLE->setReadOnly(true);

        verticalLayout_2->addWidget(SimilarityLE);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        EnteredLE = new QLineEdit(groupBox_3);
        EnteredLE->setObjectName(QStringLiteral("EnteredLE"));
        EnteredLE->setReadOnly(true);

        verticalLayout_2->addWidget(EnteredLE);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        ExitedLE = new QLineEdit(groupBox_3);
        ExitedLE->setObjectName(QStringLiteral("ExitedLE"));
        ExitedLE->setReadOnly(true);

        verticalLayout_2->addWidget(ExitedLE);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        NowLE = new QLineEdit(groupBox_3);
        NowLE->setObjectName(QStringLiteral("NowLE"));
        NowLE->setReadOnly(true);

        verticalLayout_2->addWidget(NowLE);

        SpuffingCB = new QCheckBox(groupBox_3);
        SpuffingCB->setObjectName(QStringLiteral("SpuffingCB"));
        SpuffingCB->setChecked(true);

        verticalLayout_2->addWidget(SpuffingCB);


        verticalLayout->addWidget(groupBox_3);

        splitter->addWidget(layoutWidget);

        verticalLayout_8->addWidget(splitter);

        LicenseLabel = new QLabel(centralWidget);
        LicenseLabel->setObjectName(QStringLiteral("LicenseLabel"));
        LicenseLabel->setMaximumSize(QSize(16777215, 20));
        LicenseLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_8->addWidget(LicenseLabel);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(OpenPersonalCardEditor);
        menu->addSeparator();
        menu->addAction(MakePhoto);
        menu_2->addAction(CameraControlAction);
        menu_3->addAction(DeviceControlAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Face Recognition NSTU", Q_NULLPTR));
        OpenPersonalCardEditor->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\272\320\260\321\200\321\202...", Q_NULLPTR));
        MakePhoto->setText(QApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\276\321\202\320\276...", Q_NULLPTR));
        CameraControlAction->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\320\260\320\274\320\270...", Q_NULLPTR));
        DeviceControlAction->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260\320\274\320\270...", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\276\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\320\270\320\271", Q_NULLPTR));
        CardDT1->setText(QString());
        CardDT4->setText(QString());
        CardCam1->setText(QString());
        CardCam3->setText(QString());
        CardDT2->setText(QString());
        CardPic1->setText(QString());
        CardPic2->setText(QString());
        CardFIO5->setText(QString());
        CardPic3->setText(QString());
        CardFIO3->setText(QString());
        CardFIO2->setText(QString());
        CardFIO4->setText(QString());
        CardPic4->setText(QString());
        CardPic5->setText(QString());
        CardCam4->setText(QString());
        CardFIO1->setText(QString());
        CardCam5->setText(QString());
        CardDT5->setText(QString());
        CardCam2->setText(QString());
        CardDT3->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", Q_NULLPTR));
        Repass->setText(QString());
        RealFaceLabel->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\320\276\321\217\321\211\320\265\320\265 \320\273\320\270\321\206\320\276", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\201\321\202\320\276\320\262\320\265\321\200\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\241\321\205\320\276\320\264\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\222\320\276\321\210\320\273\320\276 \321\207\320\265\320\273\320\276\320\262\320\265\320\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\210\320\273\320\276 \321\207\320\265\320\273\320\276\320\262\320\265\320\272", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\222 \320\267\320\264\320\260\320\275\320\270\320\270", Q_NULLPTR));
        SpuffingCB->setText(QApplication::translate("MainWindow", "\320\235\320\265 \320\277\321\200\320\276\320\277\321\203\321\201\320\272\320\260\321\202\321\214 \320\277\321\200\320\270 \321\201\320\277\321\203\321\204\320\270\320\275\320\263\320\265", Q_NULLPTR));
        LicenseLabel->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
