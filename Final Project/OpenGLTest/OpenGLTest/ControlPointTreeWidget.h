/*
 * ControlPointTreeWidget.h
 *
 *  Created on: Apr 22, 2010
 *      Author: hernhgts
 */

#ifndef CONTROLPOINTTREEWIDGET_H_
#define CONTROLPOINTTREEWIDGET_H_
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <map>
#include <vector>
#include "Vertex.h"
#include "Mesh.h"
#include "HalfEdge.h"


class ControlPointTreeWidget: public QTreeWidget{

	Q_OBJECT
private:
	map<QTreeWidgetItem*, Vertex*> cpmap;
	vector<Vertex*> controlPoints;
	Mesh* mesh;

	//for FFD
	int s;
	int t;
	int u;

public:
	ControlPointTreeWidget(QWidget *parent = 0);
	~ControlPointTreeWidget();

signals:
	void redraw();
	//void enableRGB(bool b)
	void updateMesh();
	void sendX(double s);
	void sendY(double s);
	void sendZ(double s);
	void enableXYZ(bool b);
	void enableRGB(bool b);
	void sendVertex(Vertex*);

//================================//
//==========Public Slots==========//
//================================//
public slots:
	void acceptMesh(Mesh* m);
	//void clicked();
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	void activated(); //whenever the widget is clicked; displays coordinates of selected vertex

	void FFD();

	void currS(QString sin);
	void currT(QString tin);
	void currU(QString uin);


};


#endif /* CONTROLPOINTTREEWIDGET_H_ */
