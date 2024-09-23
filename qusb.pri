INCLUDEPATH += $$PWD/src

#libusb-1.0
win32 {
INCLUDEPATH += $$PWD/include
LIBS += -L$$PWD/lib
RC_FILE = $$PWD/src/qusb.rc
}
else{
    CONFIG += link_pkgconfig
    PKGCONFIG += libusb-1.0
}

SOURCES += \
    $$PWD/src/device.cpp \
    $$PWD/src/handle.cpp \
    $$PWD/src/io.cpp \
    $$PWD/src/bulkio.cpp \
    $$PWD/src/io_p.cpp \
    $$PWD/src/eventhandler.cpp \
    $$PWD/src/bulkdevicehandle.cpp

HEADERS += \
    $$PWD/src/device.h \
    $$PWD/src/handle.h \
    $$PWD/src/io.h \
    $$PWD/src/bulkio.h \
    $$PWD/src/io_p.h \
    $$PWD/src/eventhandler.h \
    $$PWD/src/global.h \
    $$PWD/src/clibusb.h \
    $$PWD/src/bulkdevicehandle.h \
    $$PWD/src/version.h

PUBLIC_HEADERS = \
    $$PWD/src/global.h \
    $$PWD/src/device.h \
    $$PWD/src/clibusb.h \
    $$PWD/src/bulkdevicehandle.h



DISTFILES += \
    $$PWD/src/qusb.rc
