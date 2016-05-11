#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T00:17:37
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaikoDrum
TEMPLATE = app


SOURCES += main.cpp \
    Drum.cpp \
    DrumNode.cpp \
    score.cpp \
    Game.cpp \
    Timer.cpp \
    BeginingWindow.cpp

HEADERS  += \
    Drum.h \
    DrumNode.h \
    score.h \
    Game.h \
    Timer.h \
    BeginingWindow.h

FORMS    +=

RESOURCES += \
    img.qrc \
    sound.qrc

DISTFILES +=
