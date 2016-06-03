#-------------------------------------------------
#
# Project created by QtCreator 2016-05-23T20:26:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam3QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domain.cpp \
    repository.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    domain.h \
    repository.h \
    controller.h

FORMS    += mainwindow.ui

DISTFILES += \
    data.txt
