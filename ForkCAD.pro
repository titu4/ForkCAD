#-------------------------------------------------
#
# Project created by QtCreator 2015-01-22T22:09:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ForkCAD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    displaywidget.cpp \
    Bike/bike.cpp \
    Bike/fork.cpp \
    Bike/frame.cpp \
    Bike/tube.cpp \
    Bike/wheel.cpp

HEADERS  += mainwindow.h \
    displaywidget.h \
    Bike/bike.h \
    Bike/fork.h \
    Bike/frame.h \
    Bike/structs.h \
    Bike/tube.h \
    Bike/wheel.h

FORMS    += mainwindow.ui
