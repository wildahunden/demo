QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    costmatrixtest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CostMatrix/release/ -lCostMatrix
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CostMatrix/debug/ -lCostMatrix

INCLUDEPATH += $$PWD/../CostMatrix
DEPENDPATH += $$PWD/../CostMatrix

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/release/libCostMatrix.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/debug/libCostMatrix.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/release/CostMatrix.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/debug/CostMatrix.lib
