#
#  QCustomPlot Plot Examples
#

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = plot-examples
TEMPLATE = app

RC_FILE = icon.txt

SOURCES += main.cpp\
           mainwindow.cpp \
    qcustomplot.cpp \
    retta.cpp \
    parser_line.cpp \
    parabola.cpp \
    parser_parabola.cpp \
    ellipse.cpp \
    parser_ellipse.cpp \
    circle.cpp \
    parser_ellipse_n.cpp \
    ellipse_n.cpp \
    circle_n.cpp \
    hyperbole.cpp \
    parser_hyperbole.cpp \
    dialog_line.cpp \
    dialogs.cpp \
    prova.cpp \
    circle_d.cpp \
    parabola_d.cpp \
    hyperbole_d.cpp \
    hyperbole_n.cpp \
    form.cpp \
    tests/test2.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    tokenizer.h \
    retta.h \
    parser_line.h \
    parabola.h \
    parser_parabola.h \
    ellipse.h \
    parser_ellipse.h \
    circle.h \
    parser_ellipse_n.h \
    ellipse_n.h \
    circle_n.h \
    hyperbole.h \
    parser_hyperbole.h \
    dialog_line.h \
    dialogs.h \
    prova.h \
    circle_d.h \
    parabola_d.h \
    hyperbole_d.h \
    hyperbole_n.h \
    shape.h \
    form.h \
    tests/test2.h \
    tests/AutoTest.h

FORMS    += mainwindow.ui \
    dialog_line.ui \
    dialog_ellipse.ui \
    dialogs.ui \
    circle_d.ui \
    parabola_d.ui \
    hyperbole_d.ui \
    form.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    icon.txt

