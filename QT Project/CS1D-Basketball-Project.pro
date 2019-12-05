QT       += core gui sql

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
    database.cpp \
    editwindow.cpp \
    graphwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    resultswindow.cpp \
    souvenir.cpp \
    souvenirwindow.cpp \
    team.cpp \
    tripselectwindow.cpp \
    tripwindow.cpp \
    viewwindow.cpp

HEADERS += \
    Map.h \
    database.h \
    editwindow.h \
    graphwindow.h \
    loginwindow.h \
    mainwindow.h \
    resultswindow.h \
    souvenir.h \
    souvenirwindow.h \
    team.h \
    tripselectwindow.h \
    tripwindow.h \
    viewwindow.h

FORMS += \
    editwindow.ui \
    graphwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    resultswindow.ui \
    souvenirwindow.ui \
    tripselectwindow.ui \
    tripwindow.ui \
    viewwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	resources/database.db
