CONFIG     += designer plugin debug_and_release
TARGET      = pluginGLWidget
QT         += opengl
OBJECTS_DIR = .obj
MOC_DIR     = .moc
TEMPLATE    = lib
target.path = ~/.designer/plugins/designer
INSTALLS   += target
HEADERS     =  glwidgetPlugin.h glwidget.h
SOURCES     =  glwidgetPlugin.cpp glwidget.cpp

HEADERS	+= 	object.h \
	referencia.h \
   tram.h \
	scene.h \
	face.h \
	vertex.h \
	color.h \
	box.h \
	XML.h \
	material.h \
	material_lib.h \
	point.h \
	tinystr.h \
	tinyxml.h \
	vehicle.h \
	../llums/boto.h \
	../llums/finestraLlums.h \
	../llums/llum.h \
	../llums/sliderText.h \
	../llums/textField.h \
	../llums/ui_EditorLlums.h
	

SOURCES	+= object.cpp \
	referencia.cpp \
  	tram.cpp \
	scene.cpp \
	face.cpp \
	vertex.cpp \
	color.cpp \
	box.cpp \
	XML.cpp \
	material.cpp \
	material_lib.cpp \
	point.cpp \
	tinystr.cpp \
	tinyxml.cpp \
	tinyxmlerror.cpp \
	tinyxmlparser.cpp \
	vehicle.cpp \
	../llums/boto.cpp \
	../llums/finestraLlums.cpp \
	../llums/main.cpp \
	../llums/sliderText.cpp \
	../llums/textField.cpp
