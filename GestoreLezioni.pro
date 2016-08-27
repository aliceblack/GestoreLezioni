#-------------------------------------------------
#
# Project created by QtCreator 2016-08-16T12:54:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestoreLezioni
TEMPLATE = app


SOURCES += main.cpp\
    lezione.cpp \
    motore.cpp \
    ppl.cpp \
    vds.cpp \
    gpl.cpp \
    complete.cpp \
    database.cpp \
    basewindow.cpp \
    mainwindow.cpp \
    lessonstable.cpp \
    studentstable.cpp \
    c_mainwindow.cpp

HEADERS  += \
    lezione.h \
    motore.h \
    ppl.h \
    vds.h \
    gpl.h \
    complete.h \
    database.h \
    basewindow.h \
    mainwindow.h \
    lessonstable.h \
    studentstable.h \
    c_mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    DataBase.xml

