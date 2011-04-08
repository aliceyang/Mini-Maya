#ifndef MYLOADBUTTON_H
#define MYLOADBUTTON_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include "Face.h"
#include "Vertex.h"
#include "HalfEdge.h"
#include "Material.h"
#include "Mesh.h"



using namespace std;

/*QPushButton that handles mesh importing*/
class MyLoadButton: public QPushButton{

	Q_OBJECT
private:
	vector<Face*> faces;
	vector<Vertex*> vertices;
	vector<HalfEdge*> halfEdges;
	map<pair<Vertex*, Vertex*>, HalfEdge*> symmap; //maps pairs of vertices to halfEdge to estb SYM values later
	map<string, Material*> matmap; //maps the material name to the material object
	string currMaterial; //keeps track of the material read in (empty if none)
	string currFilePath; //keeps track of directory of files
	string mtlName;


	
public:
	MyLoadButton(QWidget *parent = 0);
	~MyLoadButton();

//================================//
//==========Public Functions======//
//================================//
	void processLine(string line);
	void processVector(string line);
	void processFace(string line);

	void linkSyms();
	void createMesh();

	//functions for reading in a mtllib file
	void openMtllib(string line);
	Material* makeNewMaterial(string line);



//================================//
//==========Public Slots==========//
//================================//
public slots:
	void loadFile();
	void acceptMtlRequest();

//================================//
//==========Public Signals========//
//================================//
signals:
	void sendMesh(Mesh* mesh);
	void sendMtl(string mtl);
	









};
#endif MYLOADBUTTON_H
