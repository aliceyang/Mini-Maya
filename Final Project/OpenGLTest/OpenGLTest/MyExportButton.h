#ifndef MYEXPORTBUTTON_H
#define MYEXPORTBUTTON_H
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
#include "Mesh.h"



using namespace std;

/*QPushButton that handles mesh importing*/
class MyExportButton: public QPushButton{

	Q_OBJECT
private:
	Mesh *mesh;
	vector<Face*> faces;
	vector<Vertex*> vertices;
	vector<HalfEdge*> halfEdges;
	string mtlname; //name of the mtl file
	string mtltracker;//keeps track of what material is written


	
public:
	MyExportButton(QWidget *parent = 0);
	~MyExportButton();

//================================//
//==========Public Functions======//
//================================//
	



//================================//
//==========Public Slots==========//
//================================//
public slots:
	void exportFile();
	void acceptMesh(Mesh* m); //accepts the mesh from MyGLWidget
	void acceptMtl(string mtl);

//================================//
//==========Public Signals========//
//================================//
signals:	
	void requestMesh(); //makes MyGLWidget emit its mesh
	void requestMtl(); //makes myLoadButton emit its mtlname









};
#endif MYEXPORTBUTTON_H
