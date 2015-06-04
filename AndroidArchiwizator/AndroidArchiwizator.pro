#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T00:08:33
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AndroidArchiwizator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    SrvThread.cpp

HEADERS  += mainwindow.h \
    server.h \
    SrvThread.h

FORMS    += mainwindow.ui
