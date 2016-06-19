#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T19:03:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_test_1
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    programmer.cpp \
    task.cpp \
    repository.cpp \
    controller.cpp \
    exception.cpp \
    observer.cpp \
    subject.cpp

HEADERS  += gui.h \
    programmer.h \
    task.h \
    repository.h \
    controller.h \
    exception.h \
    observer.h \
    subject.h

FORMS    += gui.ui

DISTFILES += \
    tasks.txt \
    progs.txt
