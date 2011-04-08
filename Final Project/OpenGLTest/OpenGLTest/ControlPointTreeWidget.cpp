/*
 * ControlPointTreeWidget.cpp
 *
 *  Created on: Apr 22, 2010
 *      Author: hernhgts
 */
#include "ControlPointTreeWidget.h"
#include <QtGui>
#include <QTreeWidgetItem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ControlPointTreeWidget::ControlPointTreeWidget(QWidget *parent):
QTreeWidget(parent){
	s = 4;
	t = 4;
	u = 4;
}

ControlPointTreeWidget::~ControlPointTreeWidget(){

}

//================================//
//==========Public Slots==========//
//================================//
void ControlPointTreeWidget::acceptMesh(Mesh* m){
	//first clear the vertices vector so we can re-add all the elements
	controlPoints.clear();
	clear(); //remove all the qWidgetItems
	cpmap.clear();

	mesh = m;
	controlPoints = m->controlPoints;
	QString v = "Control Point ";

	for(int i = 0; i < controlPoints.size(); i++){
		//set ID's
		QString id = QString::number(controlPoints.at(i)->ID);
		QString name = v + id;
		QStringList qsl(name);

		//make a qWidgetItem for each face and add it to the map
		QTreeWidgetItem* newkid = new QTreeWidgetItem(qsl);
		addTopLevelItem(newkid);

		//adds the ith face and the ith qitem to the fmap
		cpmap[newkid] = controlPoints.at(i);
	}
}

//void VertexTreeWidget::clicked(){
//	emit enableRGB(false);
//}

void ControlPointTreeWidget::setX(double x){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = cpmap[curr];

	currVertex->setX(x);
	mesh->deform(currVertex->ID);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	//mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void ControlPointTreeWidget::setY(double y){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = cpmap[curr];

	currVertex->setY(y);
	mesh->deform(currVertex->ID);
	//Now that a change to the mesh has been made, the display list must
	//be updated
	//mesh->GLWidget->updateDisplayList();

	emit redraw();
}

void ControlPointTreeWidget::setZ(double z){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = cpmap[curr];

	currVertex->setZ(z);
	mesh->deform(currVertex->ID);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	//mesh->GLWidget->updateDisplayList();

	emit redraw();
}

//whenever the widget is clicked; displays coordinates of selected vertex
void ControlPointTreeWidget::activated(){
	QTreeWidgetItem *curr = currentItem();
	Vertex *currVertex = cpmap[curr];

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

//activate Free Form Deformation
void ControlPointTreeWidget::FFD(){
	//mesh->FFD();
	mesh->FFD(s, t, u);
	emit updateMesh();//tells MyGLWidget to resend its mesh; also redraws the mesh
}

void ControlPointTreeWidget::currS(QString sin){
	s = sin.toInt();
}

void ControlPointTreeWidget::currT(QString tin){
	t = tin.toInt();
}

void ControlPointTreeWidget::currU(QString uin){
	u = uin.toInt();
}

