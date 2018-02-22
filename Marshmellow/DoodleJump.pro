#-------------------------------------------------
#
# Project created by QtCreator 2017-07-16T15:48:58
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = Marshmellow
TEMPLATE = app

CONFIG += c++14
QMAKE_CXXFLAGS += -Wall

DEFINES += GLEW_STATIC

SOURCES += main.cpp\
    game/entity/jumppad.cpp \
    game/entity/movingjumppad.cpp \
    game/entity/doodler.cpp \
    gui/gamewindow.cpp \
    game/doodlejump.cpp \
    engine/input/inputselector.cpp \
    gui/gamerenderwidget.cpp \
    engine/graphics/camera/camera.cpp \
    engine/graphics/camera/camera2d.cpp \
    engine/graphics/datatype/vao.cpp \
    engine/graphics/datatype/vbo.cpp \
    engine/graphics/datatype/vboattribmarker.cpp \
    engine/graphics/datatype/vio.cpp \
    engine/graphics/primitives/fullscreenquad.cpp \
    engine/graphics/primitives/shape.cpp \
    engine/graphics/shaders/shader.cpp \
    engine/graphics/texture/textureloader.cpp \
    engine/graphics/texture/textureparams.cpp \
    engine/graphics/graphicsobject.cpp \
    engine/dataParse/xmlprimitiveparser.cpp \
    game/input/qttobxinputmapper.cpp \
    engine/graphics/dataload/shaders/shaderfilerepository.cpp \
    game/input/inputmapper.cpp \
    engine/graphics/sprite2d/spritebatcher.cpp \
    engine/graphics/texture/texturecache.cpp \
    engine/graphics/texture/texture2d.cpp \
    game/graphics/doodlerdrawer.cpp \
    engine/graphics/sprite2d/sprite2d.cpp \
    engine/graphics/sprite2d/simplesprite2d.cpp \
    game/graphics/multisprite/multisprite.cpp \
    game/graphics/DataParse/simplesprite2dfileparser.cpp \
    game/graphics/DataParse/multispritefileparser.cpp \
#    dependencies/glew-2.1.0/src/glew.c

HEADERS  += game/entity/jumppad.h \
    game/entity/movingjumppad.h \
    game/entity/doodler.h \
    gui/gamewindow.h \
    game/doodlejump.h \
    engine/constants.h \
    engine/input/inputselector.h \
    gui/gamerenderwidget.h \
    engine/graphics/camera/camera.h \
    engine/graphics/camera/camera2d.h \
    engine/graphics/camera/cameracontrols.h \
    engine/graphics/datatype/fbo.h \
    engine/graphics/datatype/vao.h \
    engine/graphics/datatype/vbo.h \
    engine/graphics/datatype/vboattribmarker.h \
    engine/graphics/datatype/vio.h \
    engine/graphics/primitives/fullscreenquad.h \
    engine/graphics/primitives/shape.h \
    engine/graphics/shaders/shader.h \
    engine/graphics/shaders/shadervar.h \
    engine/graphics/texture/textureloader.h \
    engine/graphics/texture/textureparams.h \
    engine/graphics/graphicsobject.h \
    engine/dataParse/xmlprimitiveparser.h \
    engine/input/inputmacros.h \
    game/input/qttobxinputmapper.h \
    engine/graphics/util/util.h \
    engine/graphics/dataload/shaders/shadersourcedata.h \
    engine/graphics/dataload/shaders/shaderrepository.h \
    engine/graphics/dataload/shaders/shaderfilerepository.h \
    engine/physics/orientation2d.h \
    game/input/inputmapper.h \
    game/input/playercommands.h \
    engine/graphics/sprite2d/spritebatcher.h \
    engine/physics/orientation2dutils.h \
    engine/graphics/texture/texturecache.h \
    engine/graphics/texture/texture2d.h \
    engine/graphics/texture/texture2ddata.h \
    game/graphics/doodlerdrawer.h \
    engine/graphics/sprite2d/sprite2d.h \
    engine/graphics/util/util.h \
    engine/graphics/sprite2d/simplesprite2d.h \
    game/graphics/multisprite/multisprite.h \
    engine/graphics/sprite2d/simplesprite2ddata.h \
    engine/graphics/sprite2d/simplesprite2dfiledata.h \
    game/graphics/DataParse/simplesprite2dfileparser.h \
    game/graphics/DataParse/multispritefileparser.h \
    game/graphics/multisprite/multispritefiledata.h \

FORMS    += gui/gamewindow.ui \
    gui/gamerenderwidget.ui

##
## GLM headers
##

INCLUDEPATH += $$PWD/dependencies/glm-0.9.8.4
DEFINES += GLM_FORCE_SWIZZLE

##
## TODO!
##
## The following two blocks of code (one each for GLEW and tinyxml)
## must be reconfigured if you work on Windows
## First, recompile the libraries (they've been compiled for Mac, not Windows)
## Then delete the existing code chunks
## Finally, right-click and select "Add Library", choose External, and navigate
## to the site of the compiled binary and select it. Qt will generate the new .pro
## code for you.

##----------------------------------------------------------------
##
## QT-GENERATED .PRO CODE
##
## GLEW dependencies
##
##----------------------------------------------------------------

DEFINES += GLEW_STATIC

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dependencies/glew-2.1.0/lib/Debug/x64/ -lglew32s
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dependencies/glew-2.1.0/lib/Debug/x64/ -lglew32sd
else:unix: LIBS += -L$$PWD/dependencies/glew-2.1.0/lib/Debug/x64/ -lglew32s

INCLUDEPATH += $$PWD/dependencies/glew-2.1.0/include
DEPENDPATH += $$PWD/dependencies/glew-2.1.0/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/glew-2.1.0/lib/Debug/x64/libglew32s.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/glew-2.1.0/lib/Debug/x64/libglew32sd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/glew-2.1.0/lib/Debug/x64/glew32s.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/glew-2.1.0/lib/Debug/x64/glew32sd.lib
else:unix: PRE_TARGETDEPS += $$PWD/dependencies/glew-2.1.0/lib/Debug/x64/libglew32s.a

##----------------------------------------------------------------
##
## QT-GENERATED .PRO CODE
##
## TinyXml2 dependencies
##
##----------------------------------------------------------------

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/ -ltinyxml2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/ -ltinyxml2
else:unix: LIBS += -L$$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/ -ltinyxml2

INCLUDEPATH += $$PWD/dependencies/tinyxml2-master
DEPENDPATH += $$PWD/dependencies/tinyxml2-master
DEPENDPATH += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/libtinyxml2.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/libtinyxml2.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/tinyxml2.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/tinyxml2.lib
else:unix: PRE_TARGETDEPS += $$PWD/dependencies/tinyxml2-master/tinyxml2/bin/tinyxml2/x64-Debug-Lib/libtinyxml2.a

#/-----

LIBS += -lopengl32
