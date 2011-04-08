#include "Vertex.h"


Vertex::Vertex(){
	//default coordinate values
	v = vec4(0,0,0,1); //default at origin

	//default id value
	ID = 0;
}

Vertex::Vertex(int id){
	ID = id;
}

Vertex::Vertex(float x, float y, float z){
	ID = 0;
	v = vec4(x,y,z,1);
}

Vertex::Vertex(float x, float y, float z, int id){
	ID = id;
	v = vec4(x,y,z,1);
}

Vertex::~Vertex(){
	//empty destructor
}

void Vertex::setX(float x){
	v[0] = x;
}

void Vertex::setY(float y){
	v[1] = y;
}

void Vertex::setZ(float z){
	v[2] = z;
}

void Vertex::setXYZ(float x, float y, float z){
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

float Vertex::getX(){
	return v[0];
}

float Vertex::getY(){
	return v[1];
}

float Vertex::getZ(){
	return v[2];
}

void Vertex::print(){
	std::cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<std::endl;
}
