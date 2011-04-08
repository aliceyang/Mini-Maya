#ifndef VERTEXTREEWIDGET_H
#define VERTEXTREEWIDGET_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <map>
#include <vector>
#include "Vertex.h"
#include "Mesh.h"
#include "HalfEdge.h"

class VertexTreeWidget: public QTreeWidget{

	Q_OBJECT
private:
	map<QTreeWidgetItem*, Vertex*> vmap;
	vector<Vertex*> vertices;
	vector<HalfEdge*> halfEdges;
	Mesh* mesh;

public:
	VertexTreeWidget(QWidget *parent = 0);
	~VertexTreeWidget();

signals:
	void redraw();
	//void enableRGB(bool b)
	void updateMesh();
	void addEdgeBetweenFaces(Vertex* v);
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

	void deleteVertex();//deletes the currently selected vertex
	void addVertexToEdge();//adds a vertex using a vertex and a face
	void addEdgeBetweenFaces();//receives signal from button and sends out vertex to FaceTreeWidget

	void activated(); //whenever the widget is clicked; displays coordinates of selected vertex



};

#endif VERTEXTREEWIDGET_H
