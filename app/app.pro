TEMPLATE	= app
LANGUAGE	= C++
TARGET          = PracticaVIG

QT += opengl

LIBS += ../widget/libpluginGLWidget.so /usr/lib/libstdc++.so.6
INCLUDEPATH += ../widget

HEADERS	+= Principal.h

SOURCES	+= Principal.cpp \
	main.cpp 


FORMS	= Principal.ui

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}


