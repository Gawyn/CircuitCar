#include "referencia.h"
#include "box.h"
#include <QtOpenGL/qgl.h>
#include "scene.h"

Referencia::Referencia(int ob, Point p, Vector sz, float ori):
  object(ob), pos(p), size(sz), orientation(ori)
{}

Referencia::~Referencia(void)
{}

/*
void ObjectRef::Render(vector<Object> &models)
{

	Object o = models[object];
	o.display=display;
	Point centrat=o.boundingBox().Center();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	pos.x=(-0.225/2)+0.225*((columna-1)-3);
	pos.z=0.225*3+(0.225/2)-((fila-1))*0.225;
	glTranslatef(pos.x,pos.y,pos.z);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-centrat.x,-centrat.y,-centrat.z);
	glColor3f(mat.ka.r,mat.ka.g,mat.ka.b);
	if (fila<9 && fila>0 && columna<9 && columna>0){
		o.Render();
	}
	Object p = models[object];
	glPopMatrix();
  // Cal aplicar les transformacions de model necess�ries i
  // pintar l'objecte del color que toca
}
*/

void Referencia::Render(std::vector<Object> &lobjects)
{
  	float sx, sy, sz;

  	Object o=lobjects[this->object];
  	Box b=o.boundingBox();
  	// A partir d'aqu�, cal aplicar les transformacions de model necess�ries 
  	// i pintar l'objecte

  	sx = b.maxb.x-b.minb.x;
  	sy = b.maxb.y-b.minb.y;	
  	sz = b.maxb.z - b.minb.z;	
  	glMatrixMode(GL_MODELVIEW);
  	glPushMatrix();
  	//LoadIdentity();
  	glTranslatef(pos.x, pos.y, pos.z);
  	glRotatef(orientation, 0, 1, 0);
  	glScalef(size.x/sx, size.y/sy, size.z/sz);
  	glTranslatef(-(b.maxb.x+b.minb.x)/2, -b.minb.y, -(b.maxb.z+b.minb.z)/2);
	o.computeNormals();
	o.Render();
	glPopMatrix();
}

int Referencia::getObjectId()
{
  return object;
}

// Calculem la caixa transformada a partir de la caixa original
// de l'objecte.

Box& Referencia::computeTransformedBox(Object &obj)
{
  Box b = obj.boundingBox();
  Box result;
  float sa, sb, sc;
  sa=b.maxb.x-b.minb.x;	
  sb=b.maxb.y-b.minb.y;	
  sc = b.maxb.z - b.minb.z;	
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef(orientation, 0, 1, 0);
  glScalef(size.x/sa, size.y/sb, size.z/sc);
  glTranslatef(-(b.maxb.x+b.minb.x)/2, -b.minb.y, -(b.maxb.z+b.minb.z)/2);

  vector<Vertex> &verts = obj.vertices;
  Point punt(verts[0].coord.x, verts[0].coord.y, verts[0].coord.z);
  Scene::transformPoint(punt);
  result.init(punt);

  for (unsigned int i=1; i<verts.size(); ++i)
  {
    Point punt(verts[i].coord.x, verts[i].coord.y, verts[i].coord.z);
    Scene::transformPoint(punt);
    result.update(punt);
  }
  glPopMatrix();
  return result;
}

void Referencia::setPosition(Point p){
	pos=p;
}

Point Referencia::getPosition()
{
   return pos;
}

Vector Referencia::getSize()
{
   return size;
}

float Referencia::getOrientation()
{
   return orientation;
}

Box Referencia::getOriginalBox(Object &obj){
	Box b = obj.boundingBox();
	return b;
}
