QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CostMatrix/release/ -lCostMatrix
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CostMatrix/debug/ -lCostMatrix

INCLUDEPATH += $$PWD/../CostMatrix
DEPENDPATH += $$PWD/../CostMatrix

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/release/libCostMatrix.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/debug/libCostMatrix.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/release/CostMatrix.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../CostMatrix/debug/CostMatrix.lib
