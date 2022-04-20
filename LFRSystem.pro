#-------------------------------------------------
#
# Project created by QtCreator 2022-02-10T16:27:38
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LFRSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    messagehandler.cpp \
    personalcardeditorform.cpp \
    personalcardmanager.cpp \
    LFR/arcface.cpp \
    LFR/lfrmanager.cpp \
    LFR/lfrmsghandler.cpp \
    LFR/live.cpp \
    LFR/livefacereco.cpp \
    LFR/mtcnn_new.cpp \
    LFR/videodetectionhandler.cpp \
    makephotoform.cpp \
    addvideosourceform.cpp \
    showingcardmanager.cpp \
    authorisationform.cpp \
    devicecontrolform.cpp \
    devicesmanager.cpp

HEADERS += \
        mainwindow.h \
    messagehandler.h \
    personalcardeditorform.h \
    personalcardmanager.h \
    LFR/arcface.h \
    LFR/lfrmanager.h \
    LFR/lfrmsghandler.h \
    LFR/live.h \
    LFR/livefacereco.hpp \
    LFR/mtcnn_new.h \
    LFR/videodetectionhandler.h \
    makephotoform.h \
    addvideosourceform.h \
    showingcardmanager.h \
    authorisationform.h \
    devicecontrolform.h \
    devicesmanager.h

FORMS += \
        mainwindow.ui \
    personalcardeditorform.ui \
    makephotoform.ui \
    addvideosourceform.ui \
    authorisationform.ui \
    devicecontrolform.ui

QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

unix: {
        CONFIG += link_pkgconfig
        PKGCONFIG += opencv
}

unix:!macx: LIBS += -L$$PWD/include/ncnn/ -lncnn

INCLUDEPATH += $$PWD/include/ncnn
DEPENDPATH += $$PWD/include/ncnn

unix:!macx: PRE_TARGETDEPS += $$PWD/include/ncnn/libncnn.a
