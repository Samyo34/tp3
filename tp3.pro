INCLUDEPATH += $$PWD
SOURCES += $$PWD/openglwindow.cpp \
    camera.cpp \
    gamewindow.cpp \
    threadclient.cpp \
    threadserver.cpp
HEADERS += $$PWD/openglwindow.h \
    camera.h \
    gamewindow.h \
    threadclient.h \
    threadserver.h

SOURCES += \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/gui/openglwindow
INSTALLS += target
QMAKE_MAC_SDK = macosx10.11

RESOURCES += \
    gestionnaire.qrc

QT += network
TARGET = QTcpSocket
