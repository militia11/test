#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T17:24:40
#
#-------------------------------------------------

QT       += network sql testlib

QT       -= gui

TARGET = tst_servertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += AndroidArchiwizator\server.cpp
HEADERS += AndroidArchiwizator\server.h

SOURCES += AndroidArchiwizator\SrvThread.cpp
HEADERS += AndroidArchiwizator\SrvThread.h

SOURCES += tst_servertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
