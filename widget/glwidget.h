#ifndef _GLWIDGET_H_
#define _GLWIDGET_H_

#include <QtOpenGL/qgl.h>
#include <QKeyEvent>
#include <iostream>
#include <qstring.h>
#include <qfiledialog.h>
#include <qtimer.h>
#include <QtDesigner/QDesignerExportWidget>
#include "../llums/finestraLlums.h"
#include "../llums/llum.h"
#include "vehicle.h"
#include "material_lib.h"
#include "point.h"
#include "scene.h"

class QDESIGNER_WIDGET_EXPORT GLWidget : public QGLWidget
{
  Q_OBJECT

 public:
  GLWidget(QWidget * parent);

 public slots:

  void OpenFile();

  // help - Ajuda per la terminal des de la que hem  engegat el programa.
  void help(void);
	void SetSpeed(int x);
	void PrimeraPersona(void);
	void Llum0OnOff(void);
	void Llum1OnOff(void);
	void Reset();
	void CotxeOnOff(void);
	void mostraLlums();


  // Afegiu aqu� la declaraci� dels slots que necessiteu

 protected:
  // initializeGL() - Aqui incluim les inicialitzacions del contexte grafic.
  virtual void initializeGL();

  // paintGL - M�tode cridat cada cop que cal refrescar la finestra.
  // Tot el que es dibuixa es dibuixa aqui.
  virtual void paintGL( void );
 
  // resizeGL() - Es cridat quan canvi la mida del widget
  virtual void resizeGL (int width, int height);

  // keyPressEvent() - Cridat quan es prem una tecla
  virtual void keyPressEvent(QKeyEvent *e);

  // mousePressEvent() i mouseReleaseEvent()
  virtual void mousePressEvent( QMouseEvent *e);
  virtual void mouseReleaseEvent( QMouseEvent *);
 
  // mouseMoveEvent() - Cridat quan s'arrosega el ratoli amb algun bot� premut.
  virtual void mouseMoveEvent(QMouseEvent *e);
 
  void computeDefaultCamera(); 
 
 private:

  // par�metres de la camera
  GLfloat anglecam;
  double ra;
  double anterior, posterior; 
  Point VRP;
  double dist; 
	GLfloat fovy;
  float angleX, angleY, angleZ;
	Vehicle cotxe;
	int auxSpeed;
	int OnOff;
	int modecamera;
	int llum0;
	int llum1;
	int pripers;
	int cotxeon;
	int modeselect;
	void configurallum1();
	llum* L[2];
	bool vehicle;
	finestraLlums finestra;
	int funcaux();
	bool moviments;
	int numobject;
	int quantsref;
	float xclickaux;
	float yclickaux;
	bool rubberbanding;
	bool primermoviment;
	//double fovy;
	double ar;




  
  // interaccio
  typedef  enum {NONE, ROTATE, ZOOM, PAN, ROTATECAR} InteractiveAction;
  InteractiveAction DoingInteractive;
 
  int   xClick, yClick;
void setModelview();
void setProjection();
  
  Scene scene;  // Escena a representar en el widget

  QTimer timer;
};

#endif
