#include "glwidget.h"

#include <stdlib.h>
#define _USE_MATH_DEFINES 1
#include <cmath>

// Constructora amb format per defecte
GLWidget::GLWidget(QWidget * parent):QGLWidget(parent)
{
  // per rebre events de teclat
  setFocusPolicy(Qt::ClickFocus);
  

  connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
  timer.start(0);

  
  DoingInteractive = NONE;  
}


// initializeGL() - Aqui incluim les inicialitzacions del contexte grafic.
void GLWidget::initializeGL()
{
  glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	L[0]= new llum(0,"Llum 1");
	L[1]= new llum(1,"Llum 2");
	finestra.iniciar(L,2); 
	pripers=0;
	primermoviment=true;
	cotxeon=1;
	numobject=-1;
	for(int i=0;i<4;i++){
		L[1]->ambient[i]=1;
		L[1]->difos[i]=1;
		L[1]->especular[i]=1;
		L[1]->posicio[i]=1;
		L[0]->ambient[i]=1;
		L[0]->difos[i]=1;
		L[0]->especular[i]=1;
	}
	L[0]->posicio[0]=0;
	L[0]->posicio[1]=0;
	L[0]->posicio[2]=0;
	L[0]->posicio[3]=1;
	L[0]->referencia=ESCENA;
	rubberbanding=false;
	modeselect=0;
	glShadeModel(GL_FLAT);
  	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

	vehicle=false;
	moviments=false;
  // inicialitzem tamb� l'escena
  scene.Init();
		quantsref=scene.getNombreRef();
		quantsref=quantsref*4;
  // dimensions escena i camera inicial
  computeDefaultCamera();
	modecamera=0;
	OnOff=1;
	auxSpeed=1;
	llum0=1;
	llum1=1;
}


void GLWidget::configurallum1(){

	Point punto = scene.veh.getPos();
	L[1]->posicio[0]=punto.x;
	L[1]->posicio[1]=1;
	L[1]->posicio[2]=punto.z;

	GLfloat pos[]={punto.x,punto.z,punto.z,1};
	GLfloat angllum[]= {60};
	bool b=false;
	double angle=scene.veh.getAngleGir();
	GLfloat dirllum[3];
	dirllum[1]=-2;
	b=scene.veh.Rota();
	if(b==false){
		if(angle==0){
			dirllum[0]=0.8;
			dirllum[2]=0;
		}
		else if(angle==180){
			dirllum[0]=-0.8;
			dirllum[2]=0;
		}
		else if(angle==-90){
			dirllum[0]=0;
			dirllum[2]=0.8;
		}
		else if(angle==90){
			dirllum[0]=0;
			dirllum[2]=-0.8;
		}
	}
	else{

		double angle=0;
		angle=scene.veh.getAngleGir();
		int mode = scene.veh.getModeGir();
		double normpos=(angle/90)*0.5;
		double auxdist2= (angle/90)*0.8;
		double invers = 0.8-auxdist2;
		if(mode==0){
			L[1]->posicio[0]=punto.x+normpos;
			L[1]->posicio[2]=punto.z-normpos;
			dirllum[0]=auxdist2;
			dirllum[2]=invers;
		}
		else if(mode==1){
			L[1]->posicio[0]=punto.x+normpos;
			L[1]->posicio[2]=punto.z-normpos;
			dirllum[0]=auxdist2;
			dirllum[2]=-invers;
		}
		else if(mode==2){
			L[1]->posicio[0]=punto.x-normpos;
			L[1]->posicio[2]=punto.z+normpos;
			dirllum[0]=-auxdist2;
			dirllum[2]=invers;

		}
		else if(mode==3){
			dirllum[0]=-auxdist2;
			dirllum[2]=-invers;
		}
		else if(mode==4){
			L[1]->posicio[0]=punto.x+normpos;
			L[1]->posicio[2]=punto.z+normpos;
			dirllum[0]=invers;
			dirllum[2]=auxdist2;
		}
		else if(mode==5){
			L[1]->posicio[0]=punto.x-normpos;
			L[1]->posicio[2]=punto.z+normpos;
			dirllum[0]=-invers;
			dirllum[2]=auxdist2;
		}
		else if(mode==6){
			L[1]->posicio[0]=punto.x+normpos;
			L[1]->posicio[2]=punto.z-normpos;
			dirllum[0]=invers;
			dirllum[2]=-auxdist2;
		}
		else if(mode==7){
			L[1]->posicio[0]=punto.x-normpos;
			L[1]->posicio[2]=punto.z+normpos;
			dirllum[0]=-invers;
			dirllum[2]=auxdist2;
		}


	}
	//glLightfv(GL_LIGHT1,GL_POSITION,pos);
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,dirllum);
	glLightfv(GL_LIGHT1,GL_SPOT_CUTOFF,angllum);
}

void GLWidget::Llum0OnOff(){
	if(llum0==0){
		glEnable(GL_LIGHT0);
		llum0=1;
	}
	else{
		glDisable(GL_LIGHT0);
		llum0=0;
	}
}

void GLWidget::Llum1OnOff(){
	if(llum1==0){
		glEnable(GL_LIGHT1);
		llum1=1;
	}
	else{
		glDisable(GL_LIGHT1);
		llum1=0;
	}
}

void GLWidget::computeDefaultCamera()
{
  // Cal inicialitzar els par�metres necessaris per a definir la c�mera
  // amb els valors que ens permetin obtenir la c�mera inicial desitjada
	double radi;
	VRP= Point(0,0,0);
	angleX= 45;
	angleY= 45;
	angleZ= 0;
	ra=1;
	anterior=0.1;
	posterior=100;
	scene.CalculaEsfera(radi,VRP);
	dist= 2*radi;
	double aux3;
	aux3=asin(radi/dist);
	anglecam = 2*(aux3*(180/M_PI));
}

void GLWidget::setModelview()
{
	Point VRPaux;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(L[0]->activada==true){
		glLightfv(GL_LIGHT0,GL_POSITION,L[0]->posicio);
		glLightfv(GL_LIGHT0,GL_AMBIENT,L[0]->ambient);
		glLightfv(GL_LIGHT0,GL_DIFFUSE,L[0]->difos);
		glLightfv(GL_LIGHT0,GL_SPECULAR,L[0]->especular);
		glEnable(GL_LIGHT0);
	}
	else glDisable(GL_LIGHT0);


	if(modecamera==0){
		glTranslatef(0,0,-dist);
		glRotatef(-angleZ,0,0,1); //Gz(-ϕc)
		glRotatef(angleX, 1,0,0); //Gx (θc)
		glRotatef(-angleY,0,1,0); //Gy(-Ψc)
		glTranslatef(-VRP.x,-VRP.y,-VRP.z);
	}
	else{
		
		double angle=0;
		Point OBSaux=(0,0,0);
		bool b =false;
		if(vehicle==true){
			angle=scene.veh.getAngleGir();
			b=scene.veh.Rota();
			Point joder=scene.veh.getPos();
			OBSaux.x=joder.x;
			OBSaux.y=joder.y;
			OBSaux.z=joder.z;
		}
		double auxdist2= angle/90;
		double auxdist= auxdist2*0.707106781;
		//glRotatef(angle,0,1,0);
		Point centre=OBSaux;

		if(b){
			//Codi per a quan hagi de rotar
			int mode = scene.veh.getModeGir();
			double catop=auxdist2*0.5;
			double catcon=catop;
			double regulador=catop*2;
			double regulador2=(0.5-(catop))*5;
			if (mode==0){
	gluLookAt(OBSaux.x+catop,0.5,OBSaux.z+catcon,centre.x+catop+regulador,0.5,centre.z+catcon+regulador2,0,1,0);
			}
			else if(mode==1){
	gluLookAt(OBSaux.x+catop,0.5,OBSaux.z-catcon,centre.x+catop+regulador,0.5,centre.z-catcon-regulador2,0,1,0);
			}
			else if(mode==2){
	gluLookAt(OBSaux.x-catop,0.5,OBSaux.z+catcon,centre.x-catop-regulador,0.5,centre.z+catcon+regulador2,0,1,0);
			}
			else if(mode==3){
	gluLookAt(OBSaux.x-catop,0.5,OBSaux.z-catcon,centre.x-catop-regulador,0.5,centre.z-catcon-regulador2,0,1,0);
			}

			else if(mode==4){
	gluLookAt(OBSaux.x+catop,0.5,OBSaux.z+catcon,centre.x+catop+regulador2,0.5,centre.z+catcon+regulador,0,1,0);
			}
		
			else if(mode==5){
	gluLookAt(OBSaux.x-catop,0.5,OBSaux.z+catcon,centre.x-catop-regulador2,0.5,centre.z+catcon+regulador,0,1,0);
			}
			else if(mode==6){
	gluLookAt(OBSaux.x+catop,0.5,OBSaux.z-catcon,centre.x+catop+regulador2,0.5,centre.z-catcon-regulador,0,1,0);
			}
			else if(mode==7){
	gluLookAt(OBSaux.x-catop,0.5,OBSaux.z-catcon,centre.x-catop-regulador2,0.5,centre.z-catcon-regulador,0,1,0);
			}
		}
		else{
			if(angle==0){gluLookAt(OBSaux.x,0.5,OBSaux.z,centre.x+1,0.5,centre.z,0,1,0);}
			else if(angle==180){gluLookAt(OBSaux.x,0.5,OBSaux.z,centre.x-1,0.5,centre.z,0,1,0);}
			else if(angle==-90){gluLookAt(OBSaux.x,0.5,OBSaux.z,centre.x,0.5,centre.z+1,0,1,0);}
			else{gluLookAt(OBSaux.x,0.5,OBSaux.z,centre.x,0.5,centre.z-1,0,1,0);}
		}
		//cout<<angle;
		//cout<<"\n";
		//glTranslatef(VRPaux.x,0,VRPaux.z);
	}


	if(L[1]->activada==true){
		glLightfv(GL_LIGHT1,GL_POSITION,L[1]->posicio);
		glLightfv(GL_LIGHT1,GL_AMBIENT,L[1]->ambient);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,L[1]->difos);
		glLightfv(GL_LIGHT1,GL_SPECULAR,L[1]->especular);
		glEnable(GL_LIGHT1);
	}
	else glDisable(GL_LIGHT1);

 }

void GLWidget::setProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	ar = (double) width()/height();
	fovy=0;
	//Modifiquem l'angle d'obertura de la càmera segons l'aspect ratio.
	if(ar<=1){fovy=anglecam;}
	else{
		double DEG2RAD = M_PI/180.;
		double RAD2DEG = 180./M_PI;
		fovy = 2*atan(tan((anglecam/2)*DEG2RAD)/ar)*RAD2DEG;
	}
	gluPerspective(fovy,ar,anterior,posterior);

}


// paintGL() - callback cridat cada cop que cal refrescar la finestra. 
void GLWidget::paintGL( void )
{ 
  // Esborrem els buffers
if(rubberbanding==false){
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}
  
	configurallum1();

  setModelview();
  setProjection();
// dibuixar eixos aplicacio
if(rubberbanding==false){

  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
  // pintem l'escena
  scene.Render();
}

}




void GLWidget::SetSpeed(int x){
	//Passa la velocitat introduida per l'usuari al vehicle si aquest està en funcionament
	//si no, la guarda per quan aquest es posi en marxa
	if (OnOff!=0){
		scene.veh.setSpeed(x);
	}
	auxSpeed=x;
}

void GLWidget::Reset(){
	computeDefaultCamera();
}

void GLWidget::OpenFile()
{
	QString carrega = QFileDialog::getOpenFileName( this, "Carrega de vehicle",".",QString::null);	
	string aux= carrega.toStdString();
	const char * aux2=aux.c_str();
	if (!carrega.isEmpty())
	{
		cotxe.llegirModel(aux2);
		scene.veh=cotxe;
		scene.carrega();
		vehicle=true;
	}
}

// resizeGL() - Cridat quan es canvia el tamany del viewport.
void GLWidget::resizeGL (int width, int height)
{
/*
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);
*/
        glViewport(0,0,width, height);
}

// help() - Surt per la terminal des de la que hem 
// engegat el programa. En la versio amn interficie 
// hauria de crear una nova finestra amb la informacio...
void GLWidget::help( void ){
  cout<<"Tecles definides: \n";
  cout<<"f         Pinta en filferros\n";
  cout<<"s         Pinta amb omplert de pol�gons\n";
  cout<<"h,H,?     Imprimir aquesta ajuda\n";
  // Completar amb altres tecles que definiu...
  //
}

/*--------------------
*
*  teclat()
*
*  callback per quan hom prem una tecla.
*
*/
void GLWidget::keyPressEvent(QKeyEvent *e)
{
  switch( e->key() ) 
  {	    
    case Qt::Key_F: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      updateGL();
      break;
    case Qt::Key_S: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      updateGL();
      break;
    case  'h'  : case  'H'  : case  '?'  :  help();
      break;
    default: e->ignore(); // el propaguem cap al pare...
  }

}

int GLWidget::funcaux(){
        //Declaración de variables
        GLint picks,viewport[4];
        GLint res=-1;

        GLuint buffSelect[quantsref];
        glDisable(GL_LIGHTING);
        glSelectBuffer(quantsref, buffSelect);
        glGetIntegerv(GL_VIEWPORT, viewport);
	//Llamamos a PROJECTION
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glRenderMode(GL_SELECT);
        glLoadIdentity();
        gluPickMatrix(xClick, viewport[3] - yClick, 1, 1, viewport);
        gluPerspective(fovy,ar,anterior,posterior);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
		glTranslatef(0,0,-dist);
		glRotatef(-angleZ,0,0,1); //Gz(-ϕc)
		glRotatef(angleX, 1,0,0); //Gx (θc)
		glRotatef(-angleY,0,1,0); //Gy(-Ψc)
		glTranslatef(-VRP.x,-VRP.y,-VRP.z);
        glInitNames();
        glPushName(0);
        scene.Renderselect();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        picks=glRenderMode(GL_RENDER);
        if(picks>=1){
		//glFlush();
            res=buffSelect[3];
        }

        glEnable(GL_LIGHTING);
        return res;
}

/*--------------------
* mousePressEvent()
*/
void GLWidget::mousePressEvent( QMouseEvent *e){
  xClick = e->x();
  yClick = e->y();
  

	if(moviments==true){
		if(e->button()&Qt::LeftButton){
			scene.StopCopia();
			moviments=false;
		}
		else if(e->button()&Qt::RightButton){
			scene.EliminaCopia();
		}

		glEnable(GL_DEPTH_TEST);
  		glEnable(GL_LIGHTING);
		setAutoBufferSwap(true);
		glDisable(GL_COLOR_LOGIC_OP);
		glDrawBuffer(GL_FRONT_AND_BACK);
  		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		moviments=false;
		rubberbanding=false;
		primermoviment=true;
	}
	else if (e->button()&Qt::LeftButton && 
	! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
	{
	DoingInteractive = ROTATE;
	}
	else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier && 
	! (e->modifiers()&(Qt::AltModifier|Qt::ControlModifier)))
	{
	DoingInteractive = ZOOM;
	}
	else if (e->button()&Qt::RightButton &&  e->modifiers() &Qt::ShiftModifier)
	{
	DoingInteractive = PAN;
	}
	else if(e->button()&Qt::RightButton )
	{
	DoingInteractive = ROTATECAR;
	}
	else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier && e->modifiers() &Qt::ControlModifier){
			numobject=funcaux();
				if (numobject!=-1){
					moviments=true;
					scene.CopiaObject(numobject);

					//Fem el RubberBanding
					rubberbanding=true;
  					glDisable(GL_DEPTH_TEST);
  					glDisable(GL_LIGHTING);
					setAutoBufferSwap(false);
					glDrawBuffer(GL_FRONT);
					xclickaux =0.03*(e->x() - xClick);
					yclickaux =-0.03* (e->y() - yClick);
					cout<<"Quantes vegades?";
					glColor3f(1,1,1);
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}
		}

}



/*--------------------
*
* mouseReleaseEvent()
*
* Callback Qt cridat quan es deixa anar el bot� del
* ratol�.
*
*/
void GLWidget::mouseReleaseEvent( QMouseEvent *){
  DoingInteractive = NONE;
}

/*--------------------
*
* mouseMoveEvent()
*
* Callback Qt cridat quan s'arrosega el ratoli amb
* algun boto premut.
*
*/
void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
	float aux;
  // Aqu� cal que es calculi i s'apliqui la rotaci�, el zoom o el pan
  // com s'escaigui...
  
  if (DoingInteractive == ROTATE)
  {
	angleX = angleX + (e->y() - yClick);
	angleY = angleY + (e->x() - xClick);
  }
  else if (DoingInteractive == ZOOM)
  {
    // Fem el zoom
	aux = (e->y() - yClick);
	if((anterior + aux)<(posterior - aux))
	{	
		dist=dist+(aux*0.2);
	}
	else{
		dist=dist+(aux*0.2);

	}
  }
  else if (DoingInteractive==PAN)
  {  
    // Fem el pan
	float Float1 =0.05*(e->x() - xClick);
	float Float2 =-0.05* (e->y() - yClick);
	GLdouble mView[16];
	
	glGetDoublev(GL_MODELVIEW_MATRIX, mView);

	//p1=(mView[0] , mView[4] , mView[8]);
	//p2=(mView[1] , mView[5] , mView[9]);
	VRP.x=(VRP.x + mView[0]*Float1 +mView[1]*Float2);
	VRP.y=(VRP.y + mView[4]*Float1 + mView[5]*Float2);
	VRP.z=(VRP.z + mView[8]*Float1 + mView[9]*Float2);

  }   
else if (DoingInteractive==ROTATECAR)
{

	//Això és per rotar el cotxe amb el mouse. Es mourà quan pitgem el botó dret i desplaçem
	//el ratolí horitzontalment.
	glMatrixMode(GL_MODELVIEW);
	scene.veh.setOrientation(xClick);
}

	else if(moviments==true){

		GLdouble mView[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, mView);
		float movx, movy, movz;
		glEnable(GL_COLOR_LOGIC_OP);
		glLogicOp(GL_XOR);
		if(primermoviment==false){
		scene.PintaCopia();
		}
		float Float1 =0.03*(e->x() - xClick);
		float Float2 =-0.03* (e->y() - yClick);
		movx=(mView[0]*Float1 +mView[1]*Float2);
		movy=(mView[4]*Float1 + mView[5]*Float2);
		movz=(mView[8]*Float1 + mView[9]*Float2);
		scene.MouCopia(movx,movy, movz);

		glColor3f(1,1,1);
		scene.PintaCopia();
		primermoviment=false;
		glFlush();
		//glFlush();
		glDisable(GL_COLOR_LOGIC_OP);
	}

  xClick = e->x();
  yClick = e->y();
  updateGL();
}

void GLWidget::mostraLlums(void){
	finestra.show();
}

void GLWidget::PrimeraPersona(void){

	//Activa o desactiva el cotxe
	if(pripers==1){
		pripers=0;
		modecamera=0;
	}
	else{
		pripers=1;
		modecamera=1;
	}
}

void GLWidget::CotxeOnOff(void){

	//Activa o desactiva el cotxe
	if(cotxeon==1){
		cotxeon=0;
		scene.veh.setSpeed(0);
		OnOff=0;
		computeDefaultCamera();
	}
	else{
		cotxeon=1;
		scene.veh.setSpeed(auxSpeed);
		OnOff=1;
	}
}

