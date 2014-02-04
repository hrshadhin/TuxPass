#-------------------------------------------------
#
# Project created by QtCreator 2014-02-03T23:53:57
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TuxPass
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainwindow.cpp \
    database.cpp

HEADERS  += login.h \
    mainwindow.h \
    database.h

FORMS    += login.ui \
    mainwindow.ui

RESOURCES += \
    icons/rec.qrc


OTHER_FILES +=
