#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T15:45:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WithoutThem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Factory.cpp \
    Worker.cpp \
    Product.cpp \
    StatsList.cpp \
    Car.cpp
    WorkStation.cpp

HEADERS  += mainwindow.h \
    Factory.h \
    Worker.h \
    Product.h \
    StatsList.h \
    Car.h \
    SkillTypeEnums.h
    WorkStation.h

CONFIG += c++11



FORMS    += mainwindow.ui
