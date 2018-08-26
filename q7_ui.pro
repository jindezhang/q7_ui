#-------------------------------------------------
#
# Project created by QtCreator 2018-08-06T11:06:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = q7_ui
TEMPLATE = app

RC_ICONS = cat.ico
#add logo icon

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    wiget_label.cpp \
    mylineedit.cpp \
    mydialog.cpp \
    mainwindow2.cpp \
    paintwidget.cpp \
    donewdialog.cpp \
    spinBoxdelegate.cpp \
    comboxdelegate.cpp \
    checkdelagate.cpp

HEADERS += \
        mainwindow.h \
    wiget_label.h \
    mylineedit.h \
    mydialog.h \
    mainwindow2.h \
    paintwidget.h \
    donewdialog.h \
    spinBoxdelegate.h \
    comboxdelegate.h \
    checkdelagate.h

FORMS += \
        mainwindow.ui \
    wiget_label.ui \
    mainwindow2.ui

DISTFILES += \
    pirate.png \
    pirate.png
