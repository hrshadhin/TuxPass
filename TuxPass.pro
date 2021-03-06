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
    mainui.cpp \
    passgenerate.cpp \
    endecrypter.cpp \
    dboparation.cpp \
    tools.cpp \
    helpcontents.cpp

HEADERS  += login.h \
    database.h \
    mainui.h \
    passgenerate.h \
    endecrypter.h \
    dboparation.h \
    tools.h \
    helpcontents.h

FORMS    += login.ui \
    mainui.ui \
    dboparation.ui \
    tools.ui \
    helpcontents.ui

RESOURCES += \
    icons/rec.qrc


OTHER_FILES +=
