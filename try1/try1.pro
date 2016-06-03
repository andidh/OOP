#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T12:27:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = try1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domain.cpp \
    repository.cpp \
    validator.cpp \
    exception.cpp \
    controller.cpp \
    store.cpp \
    storefile.cpp \
    utils.cpp \
    storecsv.cpp

HEADERS  += mainwindow.h \
    domain.h \
    repository.h \
    controller.h \
    validator.h \
    utils.h \
    store.h \
    storefile.h \
    storecsv.h \
    exception.h

FORMS    += mainwindow.ui

DISTFILES += \
    store.txt \
    csv.txt \
    store.html
