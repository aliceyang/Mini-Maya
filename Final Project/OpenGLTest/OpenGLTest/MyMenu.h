#ifndef MYMENU_H
#define MYMENU_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <map>
#include <vector>
#include <QList>
#include "Face.h"
#include "Mesh.h"

class MyMenu: public QMenuBar{

	Q_OBJECT
private:
	map<QTreeWidgetItem*, Face*> fmap;
	vector<Face*> faces;
	vector<HalfEdge*> halfEdges;
	Mesh* mesh;
	
public:
	MyMenu(QWidget *parent = 0);
	~MyMenu();

	
signals:


//================================//
//==========Public Slots==========//
//================================//
public slots:
	









};
#endif MYMENU_H
