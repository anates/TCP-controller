#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T13:20:07
#
#-------------------------------------------------

QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_client_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    client.h \
    server.h

FORMS    += mainwindow.ui
