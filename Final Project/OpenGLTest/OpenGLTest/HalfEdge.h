#ifndef HALFEDGE_H
#define HALFEDGE_H
#include "Vertex.h"
#include "Face.h"

class Face; //forward declaration
class Vertex;

class HalfEdge{
public:
	Face *F;
	Vertex *V;
	HalfEdge *NEXT, *SYM;
	int ID;
	Vertex* edgePoint; //for use in Catmull-Clark Subdivision
	Vertex* midpoint; //midpoint that lies along the edge

	HalfEdge();
	HalfEdge(int id);

	Vertex* getEdgePoint(); //returns edgePoint
	Vertex* getMidpoint(); //returns midpoint

	~HalfEdge();



};
#endif HALFEDGE_H
