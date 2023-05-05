QT  = core
QT  += network

CONFIG += c++17 cmdline
CONFIG+=sdk_no_version_check

OBJECTS_DIR=$$PWD/build/objects
MOC_DIR=$$PWD/build/moc

QMAKE_CXXFLAGS += -Werror

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clienttelegraf.cpp \
        main.cpp \
        metricgenerator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    clienttelegraf.h \
    metricgenerator.h
