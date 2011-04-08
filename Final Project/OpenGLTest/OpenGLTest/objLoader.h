#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Face.h"
#include "Vertex.h"
#include "HalfEdge.h"
#include "Mesh.h"

//Reads in a .obj file and outputs a Mesh
class objLoader{

private:
	//values either imported from a mesh
	vector<Face*> faces;
	vector<Vertex*> vertices;
	vector<HalfEdge*> halfEdges;
	char *filename;
	//ifstream myFile;


public:
	objLoader();
	objLoader(char *filename); //takes in a file and opens it

	/*FUNCTIONS*/
	void parse();
	void parseLine(string line);







};
#endif OBJLOADER_H