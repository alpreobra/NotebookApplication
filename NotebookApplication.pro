QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_contact_dialog.cpp \
    add_event_dialog.cpp \
    add_task_dialog.cpp \
    find_contact_by_fio_dialog.cpp \
    find_contact_by_phonenumber_dialog.cpp \
    find_contact_by_who_dialog.cpp \
    find_event_by_date_dialog.cpp \
    find_event_by_name_dialog.cpp \
    find_task_by_date_dialog.cpp \
    main.cpp \
    notebook.cpp

HEADERS += \
    add_contact_dialog.h \
    add_event_dialog.h \
    add_task_dialog.h \
    find_contact_by_fio_dialog.h \
    find_contact_by_phonenumber_dialog.h \
    find_contact_by_who_dialog.h \
    find_event_by_date_dialog.h \
    find_event_by_name_dialog.h \
    find_task_by_date_dialog.h \
    notebook.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
