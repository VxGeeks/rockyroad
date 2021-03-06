#-------------------------------------------------
#
# Project created by QtCreator 2017-02-03T13:10:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrandoOne
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
        bma2x2.c \
    bmm050.c \
    Display_Mode.c \
    IC_Init.c \
    Delay.c \
    bmg160.c \
    BMX_support.c

HEADERS  += mainwindow.h \
    bma2x2.h \
    Delay.h \
    Display_Mode.h \
    bmm050.h \
    IC.h \
    IC_Init.h \
    Photo_Show.h \
    bmg160.h \
    BMX_support.h

FORMS    += mainwindow.ui

INCLUDEPATH    += /usr/local/include

LIBS += -L/usr/local/lib -lwiringPi
