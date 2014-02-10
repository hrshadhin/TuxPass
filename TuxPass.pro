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
    database.cpp \
    adddb.cpp \
    loaddb.cpp \
    mainui.cpp \
    passgenerate.cpp

HEADERS  += login.h \
    database.h \
    adddb.h \
    loaddb.h \
    mainui.h \
    passgenerate.h

FORMS    += login.ui \
    adddb.ui \
    loaddb.ui \
    mainui.ui

RESOURCES += \
    icons/rec.qrc


OTHER_FILES +=
