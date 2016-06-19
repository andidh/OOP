#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T10:12:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_test_3
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    user.cpp \
    issue.cpp \
    exception.cpp \
    observer.cpp \
    subject.cpp \
    repository.cpp \
    controller.cpp

HEADERS  += gui.h \
    user.h \
    issue.h \
    exception.h \
    observer.h \
    subject.h \
    repository.h \
    controller.h

FORMS    += gui.ui

DISTFILES += \
    issues.txt \
    users.txt
