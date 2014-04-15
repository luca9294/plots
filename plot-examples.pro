#
#  QCustomPlot Plot Examples
#

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = plot-examples
TEMPLATE = app

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
    circle_n.cpp

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
    circle_n.h

FORMS    += mainwindow.ui

