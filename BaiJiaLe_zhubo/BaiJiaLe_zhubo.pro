QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = BaiJiaLeZhuBo

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
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    mod/MNetManager.cpp \
    mod/mod_chat/MChat.cpp \
    mod/mod_gameover/MGameOver.cpp \
    mod/mod_leave/MLeave.cpp \
    mod/mod_login/MLogin.cpp \
    mod/mod_money/MMoney.cpp \
    mod/mod_roominfo/MRoomInfo.cpp \
    mod/mod_topThree/MTopThree.cpp \
    qqchat.cpp

HEADERS += \
    form.h \
    mainwindow.h \
    mod/MNetManager.h \
    mod/mod_chat/MChat.h \
    mod/mod_gameover/MGameOver.h \
    mod/mod_leave/MLeave.h \
    mod/mod_login/MLogin.h \
    mod/mod_money/MMoney.h \
    mod/mod_roominfo/MRoomInfo.h \
    mod/mod_topThree/MTopThree.h \
    qqchat.h

FORMS += \
    form.ui \
    mainwindow.ui \
    mod/mod_chat/MChat.ui \
    mod/mod_gameover/MGameOver.ui \
    mod/mod_login/MLogin.ui \
    mod/mod_money/MMoney.ui \
    mod/mod_topThree/MTopThree.ui \
    qqchat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

DISTFILES +=
