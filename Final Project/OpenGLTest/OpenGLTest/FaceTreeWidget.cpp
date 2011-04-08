#include "FaceTreeWidget.h"
#include <QtGui>
#include <QList>
#include <QTreeWidgetItem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

FaceTreeWidget::FaceTreeWidget(QWidget *parent):
QTreeWidget(parent){

}

FaceTreeWidget::~FaceTreeWidget(){

}

//================================//
//==========Public Slots==========//
//================================//
void FaceTreeWidget::acceptMesh(Mesh* m){
	std::cout<<"Mesh accepted"<<std::endl;
	//first clear the face vector so we can re-add all the elements
	faces.clear();
	clear(); //remove all qWidgetItems
	fmap.clear();//clear the fmap

	mesh = m;
	faces = m->faces;
	halfEdges = m->halfEdges;
	QString v = "Face ";

	for(int i = 0; i < faces.size(); i++){
		//set ID's
		QString id = QString::number(faces.at(i)->ID);
		QString name = v + id;
		QStringList qsl(name);

		//make a qWidgetItem for each face and add it to the map
		QTreeWidgetItem* newkid = new QTreeWidgetItem(qsl);
		addTopLevelItem(newkid);

		//adds the ith face and the ith qitem to the fmap
		fmap[newkid] = faces.at(i);
	}
}

//sets the current selection to the sent face
void FaceTreeWidget::acceptFace(Face* f){
	std::cout<<"acceptFace check"<<std::endl;
	//iterates through the fmap and checks whether the currFace equals the sent one
	//if so, sets the current item to the corresponding QTreeWidgetItem
	std::map<QTreeWidgetItem*, Face*>::iterator it;
	for(it = fmap.begin(); it!=fmap.end(); ++it){
		Face* currFace = it->second;
		if(currFace == f){
			std::cout<<"check"<<std::endl;
			setCurrentItem(it->first);
			activated(); //updates the RGB spinboxes for the selected Face
			break;
		}
	}
}

void FaceTreeWidget::setR(double r){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];

	currFace->origR = r;
	currFace->R = r;

	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void FaceTreeWidget::setG(double g){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];

	currFace->origG = g;
	currFace->G = g;

	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void FaceTreeWidget::setB(double b){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];

	currFace->origB = b;
	currFace->B = b;

	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void FaceTreeWidget::setShine(int shine){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];

	currFace->material->ns = (float)shine;
	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void FaceTreeWidget::enableShine(bool enabled){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];
	if (enabled){
		currFace->material->illum = 2;
	}
	else{
		currFace->material->illum = 1;

		emit redraw();
	}
}

//Splits the selected quad face into triangles
void FaceTreeWidget::SplitQuadToTriangles(){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];
	
	mesh->SplitQuadToTriangles(currFace);
	emit updateMesh();
}

//Deletes a face and replaces with centroi(Geometer function)
void FaceTreeWidget::deleteFace(){
	QTreeWidgetItem *curr = currentItem();
	Face *currFace = fmap[curr];

	mesh->deleteFace(currFace);
	emit updateMesh();
}

//accepts a Vector pointer from VertexTreeWidget and uses it to add an edge
//between two selected faces
void FaceTreeWidget::addEdgeBetweenFaces(Vertex *v){
	QList<QTreeWidgetItem*> currFaces = selectedItems(); //the two selected faces
	Face* faceA = fmap[currFaces.at(0)];
	Face* faceB = fmap[currFaces.at(1)];


	mesh->addEdgeBetweenFaces(faceA, faceB, v);
	emit updateMesh();
}

void FaceTreeWidget::activated(){
	QTreeWidgetItem *curr = currentItem();
	Face* currFace = fmap[curr];

	emit sendR(currFace->origR);
	emit sendG(currFace->origG);
	emit sendB(currFace->origB);
	emit sendShine((int)currFace->material->ns);
	emit enableXYZ(false);
	emit enableRGB(true);
	if (currFace->material->illum == 2){
		emit sendShineBool(true);
	}
	else{
		emit sendShineBool(false);
	}
}
