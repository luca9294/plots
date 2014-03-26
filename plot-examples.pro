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
    parabola.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    tokenizer.h \
    retta.h \
    parser_line.h \
    parabola.h

FORMS    += mainwindow.ui

