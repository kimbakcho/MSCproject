#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T21:29:29
#
#-------------------------------------------------

QT       += core gui network webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = MCSproject_client

TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    qsettingframe.cpp \
    qtcsocket.cpp \
    webwiget.cpp

HEADERS  += widget.h \
    qsettingframe.h \
    qtcsocket.h \
    webwiget.h
