INCLUDEPATH += $$PWD
SOURCES += $$PWD/openglwindow.cpp \
    threadserver.cpp \
    threadclient.cpp \
    camera.cpp \
    gamewindow.cpp

HEADERS += $$PWD/openglwindow.h \
    threadserver.h \
    threadclient.h \
    camera.h \
    gamewindow.h

SOURCES += \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/gui/openglwindow
INSTALLS += target
QMAKE_MAC_SDK = macosx10.11

RESOURCES += \
    gestionnaire.qrc

QT += network
TARGET = QTcpSocket
