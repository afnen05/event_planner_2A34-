QT       += core gui
QT       += core gui sql
QT       += core gui printsupport
QT       += core gui charts
QT += core serialport
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Mainwindow.cpp \
    arduino.cpp \
    arduino_avis.cpp \
    arduino_facture.cpp \
    avis.cpp \
    client.cpp \
    conge.cpp \
    connection.cpp \
    dialog.cpp \
    facture.cpp \
    main.cpp \
    mainwindow_avis.cpp \
    mainwindow_facture.cpp \
    mainwindowclient.cpp \
    menu.cpp \
    personnel.cpp \
    piechart.cpp \
    smtp.cpp \
    smtpp.cpp \
    sp.cpp

HEADERS += \
    Mainwindow.h \
    arduino.h \
    arduino_avis.h \
    arduino_facture.h \
    avis.h \
    client.h \
    conge.h \
    connection.h \
    dialog.h \
    facture.h \
    mainwindow_avis.h \
    mainwindow_facture.h \
    mainwindowclient.h \
    menu.h \
    personnel.h \
    smtp.h \
    smtpp.h \
    sp.h

FORMS += \
    Mainwindow.ui \
    dialog.ui \
    login.ui \
    mainwindow_avis.ui \
    mainwindow_facture.ui \
    mainwindowclient.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backg.qrc
