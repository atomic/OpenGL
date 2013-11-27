#-------------------------------------------------
#
# Project created by QtCreator 2013-11-20T05:50:54
#
#-------------------------------------------------

QT       += core gui opengl
#the LIBS below is added for new QT

LIBS     += -L/usr/local/lib -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TRYYYYYYYYY
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypanelopengl.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h \
    kkk.h

FORMS    += mainwindow.ui

