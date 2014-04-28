TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    organism.cpp \
    prey.cpp \
    predator.cpp \
    colony.cpp \
    grid.cpp

HEADERS += \
    organism.h \
    prey.h \
    predator.h \
    colony.h \
    grid.h

