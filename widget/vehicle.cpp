#include "vehicle.h"
#include "scene.h"

#define _USE_MATH_DEFINES 1
#include <cmath>

using namespace std;

Vehicle::Vehicle():obj("VEHICLE"), orient(0)
{}

void Vehicle::llegirModel (const char* filename)
{
   obj.readObj(filename, Scene::matlib);
   obj.updateBoundingBox();
   Box box=obj.boundingBox();

   // Aqui cal que inicialitzeu correctament la resta d'atributs del vehicle

	escalat=15;
	escalat_aux=1;
	p.x=0;p.y=0;p.z=0;
	speed=5;
	inici=true;
	rota=false;
	tramactual=0;
	modemov=0;
	comptadistancia=0;
	modemovaux=0;
	acumulador=0;
	tramnext=1;
	orientaux=0;
	posveh.x=0;posveh.y=0;posveh.z=0;
	angleGir=0;
}

Point Vehicle::getBox(){
   Box box=obj.boundingBox();
	return box.Center();
}

void Vehicle::setCopiaCircuit(vector<Tram> x){
	circuit=x;

}

void Vehicle::setSpeed (double s)
{
  speed=s;
}

double Vehicle::getSpeed()
{
   return speed;
}

double Vehicle::getAngleGir()
{
   return angleGir;
}
void Vehicle::setPos (Point pos)
{
  p=pos;
}

Point Vehicle::getPos()
{
   return p;
}

void Vehicle::setOrientation(int o)
{
   orient=o;
}

int Vehicle::getOrientation()
{ 
   return orient;
}

int Vehicle::getModeGir(){
	return modeGir;
}

void Vehicle::calculaVehPos(){
	Tram t=circuit[tramactual];
	int auxtram;
	int auxdirection;
	float speedaux=0;
	speedaux=(50-speed)+5;
	Tram t2=circuit[tramnext];
	double speedaux2=1/speedaux;
	Point auxpos;
	if(rotafin){setOrientation(orientaux);rota=false;rotafin=false;}

	if (speed>0){

		//Quan arribem a un tram nou, calculem la direcció del tram on estem (modemov)
		//i del pròxim.(modemovaux)
		if(comptadistancia==0){
			circuit[tramnext].whatareyou(auxtram,auxdirection);
			modemovaux=auxdirection;
			help=auxtram;
		}

		//Com que tots els condicionals if modemovaux==x son iguals només explicarem un
		if(modemovaux==0){
			//Si la direcció canvia, és a dir, si s'ha de girar
			if(modemovaux!=modemov){
				rota=true;
				//Això serveix per a no passar-nos dels 90 per decimals que sobren
				//donada la limitació de double o float
				if(acumulador+(90*speedaux2)>=90){
					acumulador+=(90-acumulador);
					orientaux=0;
					rotafin=true;
				}
				//Si no, sumem el gir que pertoca segons la velocitat
				else{
					acumulador+=90*speedaux2;
				}
				//Aqui ḉés on fem el gir. Transportem el punt de gir a (0,0), rotem
				//i retornem a les coordenades normals
				glTranslatef((posveh.x+0.5),posveh.y,posveh.z);
				if(modemov==2){
					modeGir=0;
					glRotatef(acumulador,0,1,0);
					//Quam hem acabat el gir, fem fixa la nova posició
					if(acumulador==90){
						posveh.x+=0.5;
						posveh.z+=0.5;
					}
				}
				else if(modemov==3){
					modeGir=1;
					glRotatef(-acumulador,0,1,0);
					if(acumulador==90){
						posveh.x+=0.5;
						posveh.z-=0.5;
					}
				}
				glTranslatef(-(posveh.x+0.5),-posveh.y,-posveh.z);
				angleGir=acumulador;
			}
			//Si continua recte
			else{
				//Com que la posició inicial del gir és la línea de separació entre
				//trams, i no el mig, tenim en compte si és el primer moviment.
				//A més, anem sumant translates segons la velocitat, fins al seguent
				//tram
				if(inici){
					if(comptadistancia+speedaux2>1.5){
						posveh.x+=(1.5-comptadistancia);
					}
					else{
						posveh.x=posveh.x+(speedaux2);
					}
				}
				else if(comptadistancia+speedaux2>1){
					posveh.x+=(1-comptadistancia);
				}
				else{
					posveh.x=posveh.x+(speedaux2);
				}
			}
		}
		else if(modemovaux==1){
			if(modemovaux!=modemov){
				rota=true;
				if(acumulador+(90*speedaux2)>=90){
					acumulador+=(90-acumulador);
					orientaux=180;
					rotafin=true;
				}
				else{
					acumulador+=90*speedaux2;
				}
				glTranslatef((posveh.x-0.5),posveh.y,posveh.z);
				if(modemov==3){
					modeGir=3;
					glRotatef(acumulador,0,1,0);
					if(acumulador==90){
						posveh.x-=0.5;
						posveh.z-=0.5;
					}
				}
				else if(modemov==2){
					modeGir=2;
					glRotatef(-acumulador,0,1,0);
					if(acumulador==90){
						posveh.x-=0.5;
						posveh.z+=0.5;
					}
				}
				glTranslatef(-(posveh.x-0.5),-posveh.y,-posveh.z);
				angleGir=acumulador;
			}
			else{
				if(comptadistancia+speedaux2>1){
					posveh.x=posveh.x-(1-comptadistancia);
				}
				else{
					posveh.x=posveh.x-(speedaux2);
				}
			}
		}
		else if(modemovaux==2){
			if(modemovaux!=modemov){
				rota=true;
				if(acumulador+(90*speedaux2)>=90){
					acumulador+=(90-acumulador);
					orientaux=-90;
					rotafin=true;
				}
				else{
					acumulador+=90*speedaux2;
				}
				glTranslatef(posveh.x,posveh.y,(posveh.z+0.5));
				if(modemov==1){
					modeGir=5;
					glRotatef(acumulador,0,1,0);
					if(acumulador==90){
						posveh.z+=0.5;
						posveh.x-=0.5;
					}
				}
				else if(modemov==0){
					modeGir=4;
					glRotatef(-acumulador,0,1,0);
					if(acumulador==90){
						posveh.z+=0.5;
						posveh.x+=0.5;
					}
				}
				glTranslatef(-posveh.x,-posveh.y,-(posveh.z+0.5));
				angleGir=acumulador;
			}
			else{
				if(comptadistancia+speedaux2>1){
					posveh.z=posveh.z+(1-comptadistancia);
				}
				else{
					posveh.z=posveh.z+(speedaux2);
				}
			}
		}
		else if(modemovaux==3){
			if(modemovaux!=modemov){
				rota=true;
				if(acumulador+(90*speedaux2)>=90){
					acumulador+=(90-acumulador);
					orientaux=90;
					rotafin=true;
				}
				else{
					acumulador+=90*speedaux2;
				}
				glTranslatef(posveh.x,posveh.y,(posveh.z-0.5));
				if(modemov==0){
					modeGir=6;
					glRotatef(acumulador,0,1,0);
					if(acumulador==90){
						posveh.z-=0.5;
						posveh.x+=0.5;
					}
				}
				else if(modemov==1){
					modeGir=7;
					glRotatef(-acumulador,0,1,0);
					if(acumulador==90){
						posveh.z-=0.5;
						posveh.x-=0.5;
					}
				}
				glTranslatef(-posveh.x,-posveh.y,-(posveh.z-0.5));
				angleGir=acumulador;
			}
			else{
				if(comptadistancia+speedaux2>1){
					posveh.z=posveh.z-(1-comptadistancia);
				}
				else{
					posveh.z=posveh.z-(speedaux2);
				}			
			}
		}
		comptadistancia=comptadistancia+(speedaux2);
		float N=0;
		p=posveh;
		//La translació no serà del mig del tram al mig del tram seguent, sino de la linea
		//d'inici de tram a linia d'inici del tram seguent, la primera translació
		if(inici){
			N=1.5;
		}
		else{
			N=1;
		}
		//Quam hem recorregut el tram, posem els comptadors a 0
		if((comptadistancia>=N && acumulador==0) || acumulador==90){
			rota=false;
			inici=false;
			acumulador=0;
			angleGir=orientaux;
			comptadistancia=0;
			tramactual=tramnext;
			tramnext=help;
			modemov=modemovaux;
		}
	}

}

bool Vehicle::Rota(){
	return rota;
}

void Vehicle::Render ()
{

 	 // Cal aplicar les transformacions de model necess�ries i pintar l'objecte
  	float sx, sy, sz;
   	obj.updateBoundingBox();
  	Box b=obj.boundingBox();



	//glLightfv(GL_LIGHT1,GL_POSITION,pos);
  	// A partir d'aqu�, cal aplicar les transformacions de model necess�ries 
  	// i pintar l'objecte

  	sx = b.maxb.x-b.minb.x;	
  	sy = b.maxb.y-b.minb.y;	
  	sz = b.maxb.z - b.minb.z;	

	glPushMatrix();
	calculaVehPos();
	glTranslatef(posveh.x,0,posveh.z);
	glRotatef(orient,0,1,0);
	//glRotatef(angleGir,eixGir.x,eixGir.y,eixGir.z); 
	glScaled(0.5,0.5,0.5);
  	glTranslatef(-(b.maxb.x+b.minb.x)/2, -b.minb.y, -(b.maxb.z+b.minb.z)/2);
	obj.Render();
	glPopMatrix();
}

