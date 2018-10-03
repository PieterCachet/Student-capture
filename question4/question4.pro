#-------------------------------------------------
#
# Project created by QtCreator 2018-09-19T13:38:36
#
#-------------------------------------------------
QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = question4
CONFIG += CONSOLE
CONFIG += c++11

SOURCES += main.cpp \
    student.cpp \
    studentlist.cpp \
    mainwindow.cpp \
    xmlwriter.cpp

HEADERS += \
    student.h \
    studentlist.h \
    mainwindow.h \
    xmlwriter.h

