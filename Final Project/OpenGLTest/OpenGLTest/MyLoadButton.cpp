#include "MyLoadButton.h"
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


MyLoadButton::MyLoadButton(QWidget *parent):
	QPushButton(parent){
		//since OBJ vertices start at index 1, just push in an arbitrary vertex 
		//for index 0 in the vector
		//vertices.push_back(new Vertex(999,999,999)); //comment this out later!! bad implementation!

}

MyLoadButton::~MyLoadButton(){

}


//================================//
//==========Public Slots==========//
//================================//
void MyLoadButton::loadFile(){
	//clear any stored values from before
	faces.clear();
	vertices.clear();
	halfEdges.clear();
	symmap.clear();
	currMaterial = "";
	mtlName = "";
	
	QString qfilename = QFileDialog::getOpenFileName(this, tr("Load Mesh"), "", tr("OBJ Files (*.obj)"));//getting the file name
    //QFile file(filename);

	if(qfilename != NULL){
		string sfilename = qfilename.toStdString(); //converts the qString to a std::string
		//std::cout<<sfilename<<std::endl; 

		//stores the directory file path (to find the .mtl file later)
		//finds last occurances of '/'
		size_t found;
		found = sfilename.find_last_of("/\\");
		currFilePath = sfilename.substr(0, found+1);
		std::cout<<"currFilePath: "<<currFilePath<<std::endl; //PRINT CHECK!


		char* filename;
		filename = new char[sfilename.size() + 1];
		strcpy(filename, sfilename.c_str()); //filename now contains a c-string copy of sfilename
		//std::cout<<"OBJ filename: "<<filename<<std::endl;

		//makes a file object
		ifstream myFile(filename); 
		
		//process the file object
		string line;

		while(!myFile.eof()){
			getline(myFile, line);
			//std::cout << "Processing: " << line << std::endl;
			if(line != ""){
				processLine(line);
			}
		}
		//TO IMPLEMENT: LINK HALFEDGE SYMS
		linkSyms();
		myFile.close();
		createMesh(); //creates mesh and emits it in a signal to MyGLWidget
	}
}

//Parsese a line in an OBJ file
void MyLoadButton::processLine(std::string line){
	string keyword;
	stringstream stream(line); //makes io stream from the line
	stream >>keyword; //the first word in the line

	if(keyword == "mtllib"){ //opens the mtl file
		openMtllib(line);
	}
	else if(keyword == "usemtl"){
		string m;
		stream >> m; //retrieves the material name
		currMaterial = m; //sets current Material to m. subsequent faces will be colored if m is found in matmap
		std::cout<<"currMaterial: "<< currMaterial<<std::endl; 
	}
	else if(keyword == "v"){
		processVector(line);
	}
	else if(keyword == "f"){
		processFace(line);
	}
	
}

//Processes a Vertex in an OBJ file
void MyLoadButton::processVector(string line){
	string vectorData = line.substr(2, line.length() - 1); //all the data after the 'v '
	stringstream stream(vectorData); //creates an io stream from the vectorData
	
	float x,y,z; //initialize floats
	stream>>x>>y>>z; //retrieves float values from the stream
	vertices.push_back(new Vertex(x,y,z)); //adds Vertex to vertices vector
	//std::cout<<"new vertex added: "; //PRINT CHECK!
	//vertices.at(vertices.size() - 1)->print();

	//Note: Keep in mind that vector indices start at 1 (given format of OBJ file). The
	//0th index in vertices is an arbitrary Vertex (999,999,999)


	//OLD CODE. DO NOT USE.
	//string word;
	//vector<float> floats; //vector to store each coordinate
	//while(getline(stream, word, ' ')){ //split the stream by spaces (delimiter)
	//	double d = atof(word.c_str()); //converts string to double
	//	float f = d; //converts double to float
	//	floats.push_back(f); //pushes float into float vector
	//}
	//vertices.push_back(new Vertex(floats[0], floats[1], floats[2])); //adds a new Vertex to the vertices vector
	//std::cout<<"new vertex added: ";
	//vertices.at(vertices.size() - 1)->print();

}

//Processes a Face in an OBJ file
void MyLoadButton::processFace(string line){
	Face* face = new Face();
	HalfEdge* start = new HalfEdge();
	halfEdges.push_back(start);
	face->HE = start;
	HalfEdge* current = start;

	string faceData = line.substr(2, line.length() - 1); //all the data after the 'f '
	stringstream stream(faceData); //creates an io stream for the face data
	//this time we cannot just use >>operator since we're not sure how many vertices each face has

	string word;
	vector<Vertex*> facevs; //vector containing vertices in this face
	while(getline(stream, word, ' ')){ //split the stream using space as delimiter
		int i = atoi(word.c_str()); //converts string to int
		//std::cout<<"face i:"<<i<<std::endl;
		//facevs.push_back(vertices.at(i)); //comment this out later!!
		facevs.push_back(vertices.at(i-1)); //pushes vertex into vs vector (note that vertices start at 1, so we need to minus one when accessing vertex vector)
	}

	//sets the NEXT, F, and V values for each halfEdge in the face.
	for(int i = 0; i < facevs.size(); i++){
		if(i == facevs.size() - 1){
			current->F = face;
			current->V = facevs.at(i);
			current->NEXT = start;
		}
		else{
			current->F = face;
			current->V = facevs.at(i);
			HalfEdge* next = new HalfEdge();
			halfEdges.push_back(next);
			current->NEXT = next;
			current = next;
		}
	}

	//sets up the symmap
	HalfEdge *origEdge = face->HE;
	HalfEdge *currEdge = origEdge;
	do{
		Vertex *vStart = currEdge->V;
		Vertex *vEnd = currEdge->NEXT->V; //currEdge->Next is the HE between vStart and vEnd
		
		//Enter the vertices backwards, so when you iterate through map later, this edge will
		//be the SYM of the halfEdge between those vertices.
		pair<Vertex*, Vertex*> vpair(vEnd,vStart);
		symmap[vpair] = currEdge->NEXT;

		currEdge = currEdge->NEXT;
	}while(origEdge != currEdge);

	//if the currMaterial exists in the material map(matmap), then apply the material to this face
	if(matmap.count(currMaterial) > 0){
		face->material = matmap[currMaterial];
	}

	//finally push this face into the faces vector
	faces.push_back(face);
	//std::cout<<"face size check: "<<faces.size()<<std::endl;
	//std::cout<<"edges check: "<<face->numEdges()<<std::endl;

	//checking stuff
	//std::cout<<"checking stuff"<<std::endl;
	//for(int i = 0; i < faces.size(); i++){
	//	Face* f = faces.at(i);
	//	HalfEdge *orig = f->HE;
	//	HalfEdge *curr = orig;
	//	do{
	//		curr->V->print();
	//		curr = curr->NEXT;
	//	}while(orig != curr);
	//}
}

//Iterates through the symmap. Finds the HalfEdge for the Vertex pair, and sets its
//SYM to the halfEdge value of that key-value entry. 
void MyLoadButton::linkSyms(){
	std::cout<<"start linkSyms"<<std::endl;
	std::map<pair<Vertex*, Vertex*>, HalfEdge*>::iterator it;
	for(it = symmap.begin(); it!=symmap.end(); ++it){
		pair<Vertex*, Vertex*> vpair = it->first; 
		Vertex* vStart = vpair.first;
		Vertex* vEnd = vpair.second;
		HalfEdge* symEdge = it->second;

		//Find the HE (currEdge) between vStart and vEnd, and set its SYM to symEdge and vice versa
		for(int i = 0; i < halfEdges.size(); i++){
			HalfEdge* origEdge = halfEdges.at(i);
			HalfEdge* prevEdge = origEdge; //loop using prevEdge, since it's easier to find its NEXT edge rather than looping back to find a previous edge
			do{
				HalfEdge *currEdge = prevEdge->NEXT;
				if(prevEdge->V == vStart && currEdge->V == vEnd){
					//std::cout<<"sym edge found!!!"<<std::endl;
					currEdge->SYM = symEdge;
					break; //breaks out of immediate while loop
					break; //breaks out of forloop
					//symEdge->SYM = currEdge;
				}
				prevEdge = prevEdge->NEXT;
			}while(origEdge != prevEdge);
		}
	}
	std::cout<<"linksyms complete!"<<std::endl;
	std::cout<<""<<std::endl;
}

//Creates a Mesh and emits it
void MyLoadButton::createMesh(){
	Mesh *mesh = new Mesh();
	mesh->faces = faces;
	mesh->vertices = vertices;
	mesh->halfEdges = halfEdges;
	//Mesh *mesh = Mesh::makeCube();

	emit sendMesh(mesh);
}

//opens the mtl file, creates all material objects, and maps them to their names
void MyLoadButton::openMtllib(std::string line){
	std::cout<<"openMtllib started"<<std::endl;
	string mtlData = line.substr(7, line.length() - 1); //all the words after the 'mtllib '
	mtlName = mtlData;
	//std::cout<<"mtlName: "<<mtlName<<std::endl; //PRINT CHECK!!

	mtlData = currFilePath + mtlData; //add file path in front of name. We assume the MTL file is in the same directory as the OBJ
	//std::cout<<"mtlData: "<<mtlData<<std::endl; //PRINT CHECK!

	//convert string filename into char*
	char* filename;
	filename = new char[mtlData.size() + 1];
	strcpy(filename, mtlData.c_str()); //filename now contains a c-string copy of sfilename

	std::cout<<"MTL filename: "<<filename<<std::endl; //mtl file name PRINT CHECK!!
	ifstream mtlFile(filename); //creates input file object from the file name after 'mtllib'
	string mtline;
	Material *currMaterial; //keeps track of which material we're on
	
	while(!mtlFile.eof()){
		getline(mtlFile, mtline);//sets mtline 
		stringstream stream(mtline); //makes io stream from the line
		string keyword; //initialize keyword
		stream >>keyword; //set keyword to the first word in the line

		if(keyword == "newmtl"){
			currMaterial = makeNewMaterial(mtline); //makes a new material and sets this as currMaterial
		}
		else if(keyword == "Ka"){
			float x,y,z;
			stream>>x>>y>>z;
			currMaterial->ka[0] = x;
			currMaterial->ka[1] = y;
			currMaterial->ka[2] = z;
			//std::cout<<"Ka check: "<<x<<","<<y<<","<<z<<std::endl;
		}
		else if(keyword == "Kd"){
			float x,y,z;
			stream>>x>>y>>z;
			currMaterial->kd[0] = x;
			currMaterial->kd[1] = y;
			currMaterial->kd[2] = z;
			//std::cout<<"Kd check: "<<x<<","<<y<<","<<z<<std::endl;
		}
		else if(keyword == "Ks"){
			float x,y,z;
			stream>>x>>y>>z;
			currMaterial->ks[0] = x;
			currMaterial->ks[1] = y;
			currMaterial->ks[2] = z;
			//std::cout<<"ks check: "<<x<<","<<y<<","<<z<<std::endl;
		}
		else if(keyword == "d" || mtline == "Tr"){
			float x;
			stream>>x;
			currMaterial->d = x;
			currMaterial->tr = x;
			//std::cout<<"tr check: "<<x<<std::endl;
		}
		else if(keyword == "Ns"){
			float x;
			stream>>x;
			currMaterial->ns = x;
			//std::cout<<"ns check: "<<x<<std::endl;
		}
		else if(keyword == "illum"){
			int x;
			stream>>x;
			currMaterial->illum = x;
			//std::cout<<"illum check: "<<x<<std::endl;
		}
	}
	mtlFile.close();
	std::cout<<"openMTllib completed"<<std::endl;

}

//makes new material from a given std::string line (newmtl) and returns a pointer to it
//adds the name + Material into the material map (matmap)
Material* MyLoadButton::makeNewMaterial(std::string line){
	string vectorData = line.substr(7, line.length() - 1); //all the data after the 'newmtl '
	stringstream stream(vectorData); //creates an io stream from the vectorData
	string name;
	stream >> name; //name of the Material
	
	std::cout<<"New Material " <<name<<" loaded!"<<std::endl;

	Material *mat = new Material();
	mat->name = name; //sets the material's name
	matmap[name] = mat; //adds the name + Material into the material map (matmap)
	return mat; //return pointer of the newly created Material
}


//receives exportButton's mtlname request and emits the mtlname
void MyLoadButton::acceptMtlRequest(){
	emit sendMtl(mtlName);
}