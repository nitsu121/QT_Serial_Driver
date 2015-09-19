#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T13:25:54
#
#-------------------------------------------------


QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = COM_PORT_Driver
TEMPLATE = lib

DEFINES += COM_PORT_DRIVER_LIBRARY

SOURCES += com_port_driver.cpp

HEADERS += com_port_driver.h\
        com_port_driver_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}



