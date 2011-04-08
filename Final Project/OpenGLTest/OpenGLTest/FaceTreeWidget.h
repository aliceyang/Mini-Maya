#ifndef FACETREEWIDGET_H
#define FACETREEWIDGET_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <map>
#include <vector>
#include <QList>
#include "Face.h"
#include "Mesh.h"

class FaceTreeWidget: public QTreeWidget{

	Q_OBJECT
private:
	map<QTreeWidgetItem*, Face*> fmap;
	vector<Face*> faces;
	vector<HalfEdge*> halfEdges;
	Mesh* mesh;
	
public:
	FaceTreeWidget(QWidget *parent = 0);
	~FaceTreeWidget();

	
signals:
	void redraw();
	void updateMesh();
	void sendR(double r);
	void sendG(double g);
	void sendB(double b);
	void sendShine(int shine);
	void sendShineBool(bool enabled);
	void enableXYZ(bool b);
	void enableRGB(bool b);

//================================//
//==========Public Slots==========//
//================================//
public slots:
	void acceptMesh(Mesh* m);
	void acceptFace(Face* f); //selects the clicked face
	void setR(double r);
	void setG(double g);
	void setB(double b);
	void setShine(int shine);
	void enableShine(bool enabled);

	void SplitQuadToTriangles();

	void deleteFace();//deletes a face and replaces with centroid (Geometer operation)

	void addEdgeBetweenFaces(Vertex* v);

	void activated();//when user clicks on this widget. Displays RGB values of selected face









};
#endif FACETREEWIDGET_H
