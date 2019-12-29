#-------------------------------------------------
#
# Project created by QtCreator 2019-04-06T01:18:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = collo
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
    mythread.cpp \
    my_label.cpp\
    detectfacecv.cpp

HEADERS += \
        mainwindow.h \
    mythread.h \
    my_label.h \
    detectfacecv.h
    #dlibdetectface.h

FORMS += \
        mainwindow.ui

INCLUDEPATH+=/usr/include/opencv
QMAKE_CXXFLAGS += -Wall

LIBS += `pkg-config opencv --libs`

CONFIG += link_pkgconfig
PKGCONFIG += opencv
#############################DLIB CONFIG##########################
INCLUDEPATH+= /home/nano/dlib-19.6/include
LIBS+=-L/home/nano/dlib-19.6/build
LIBS+=-ldlib
