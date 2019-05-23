TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread -lglog -lgflags

SOURCES += \
        main.cpp \
        gflags_test.cpp

HEADERS += \
    future.h \
    gflags_test.h
