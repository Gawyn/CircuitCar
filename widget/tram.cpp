#include "tram.h"
#include "scene.h"

Tram::Tram(int idob, Point p, Vector sz, int ori):Referencia(idob, p, sz, ori)
{
   seguents[XPOS]=-1;
   seguents[XNEG]=-1;
   seguents[ZPOS]=-1;
   seguents[ZNEG]=-1;
}

Tram::~Tram(void)
{}


void Tram::tractaRecta(int a)
{
       if (orientation==0) seguents[XNEG]=a;
       else if (orientation==90)  seguents[ZPOS]=a;
       else if (orientation==180) seguents[XPOS]=a;
       else if (orientation==270) seguents[ZNEG]=a;
	tipus=0;
	triple=false;
}

void Tram::tractaDreta(int a)
{
       if (orientation==0)   seguents[ZNEG]=a; 
       else if (orientation==90) seguents[XNEG]=a; 
       else if (orientation==180) seguents[ZPOS]=a; 
       else if (orientation==270) seguents[XPOS]=a;
	tipus=1;
 	triple=false;
}

void Tram::tractaEsquerra(int a)
{
       if (orientation==0)  seguents[ZPOS]=a; 
       else if (orientation==90) seguents[XPOS]=a; 
       else if (orientation==180) seguents[ZNEG]=a; 
       else if (orientation==270) seguents[XNEG]=a; 
	tipus=2;
	triple=false;
}

void Tram::tractaDoble(int a, int b)
{
	if (orientation==0) {seguents[ZNEG]=a; seguents[ZPOS]=b;} 
   else if (orientation==90)  {seguents[XNEG]=a; seguents[XPOS]=b;} 
   else if (orientation==180) {seguents[ZPOS]=a; seguents[ZNEG]=b;} 
   else if (orientation==270) {seguents[XPOS]=a; seguents[XNEG]=b;}
	tipus=3; 
	triple=false;
}

void Tram::tractaTriple(int a, int b, int c)
{
   if (orientation==0)   {seguents[ZNEG]=a; seguents[XNEG]=b; seguents[ZPOS]=c; }
   else if (orientation==90)  {seguents[XNEG]=a; seguents[ZPOS]=b; seguents[XPOS]=c; }
   else if (orientation==180) {seguents[ZPOS]=a; seguents[XPOS]=b; seguents[ZNEG]=c; }
   else if (orientation==270) {seguents[XPOS]=a; seguents[ZNEG]=b; seguents[XNEG]=c; }
	tipus=4;
	triple=true;
}

void Tram::setSeg(int a, int b, int c)
{
      if (object==Scene::RECTA) tractaRecta(a);
      else if(object==Scene::DRETA) tractaDreta(a);
      else if(object==Scene::DOBLE) tractaDoble(a,b);
      else if(object==Scene::TRIPLE) tractaTriple(a,b,c);
      else if(object==Scene::ESQUERRA) tractaEsquerra(a);
}

void Tram::whatareyou(int &tram, int &ori){

	//Retornem el tipus de tram(recta,dreta,esquerra, doble i tripe)
	int random = (rand()%2)+1;
	int random2 = (rand()%3)+1;
	int i=-1;
	int j=0;
	if (tipus<3){
		if(seguents[XPOS]!=-1){ori=0;tram=seguents[XPOS];}
		else if(seguents[XNEG]!=-1){ori=1;tram=seguents[XNEG];}
		else if(seguents[ZPOS]!=-1){ori=2;tram=seguents[ZPOS];}
		else if(seguents[ZNEG]!=-1){ori=3;tram=seguents[ZNEG];}
	}
	else if(tipus==3){
		while(j<random){
			i++;
			if(seguents[i]!=-1){
				j++;
			}
		}
		tram=seguents[i];
		ori=i;
	}
	else if(tipus==4){
		while(j<random2){
			i++;
			if(seguents[i]!=-1){
				j++;
			}
		}
		tram=seguents[i];
		ori=i;
	}
	
}
