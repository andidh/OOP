#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T11:55:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    repository.cpp \
    controller.cpp \
    exception.cpp \
    observer.cpp \
    subject.cpp \
    programmer.cpp \
    tester.cpp \
    source.cpp

HEADERS  += gui.h \
    repository.h \
    controller.h \
    exception.h \
    observer.h \
    subject.h \
    programmer.h \
    tester.h \
    source.h

FORMS    += gui.ui

DISTFILES += \
    source.txt \
    prog.txt
