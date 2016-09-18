QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    canvaswidget.cpp \
    cshape.cpp \
    cline_s.cpp \
    crectangle.cpp \
    crectangle_s.cpp \
    ccircle.cpp \
    cellipse.cpp \
    ctriangle.cpp \
    cbeziercurve.cpp \
    precisedrawdialog.cpp \
    colormanagedialog.cpp

HEADERS += \
    mainwindow.h \
    canvaswidget.h \
    cshape.h \
    cline_s.h \
    crectangle.h \
    crectangle_s.h \
    ccircle.h \
    cellipse.h \
    ctriangle.h \
    cbeziercurve.h \
    precisedrawdialog.h \
    colormanagedialog.h

FORMS += \
    precisedrawdialog.ui \
    colormanagedialog.ui

RESOURCES += \
    image.qrc
