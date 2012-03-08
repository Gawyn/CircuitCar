#ifndef _Vehicle_H_
#define _Vehicle_H_
#include "object.h"
#include "tram.h"
#include <QtOpenGL/qgl.h>

class Vehicle
{
  friend class Scene;

 private:
  Point p;         // posici� del centre de la base del vehicle
  double escalat;    // escalat (homogeni) que cal aplicar-li en pintar-lo
  double orient;        // orientaci� (en graus) respecte l'eix Y
	double escalat_aux;
	double speed;
	vector <Tram> circuit;
	void calculaVehPos();
	int tramactual;
	int tramnext;
	int modemov;
	int auxcalcul;
	int modemovaux;
	double comptadistancia;
	float acumulador;
	Point posveh;
	int help;
	bool inici;
	double orientaux;
	bool rota;
	double angleGir;
	int modeGir;
	bool auxrota;
	bool rotafin;

 
public:
  Vehicle();
  Object obj;
	void setCopiaCircuit(vector <Tram> x);
	bool Rota();
	Point getBox();

  // carrega l'objecte
  void llegirModel (const char* filename); 

  // assigna la posici� del vehicle
  void setPos (Point);
  Point getPos();
  void setSpeed (double);
  double getSpeed();
	double getAngleGir();
	int getModeGir();
 
  // assigna l'orientaci� del vehicle
  void setOrientation (int);
  int getOrientation();
  void Render ();
  
};

#endif
