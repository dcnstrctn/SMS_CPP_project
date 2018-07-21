#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T16:13:22
#
#-------------------------------------------------

QT       += core gui
RC_ICONS +=logo.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMS_demo
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
    logindialog.cpp \
    changepwdialog.cpp \
    stockinfodialog.cpp \
    goodindialog.cpp \
    modifystockinfordialog.cpp \
    deletememberdialog.cpp \
    newmnmberdialog.cpp \
    function_goods.cpp \
    goods.cpp \
    vip.cpp \
    supervip.cpp \
    dateandtime.cpp \
    func_vip.cpp \
    viewallmember.cpp \
    checkoutdialog.cpp \
    searchphonenumber.cpp \
    account.cpp \
    discountaccount.cpp \
    dailyaccountdialog.cpp \
    dayaccount.cpp \
    function_account.cpp \
    monthaccount.cpp \
    monthlyaccountdialog.cpp \
    searchaccountdialog.cpp \
    setdiscountdialog.cpp \
    giftsdialog.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    changepwdialog.h \
    global.h \
    stockinfodialog.h \
    goodindialog.h \
    modifystockinfordialog.h \
    deletememberdialog.h \
    updatedialog.h \
    newmnmberdialog.h \
    goods.h \
    vip.h \
    supervip.h \
    dateandtime.h \
    viewallmember.h \
    checkoutdialog.h \
    searchphonenumber.h \
    account.h \
    discountaccount.h \
    dailyaccountdialog.h \
    monthlyaccountdialog.h \
    searchaccountdialog.h \
    setdiscountdialog.h \
    giftsdialog.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    changepwdialog.ui \
    stockinfodialog.ui \
    goodindialog.ui \
    modifystockinfordialog.ui \
    deletememberdialog.ui \
    newmnmberdialog.ui \
    viewallmember.ui \
    checkoutdialog.ui \
    searchphonenumber.ui \
    dailyaccountdialog.ui \
    monthlyaccountdialog.ui \
    searchaccountdialog.ui \
    setdiscountdialog.ui \
    giftsdialog.ui

RESOURCES += \
    icons.qrc
