#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T22:06:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_retake
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    repository.cpp \
    controller.cpp \
    exception.cpp \
    programmer.cpp \
    task.cpp \
    subject.cpp \
    observer.cpp

HEADERS  += widget.h \
    repository.h \
    controller.h \
    exception.h \
    programmer.h \
    task.h \
    subject.h \
    observer.h

FORMS    += widget.ui

DISTFILES += \
    progs.txt \
    tasks.txt
