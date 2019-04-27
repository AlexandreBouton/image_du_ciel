TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    bmp_file.cpp \
    ppm_file.cpp \
    general_noise.cpp

HEADERS += \
    bmp_file.h \
    ppm_file.h \
    general_noise.h
