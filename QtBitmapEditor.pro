
QT += widgets
CONFIG += c++17


CORE_DIR = ../lab4_7
INCLUDEPATH += $$CORE_DIR


HEADERS += \
    ../../lab4/lab4_7/Bitmap.h \
    ../../lab4/lab4_7/IPixelFactory.h \
    ../../lab4/lab4_7/Pixel.h \
    mainwindow.h

SOURCES += main.cpp \
    mainwindow.cpp

FORMS += mainwindow.ui

DISTFILES += \

