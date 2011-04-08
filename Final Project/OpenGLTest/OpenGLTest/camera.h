/*
 * camera.h
 *
 *  Created on: Mar 21, 2010
 *      Author: Joe Forzano
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>
#include "algebra3.h"
#include "Face.h"
#include "Vertex.h"


using namespace std;

class camera{

public:
	//this vec3 holds the current position of the eye
	vec3 eye;
	//this vec3 holds the current up direction
	vec3 upVector;
	//this vec 3 holds the current side axis (for up and down movement)
	vec3 sideVector;
	//this vec3 holds the reference point
	vec3 referencePoint;
	//this mat4 holds the transformation
	mat4 cameraTransformation;

	//holds the currently selected face
	Face* currentFaceSelection;

	Vertex* selectedVertex;
	//bool decides whether to focus on vertex or face
	bool focusOnVertex;



	//this float holds the current zoom level
	float zoomLevel;
	//***Constructors***//
	//sets up camera at an initial position
	camera();

	//***Getters and Setters***//
	void setEye(float x, float y, float z);
	void setUpVector(float x, float y, float z);
	void setCameraTransformation(mat4 newTransform);
	void setReferencePoint(float x, float y, float z);
	vec3 getEye();
	vec3 getUp();
	mat4 getTransform();

	//Calculate the camera's rotation matrix
	void calculateRotationMatrix();

	//Functions that rotate the camera
	void moveLeftRight(int rotation);
	void moveUpDown(int rotation);
	void zoomIn();
	void zoomOut();

	//panning/pedstalling movement of the camera
	void panLeft();
	void panRight();
	void pedestalUp();
	void pedestalDown();

	//center the scene to the origin
	void centerScene();

	//center scene on selected face/vertex
	void centerOnSelectedFace();
	void centerOnSelectedVertex();



};


#endif /* CAMERA_H_ */
