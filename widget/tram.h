#ifndef _Tram_H_
#define _Tram_H_
#include "referencia.h"

#define XPOS 0
#define XNEG 1
#define ZPOS 2
#define ZNEG 3

class Tram:public Referencia
{
 private:
   int seguents[4];   // vector d'indexos a trams connectats al tram donat
	void tractaRecta(int a);
	void tractaDreta(int a);
	void tractaEsquerra(int a);
	void tractaDoble(int a, int b);
	void tractaTriple(int a, int b, int c);
	int tipus;


 public:
  Tram(int idob, Point p, Vector sz, int ori);
  ~Tram(void);
	bool triple;
   
   void setSeg(int a, int b=-1, int c=-1);
	void whatareyou(int &tram, int &ori);

};
#endif
