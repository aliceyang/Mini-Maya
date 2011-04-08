#ifndef VERTEX_H
#define VERTEX_H
#include "algebra3.h"

class Vertex{
public:
	vec4 v;
	int ID;

	Vertex();
	Vertex(int id);
	Vertex(float x, float y, float z);
	Vertex(float x, float y, float z, int id);
	~Vertex();

	//insert additional methods here
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setXYZ(float x, float y, float z);
	float getX();
	float getY();
	float getZ();

	void print();



};

#endif VERTEX_H
