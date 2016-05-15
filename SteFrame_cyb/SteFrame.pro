#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T10:13:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SteFrame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    algorithm.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    algorithm.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui

RESOURCES += \
    steframe.qrc
