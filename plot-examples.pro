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
    parser.cpp \
    retta.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    parser.h \
    tokenizer.h \
    retta.h

FORMS    += mainwindow.ui

