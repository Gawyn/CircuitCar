#include "scene.h"
#include "XML.h"
#include <math.h>

int Scene::DRETA=0;
int Scene::ESQUERRA=1;
int Scene::RECTA=2;
int Scene::ARBRE=3;
int Scene::PEDRES=4;
int Scene::CASA=5;
int Scene::DOBLE=6;
int Scene::TRIPLE=7;
int Scene::FANAL=8;

MaterialLib Scene::matlib;

Scene::Scene()
{}

void Scene::Init()
{
  XML xmlloader;
  xmlloader.LoadSceneDescription(this, "../data/escena.xml");
	carregat=false;
	veh.setCopiaCircuit(circuit);
	numref=0;

}


// Modifica un punt donat aplicant-li la transformaci� que es t� guardada
// a la matriu MODELVIEW
void Scene::transformPoint(Point &p)
{
  GLfloat m[16];
  GLfloat p1[16];

  int i; 
  for (i=4; i<16; ++i) p1[i]=0.0f;

  p1[0] = p.x; 
  p1[1] = p.y; 
  p1[2] = p.z; 
  p1[3] = 1;

  glPushMatrix();
  glMultMatrixf(p1);
  glGetFloatv(GL_MODELVIEW_MATRIX, m);
  p.x = m[0];
  p.y = m[1];
  p.z = m[2];
  glPopMatrix();
}

// M�tode que pinta l'escena: tots els objectes i el vehicle
void Scene::Render()
{
  // Cal pintar tots els objectes de l'escena que es troben als vectors
  // Cal pintar tamb� el vehicle, si s'escau
  std::vector<Referencia>::iterator ito;
  std::vector<Tram>::iterator ito2;
	int n=0;
	//Pintem les cases, els arbres...
for (ito=lreferencies.begin(); ito!=lreferencies.end(); ito++){
	(*ito).Render(this->lobjects);
}
	//Pintem la carretera
for (ito2=circuit.begin(); ito2!=circuit.end(); ito2++){
	(*ito2).Render(this->lobjects);
}
	//Si està carregat, pintem el cotxe
if (carregat){
	veh.Render();
	}

}


//FALTA PER FER MOUCOPIA

void Scene::MouCopia(float movx, float movy, float movz){
	int tamany=lreferencies.size();
  	std::vector<Referencia>::iterator ito;
	Point p2;
	bool b=false;
	int i=0;
	ito=lreferencies.begin();
	while(b==false){
		if(i==(tamany-1)){
				Point p2=(*ito).getPosition();
				p2.x=p2.x+movx;
				p2.y=p2.y+movy;
				p2.y=alturacopia;
				p2.z=p2.z+movz;
				(*ito).setPosition(p2);
				b=true;
			}
		ito++;
		i++;
	}

}

void Scene::PintaCopia(){
	int tamany=lreferencies.size();
  	std::vector<Referencia>::iterator ito;
	int i=0;
	bool b=false;
	ito=lreferencies.begin();

	while(b==false){
		if(i==(tamany-1)){
			Point p2=(*ito).getPosition();
			cout<<p2.x;
			cout<<"-";
			cout<<p2.y;
			cout<<"-";
			cout<<p2.z;
			cout<<"\n";
			b=true;
			(*ito).Render(this->lobjects);
		}
		ito++;
		i++;
	}
}

void Scene::EliminaCopia(){
	lreferencies.pop_back();
}

void Scene::StopCopia(){
	int tamany=lreferencies.size();
  	std::vector<Referencia>::iterator ito;
	int i=0;
	bool b=false;
	ito=lreferencies.begin();

	while(b==false){
		if(i==(tamany-1)){
			b=true;
			Point p2=(*ito).getPosition();
			p2.y=alturacopia;
			(*ito).setPosition(p2);
			b=true;
		}
		ito++;
		i++;
	}
}

void Scene::CopiaObject(int num){
	//Referencia aux;
  	std::vector<Referencia>::iterator ito;
	int n=0;
	ito=lreferencies.begin();
	for(int i=0;i!=num;i++){
		ito++;
	}
	int aux1=(*ito).getObjectId();
	Point aux2=(*ito).getPosition();
	alturacopia=aux2.y;
	Vector aux3= (*ito).getSize();
	float aux4=(*ito).getOrientation();	
  	Referencia aux(aux1,aux2,aux3,aux4);
	lreferencies.push_back(aux);
}


void Scene::Renderselect(){
  // Cal pintar tots els objectes de l'escena que es troben al 
  // vector d'inst�ncies i el tauler
	//tauler.displ(display);
  //tauler.Render();
  std::vector<Referencia>::iterator ito;
  std::vector<Tram>::iterator ito2;
	int n=0;
for (ito=lreferencies.begin(); ito!=lreferencies.end(); ito++){
	glLoadName(n);
	(*ito).Render(this->lobjects);
	n++;
	numref++;
}
	//Pintem la carretera
for (ito2=circuit.begin(); ito2!=circuit.end(); ito2++){
	(*ito2).Render(this->lobjects);
	numref++;
}
}

int Scene::getNombreRef(){
	numref=lreferencies.size();
	numref=numref+circuit.size();
	return numref;
}

void Scene::AddObject(Object &o)
{
  lobjects.push_back(o);
}

void Scene::AddObject(Referencia &oref)
{
  lreferencies.push_back(oref);
}

void Scene::AddObject(Tram &tref)
{
  circuit.push_back(tref);
}

void Scene::CalculaEsfera (double &radi, Point &centreEscena)
{
  // creem la capsa inicialment amb els v�rtexs m�nim i m�xim del terra
  Box capsaEscena(Point (0.0, 0.0, 0.0), Point (0.0, 0.0, 0.0));
  Box bobj;
  // actualitzem la capsa amb tots els objectes de l'escena
  std::vector<Referencia>::iterator ito;
  for (ito=lreferencies.begin(); ito!=lreferencies.end(); ito++)
  {
    bobj=(*ito).computeTransformedBox(lobjects[(*ito).getObjectId()]);

    capsaEscena.update(bobj.minb);
    capsaEscena.update(bobj.maxb);
  }
  std::vector<Tram>::iterator itt;
  for (itt=circuit.begin(); itt!=circuit.end(); itt++)
  {
    bobj=(*itt).computeTransformedBox(lobjects[(*itt).getObjectId()]);

    capsaEscena.update(bobj.minb);
    capsaEscena.update(bobj.maxb);
  }
  centreEscena =  (capsaEscena.minb + capsaEscena.maxb)/2.;
  radi = (capsaEscena.maxb-capsaEscena.minb).length()/2.f;
}

void Scene::carrega(){
	carregat=true;
}

