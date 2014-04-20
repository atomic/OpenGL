QT += core gui opengl
QT += widgets

TEMPLATE = app
#CONFIG += console
#CONFIG -= app_bundle
#CONFIG -= qt

HEADERS += \
    mywindow.h \
    glwidget.h \
    polygon.h

SOURCES += main.cpp \
    mywindow.cpp \
    glwidget.cpp \
    polygon.cpp


