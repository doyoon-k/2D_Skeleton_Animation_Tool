#-------------------------------------------------
#
# Project created by QtCreator 2020-03-15T02:25:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimationTool
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

CONFIG += c++17

INCLUDEPATH += C:\Users\doyoonkim\Documents\AnimationTool\BindPoseGenerator

SOURCES += \
        AnimationSample.cpp \
        BindPoseGenerator/addjointcommand.cpp \
        BindPoseGenerator/jointtreewidgetitem.cpp \
        BindPoseGenerator/skeletonhierarchytreewidget.cpp \
        BindPoseGenerator/spritelistwidget.cpp \
        Joint.cpp \
        Matrix3X3.cpp \
        Skeleton.cpp \
        Vector3D.cpp \
        BindPoseGenerator/bindposeanimsamplegenerator.cpp \
        BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        AnimationClip.h \
        AnimationSample.h \
        BindPoseGenerator/addjointcommand.h \
        BindPoseGenerator/jointtreewidgetitem.h \
        BindPoseGenerator/skeletonhierarchytreewidget.h \
        BindPoseGenerator/spritelistwidget.h \
        Joint.h \
        Matrix3X3.h \
        Skeleton.h \
        Sprite.h \
        SpriteMesh.h \
        Vector3D.h \
        BindPoseGenerator/bindposeanimsamplegenerator.h \
        BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h \
        mainwindow.h \
        mathLib.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
