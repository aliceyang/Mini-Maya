#include "MyExportButton.h"
#include <QtGui>
#include <iostream>
#include <string>
#include <QFileDialog>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

MyExportButton::MyExportButton(QWidget *parent):QPushButton(parent){
	//nothing to see here

}

MyExportButton::~MyExportButton(){
	//nothing to see here
}


//================================//
//==========Public Slots==========//
//================================//


void MyExportButton::exportFile(){
	//nothing to see here
	std::cout<<"Exporting File"<<std::endl;
	emit requestMesh(); //when GLWidget sendsMesh -> slot: acceptMesh(). mesh should be established now
	emit requestMtl();

	//retrieve the face and vertice information from the mesh
	faces = mesh->faces;
	vertices = mesh->vertices; 

	//now create an OBJ file and write the data to it
	QString qfilename = QFileDialog::getSaveFileName(this, tr("Export OBJ"), "", tr("OBJ Files (*.obj)"));//setting the file name
	string sfilename = qfilename.toStdString(); 

	char* filename;
	filename = new char[sfilename.size() + 1];
	strcpy(filename, sfilename.c_str()); //filename now contains a c-string copy of sfilename

	ofstream myFile(filename); //makes a file object

	//WRITE TO FILE OBJECT
	//myFile<<"hello\n"<<75; //testing

	if(mtlname != ""){
		myFile<<"mtllib "<<mtlname <<"\n";
	}

	//write all the vertices
	for(int i = 0; i < vertices.size(); i++){
		myFile<<"v "<<vertices.at(i)->getX()<<" "<<vertices.at(i)->getY()<<" "<<vertices.at(i)->getZ()<<"\n";
	}

	//now write all the file names
	if(mtlname != ""){
		mtltracker = faces.at(0)->material->name; //initialize mtltracker
		myFile<<"usemtl "<<mtltracker<<"\n";
	}
	
	for(int i = 0; i < faces.size(); i++){
		if(mtlname != ""){
			string currmtlname = faces.at(i)->material->name;
			if(mtltracker != currmtlname){
				mtltracker = currmtlname;
				myFile<<"usemtl "<<mtltracker<<"\n";
			}
		}
		vector<Vertex*> vs; //stores the vertices of this face
		myFile<<"f ";
		Face *face = faces.at(i);
		HalfEdge *orig = face->HE;
		HalfEdge *curr = orig;

		do{
			vs.push_back(curr->V);
			curr = curr->NEXT;
		}while(curr != orig);

		//loops through vector of vertices and finds its index. Prints out to index+1 since OBJ indices start at 1
		for(int i = 0; i < vs.size(); i++){
			for(int j = 0; j < vertices.size(); j++){
				if(vs.at(i) == vertices.at(j)){
					myFile<<j+1<<" ";
					break;
					break;
				}
			}
		}
		myFile<<"\n";
	}
	
	myFile.close();

}

//accepts a mesh from MyGLWidget
void MyExportButton::acceptMesh(Mesh* m){
	mesh = m;
	std::cout<<"check: Mesh accepted to Export button"<<std::endl;
}

//accepts mtlname info from load button
void MyExportButton::acceptMtl(std::string mtl){
	mtlname = mtl;
	std::cout<<"received mtlname from loadbutton: "<<mtlname<<std::endl;
}
