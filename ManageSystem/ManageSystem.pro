#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T17:58:11
#
#-------------------------------------------------

QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManageSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    manager.cpp \
    select.cpp \
    alter.cpp \
    altercheckin.cpp \
    selectcheckin.cpp \
    selectdepart.cpp \
    alterdepart.cpp \
    add.cpp \
    adddepart.cpp \
    deletedepart.cpp \
    help.cpp \
    alterpassword.cpp \
    logout.cpp \
    enroll.cpp \
    deletepersonal.cpp \
    personalinfo.cpp \
    salary.cpp \
    checkin.cpp \
    depart.cpp \
    about.cpp \
    selectme.cpp \
    alterme.cpp

HEADERS  += mainwindow.h \
    user.h \
    manager.h \
    select.h \
    alter.h \
    altercheckin.h \
    selectcheckin.h \
    selectdepart.h \
    alterdepart.h \
    add.h \
    adddepart.h \
    deletedepart.h \
    help.h \
    about.h \
    alterpassword.h \
    logout.h \
    enroll.h \
    deletepersonal.h \
    personalinfo.h \
    salary.h \
    checkin.h \
    depart.h \
    selectme.h \
    alterme.h

FORMS    += mainwindow.ui \
    user.ui \
    manager.ui \
    select.ui \
    alter.ui \
    altercheckin.ui \
    selectcheckin.ui \
    selectdepart.ui \
    alterdepart.ui \
    add.ui \
    adddepart.ui \
    deletedepart.ui \
    help.ui \
    about.ui \
    alterpassword.ui \
    logout.ui \
    enroll.ui \
    deletepersonal.ui \
    personalinfo.ui \
    salary.ui \
    checkin.ui \
    depart.ui \
    selectme.ui \
    alterme.ui
