#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T13:16:59
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = Main_App
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytcpserver.cpp \
    comsetupmenue.cpp \
    slavethread.cpp

HEADERS  += mainwindow.h \
    mytcpserver.h \
    comsetupmenue.h \
    slavethread.h

FORMS    += mainwindow.ui \
    comsetupmenue.ui




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../COM_PORT_Driver/Build/release/ -lCOM_PORT_Driver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../COM_PORT_Driver/Build/debug/ -lCOM_PORT_Driver

INCLUDEPATH += $$PWD/../COM_PORT_Driver/Build/release
DEPENDPATH += $$PWD/../COM_PORT_Driver/Build/release

INCLUDEPATH += $$PWD/../COM_PORT_Driver/Build/debug
DEPENDPATH += $$PWD/../COM_PORT_Driver/Build/debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../COM_PORT_Driver/Build/release/libCOM_PORT_Driver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../COM_PORT_Driver/Build/debug/libCOM_PORT_Driver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../COM_PORT_Driver/Build/release/COM_PORT_Driver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../COM_PORT_Driver/Build/debug/COM_PORT_Driver.lib

INCLUDEPATH += $$PWD/../COM_PORT_Driver
DEPENDPATH += $$PWD/../COM_PORT_Driver
