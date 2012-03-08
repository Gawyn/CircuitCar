#ifndef _Referencia_H_
#define _Referencia_H_
#include <vector>
#include "point.h"
#include "object.h"
#include "box.h"


using namespace std;

class Referencia
{
 protected:
  int object;   // identificador de l'objecte
  Point pos;    // posicio sobre el terra
  Vector size;	   // mida en unitats
  float orientation;  //orientaci� respecte Y

 public:
  Referencia(int idob, Point p, Vector sz, float ori);
  ~Referencia(void);

  void Render(std::vector<Object> &);
  int getObjectId();
  Box& computeTransformedBox(Object &obj);
  Point getPosition();
	void setPosition(Point p);
  Vector getSize();
  float getOrientation();
	Box getOriginalBox(Object &obj);
};

#endif
