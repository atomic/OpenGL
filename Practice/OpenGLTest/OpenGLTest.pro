#-------------------------------------------------
#
# Project created by QtCreator 2013-11-26T20:53:33
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lglut -lGL -lGLU -lGLEW

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGLTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypanelopengl.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h

FORMS    += mainwindow.ui
