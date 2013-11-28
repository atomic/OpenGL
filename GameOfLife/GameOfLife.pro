#-------------------------------------------------
#
# Project created by QtCreator 2013-11-27T14:04:49
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypanelopengl.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h \
    gameoflife.h

FORMS    += mainwindow.ui
