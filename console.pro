QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = console
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
	TPool.cpp \
	objects/TObject.cpp \
	objects/TGame.cpp \
	objects/board/TBoard.cpp \
	objects/board/weapon/TWeapon.cpp \
	objects/board/weapon/TTurret.cpp \
	objects/score/TScore.cpp \
	objects/control/TControl.cpp \
	objects/storage/TStorage.cpp

HEADERS += \
        mainwindow.h \
	TPool.h \
	objects/All_objects.h \
	objects/TObject.h \
	objects/TGame.h \
	objects/board/TBoard.h \
	objects/board/weapon/TWeapon.h \
	objects/board/weapon/TTurret.h \
	objects/score/TScore.h \
	objects/control/TControl.h \
	objects/storage/TStorage.h \
       	operations/painter.h \
	operations/helpers.h
