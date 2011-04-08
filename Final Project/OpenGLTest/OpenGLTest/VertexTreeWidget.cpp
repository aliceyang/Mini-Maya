#include "VertexTreeWidget.h"
#include <QtGui>
#include <QTreeWidgetItem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

VertexTreeWidget::VertexTreeWidget(QWidget *parent):
QTreeWidget(parent){

}

VertexTreeWidget::~VertexTreeWidget(){

}

//================================//
//==========Public Slots==========//
//================================//
void VertexTreeWidget::acceptMesh(Mesh* m){
	//first clear the vertices vector so we can re-add all the elements
	vertices.clear();
	clear(); //remove all the qWidgetItems
	vmap.clear();

	mesh = m;
	vertices = m->vertices;
	halfEdges = m->halfEdges;
	QString v = "vertex ";

	for(int i = 0; i < vertices.size(); i++){
		//set ID's
		QString id = QString::number(vertices.at(i)->ID);
		QString name = v + id;
		QStringList qsl(name);

		//make a qWidgetItem for each face and add it to the map
		QTreeWidgetItem* newkid = new QTreeWidgetItem(qsl);
		addTopLevelItem(newkid);

		//adds the ith face and the ith qitem to the fmap
		vmap[newkid] = vertices.at(i);
	}
}

//void VertexTreeWidget::clicked(){
//	emit enableRGB(false);
//}

void VertexTreeWidget::setX(double x){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];

	currVertex->setX(x);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void VertexTreeWidget::setY(double y){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];

	currVertex->setY(y);
	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void VertexTreeWidget::setZ(double z){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];

	currVertex->setZ(z);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	mesh->GLWidget->updateDisplayList();

	emit redraw();
}

//deletes the currently selected vertex then updates the vertext list
void VertexTreeWidget::deleteVertex(){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];
	mesh->deleteVertex(currVertex);

	emit updateMesh();//tells MyGLWidget to resend its mesh; also redraws the mesh

}

//adds a vertex to the selected vertex edge
void VertexTreeWidget::addVertexToEdge(){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];
	HalfEdge *currEdge;

	//find the halfEdge that points to the vertex.
	for(int i = 0; i < halfEdges.size(); i++){
		if(halfEdges.at(i)->V == currVertex){
			currEdge = halfEdges.at(i);
			break;
		}
	}

	//now add a vertex to that edge using the half edge we just found
	mesh->addVertexToEdge(currEdge);
	std::cout<<"half edge id:"<<currEdge->V->ID<<std::endl;

	emit updateMesh();//tells MyGLWidget to resend its mesh; also redraws the mesh
}

//receives signal from button and sends the selected vertex to FaceTreeWidget 
void VertexTreeWidget::addEdgeBetweenFaces(){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];

	emit addEdgeBetweenFaces(currVertex);
}

//whenever the widget is clicked; displays coordinates of selected vertex
void VertexTreeWidget::activated(){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = vmap[curr];

	//QString x = QString::number(currVertex->v[0]);
	//QString y = QString::number(currVertex->v[1]);
	//QString z = QString::number(currVertex->v[2]);

	emit sendX(currVertex->v[0]);
	emit sendY(currVertex->v[1]);
	emit sendZ(currVertex->v[2]);
	emit enableRGB(false);
	emit enableXYZ(true);
	emit sendVertex(currVertex);
}



