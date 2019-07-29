QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proj
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        Model/Hierarchy/animal.cpp \
        Model/Hierarchy/bird.cpp \
        Model/Hierarchy/cat.cpp \
        Model/Hierarchy/dog.cpp \
        Model/jsonparser.cpp \
        Model/modeladapter.cpp \
        Model/sortfilterproxymodel.cpp \
        View/detailswidget.cpp \
        View/insertwidget.cpp \
        View/tableview.cpp \
        main.cpp \
        View/mainwindow.cpp

HEADERS += \
        Model/Hierarchy/animal.h \
        Model/Hierarchy/bird.h \
        Model/Hierarchy/cat.h \
        Model/Hierarchy/dog.h \
        Model/Hierarchy/Bird.h \
        Model/container.h \
        Model/deepptr.h \
        Model/jsonparser.h \
        Model/modeladapter.h \
        Model/sortfilterproxymodel.h \
        View/detailswidget.h \
        View/insertwidget.h \
        View/mainwindow.h \
        View/tableview.h \
        View/ui_mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
