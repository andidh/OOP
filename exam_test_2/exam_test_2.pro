#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T10:08:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exam_test_2
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    question.cpp \
    participant.cpp \
    repository.cpp \
    observer.cpp \
    subject.cpp \
    exception.cpp \
    controller.cpp \
    presenter.cpp

HEADERS  += gui.h \
    question.h \
    participant.h \
    repository.h \
    observer.h \
    subject.h \
    exception.h \
    controller.h \
    presenter.h

FORMS    += gui.ui

DISTFILES += \
    questions.txt \
    participants.txt
