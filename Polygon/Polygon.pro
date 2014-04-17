#-------------------------------------------------
#
# Project created by QtCreator 2014-04-16T20:51:45
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Polygon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypanelopengl.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h

FORMS    += mainwindow.ui
