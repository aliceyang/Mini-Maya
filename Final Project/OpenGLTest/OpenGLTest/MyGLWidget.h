/* see the comments in the .cpp file for details about the functions */

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QTimer>
#include <QWheelEvent>
#include <QMouseEvent>
#include <vector>
#include "algebra3.h"
#include "camera.h"
#include "Mesh.h"
#include "Light.h"

class Mesh;

class MyGLWidget: public QGLWidget{ //inherit from QGLWidget
	Q_OBJECT //tell Qt that this is a Qt object.  Don't erase this.

public:
	MyGLWidget(QWidget *parent = 0);
	~MyGLWidget();
	void initializeGL(); //initialize some parameters for OpenGL
	void paintGL(); //paints the scene
	void resizeGL(int, int); //sets the initial projection and handles
							//resizing
	void keyPressEvent(QKeyEvent *e); //add code for processing keystrokes here.  keep it simple!

//	void wheelEvent(QWheelEvent *event); //handles zoom with the mouse wheel
	void mousePressEvent(QMouseEvent *event); //handles rotation with left mouse click
	void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
	void dragRotate(const int &endX, const int &endY);//rotates the cube from prevX to endX, and prevY to endY

	//FOR HOMEWORK 7
	void drawRay(); //draws the ray using eyeAtClick and directionAtClick
	void clickSelect(); //selects the closest face to the eye
	double distBetweenTwoVecs(vec3 v1, vec3 v2); //finds the distance between 2 vec3's

	//This method updates the display list. *****Must be called whenever a change to the mesh has been made
	void updateDisplayList();

	//these methods enable/disable lighting
	void enableLighting();
	void disableLighting();

	//set up views
	void topView();
	void rightProfile();
	void leftProfile();
	void frontView();
	void backView();
	void bottomView();
	void perspective();

private:
	camera *cam; //camera

	int prevX, prevY; //keeps track of initial cube positions before click rotation
	
	//FOR HOMEWORK 6
	Mesh *m;

	//FOR HOMEWORK 7
	vec3 P;
	vec3 rayStart;
	vec3 rayEnd;
	
	//FOR FINAL PROJECT
	//this integer stores the index of the display list
	int displayListIndex;

	//this boolean tells whether lighting is enabled
	bool lightingEnabled;

	//vector of lights
	vector<Light*> lights;

	//tells whether to be in orthographic or not
	bool orthographicView;
	//tells whether rotation should be disabled or not
	bool rotationDisabled;
	//stores original position of eye when switching out of perspective view
	vec3 storedEye;
	vec3 storedUp;
	vec3 storedSide;
	vec3 storedRef;
	//bools used for toggling in and out of views
	bool inPerspectiveView;

public slots:
	void drawMesh();
	void resendMesh();//resends the mesh to the 2 tree widgets
	void smooth();
	void recieveSelectedVertex(Vertex * vertex);

	//GUI testing
	void receiveMesh(Mesh* mesh); //receives mesh from load button
	void receiveMeshRequest(); //receives request from export button and sends the mesh

signals:
	void sendMesh(Mesh* mesh);
	void sendFace(Face* face); //send a signal containing which face was clicked
	//send the lights to the lightList
	void sendLights(Light*);


};

#endif MYGLWIDGET_H
