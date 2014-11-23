#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T15:45:33
#
#-------------------------------------------------



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WithoutThem
TEMPLATE = app


QT       += sql

SOURCES += main.cpp\
        mainwindow.cpp \
    Factory.cpp \
    Worker.cpp \
    Product.cpp \
    StatsList.cpp \
    WorkStation.cpp \
    DatabaseManipulator.cpp
    WorkStation.cpp

HEADERS  += mainwindow.h \
    Factory.h \
    Worker.h \
    Product.h \
    StatsList.h \
    SkillTypeEnums.h \
    WorkStation.h \
    DatabaseManipulator.h
    WorkStation.h

CONFIG += c++11



FORMS    += mainwindow.ui

OTHER_FILES += \
    without_them_db

RESOURCES +=
