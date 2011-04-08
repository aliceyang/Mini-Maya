#ifndef FACE_H
#define FACE_H
#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include <vector>
#include "HalfEdge.h"
#include "Vertex.h"
#include "Material.h"
class HalfEdge; //forward declaration

class Face{
public:
	HalfEdge *HE;
	float R,G,B;
	float origR, origG, origB; //stores the original colors (never changes)
	int ID;
	Vertex *centroid;
	int selected; //keeps track of whether to highligh the face
	vector < HalfEdge* > edges2; //for use in smoothing
	int numF; //hold the number of faces from before smoothing
	Material *material;

	//constructor/destructor
	Face();
	Face(int id);
	~Face();

	//Functions
	void setRGB(float r, float g, float b);
	int numEdges();
	Vertex* getCentroid();

	//Catmull-Clark implementation : http://www.rorydriscoll.com/2008/08/01/catmull-clark-subdivision-the-basics/
	vector < Face* > smooth(vector < Vertex* > vertices, float r, float g, float b); //inputs allow new faces to have different colors

	//corrects for symmetrical edges in smooth
	//should only be called after all faces in mesh have called smooth
	//(some edges symmetrical edges are not created when initial smooth is called
	void adjustSym();

	void select();

	//FFD methods
	float minX(); //returns the min x value (compared to all vertices of the face)
	float minY();
	float minZ();

	float maxX();
	float maxY();
	float maxZ();

};

#endif FACE_H
