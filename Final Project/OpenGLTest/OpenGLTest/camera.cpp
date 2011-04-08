/*
 * camera.cpp
 *
 *  Created on: Mar 21, 2010
 *      Author: jayfo
 */

#include "camera.h"
#include <math.h>

#define pi 3.14159

//***Constructors***//
//sets up camera at an initial position
camera::camera(){
	//start the camera with the eye at (0,0,6), up
	//being in the positive y direction, and from that
	//calculate the initial camera transform
	zoomLevel = 6.0;
	eye = vec3(0.0, 0.0, zoomLevel);
	upVector = vec3(0.0, 1.0, 0.0);
	sideVector = vec3(1.0, 0.0, 0.0);
	referencePoint = vec3(0.0,0.0,0.0);
	currentFaceSelection = 0;
	calculateRotationMatrix();

}

//***Getters and Setters***//
void camera::setEye(float x, float y, float z){
	eye[0] = x;
	eye[1] = y;
	eye[2] = z;
}
void camera::setUpVector(float x, float y, float z){
	upVector[0] = x;
	upVector[1] = y;
	upVector[2] = z;
}
void camera::setCameraTransformation(mat4 newTransform){
	cameraTransformation = newTransform;
}
void camera::setReferencePoint(float x, float y, float z){
	referencePoint[0] = x;
	referencePoint[0] = y;
	referencePoint[0] = z;
}
vec3 camera::getEye(){
	return eye;
}
vec3 camera::getUp(){
	return upVector;
}
mat4 camera::getTransform(){
	return cameraTransformation;
}

//Calculate the camera's rotation matrix
void camera::calculateRotationMatrix(){
	//Use the current eye vector and up direction to calculate the
	//camera's rotation matrix focused on the origin
	vec3 viewReference(0.0,0.0,0.0);

	/* First we create three vectors that will represent
	 * the three rows of our new transformation matrix
	 */
	vec3 row1, row2, row3;

	/* row3 holds our view plane normal, which we
	 * get from subtracting the viewReference from
	 * the eye vector, and then normalizing
	 */
	row3 = eye - viewReference;
	row3.normalize();

	/*row1 is the x vector, which is computed by finding
	 * the cross product of the up direction and
	 * the z vector
	 * X = upVector x Z
	 * ***^ operator is defined as cross product
	 */
	row1 = upVector ^ row3;

	/*row2 is the y vector, which is computed by finding
	 * the cross product of the z vector and the new
	 * x vector
	 * Y = X x Z
	 * ***^ operator is defined as the cross product
	 */
	row2 = row3 ^ row1;

	//normalize the newly calculated row1 and row2
	row1.normalize();
	row2.normalize();

	//create the rotation matrix
	cameraTransformation = mat4(vec4(row1[0],row1[1],row1[2],0.0),
			vec4(row2[0],row2[1],row2[2],0.0),
			vec4(row3[0],row3[1],row3[2],0.0),
			vec4(0.0,0.0,0.0,1.0) );

	//translate eye out from origin
		//First, create the 3d translation matrix
		vec3 trans(0.0, 0.0, -zoomLevel);
		mat4 translationMatrix = translation3D(trans);
		//change the current transform matrix to include this translation
		cameraTransformation = translationMatrix * cameraTransformation;
}


//Functions that move the camera



void camera::moveLeftRight(int rotation){
	//if the reference point is not the origin, we have to translate to the
	//origin, rotate, then translate back

	//first, calculate the difference between the
	//reference point and the origin
	vec3 difference = referencePoint - vec3(0.0,0.0,0.0);

	//translate the eye by this value to center it back
	//around the origin
	vec3 newEye = eye - difference;

	//create a vec4 to be used for the rotation calculation
	vec4 eyeForRotation(newEye[0], newEye[1], newEye[2], 1);

	//create the rotation for the camera
	mat4 rotationMatrix = rotation3D(upVector, rotation);
	eyeForRotation = rotationMatrix * eyeForRotation;

	//translate the eye back
	newEye = vec3(eyeForRotation[0], eyeForRotation[1], eyeForRotation[2]);
	newEye = newEye + difference;
	setEye(newEye[0], newEye[1], newEye[2]);

	//create the rotation for the sideVector
	vec4 newSideVector(sideVector[0], sideVector[1], sideVector[2], 1);
	//rotate the upVector around the upVector
	mat4 sideVectorRotationMatrix = rotation3D(upVector, rotation);
	newSideVector = sideVectorRotationMatrix * newSideVector;
	sideVector[0] = newSideVector[0];
	sideVector[1] = newSideVector[1];
	sideVector[2] = newSideVector[2];
	calculateRotationMatrix();
}

void camera::moveUpDown(int rotation){
	//if the reference point is not the origin, we have to translate to the
	//origin, rotate, then translate back

	//first, calculate the difference between the
	//reference point and the origin
	vec3 difference = referencePoint - vec3(0.0,0.0,0.0);

	//translate the eye by this value to center it back
	//around the origin
	vec3 newEye = eye - difference;

	//create a vec4 to be used for the rotation calculation
	vec4 eyeForRotation(newEye[0], newEye[1], newEye[2], 1);

	//create the rotation for the camera
	mat4 rotationMatrix = rotation3D(sideVector, rotation);
	eyeForRotation = rotationMatrix * eyeForRotation;

	//translate the eye back
	newEye = vec3(eyeForRotation[0], eyeForRotation[1], eyeForRotation[2]);
	newEye = newEye + difference;
	setEye(newEye[0], newEye[1], newEye[2]);

	//create the rotation for the up Vector
	vec4 newUpVector(upVector[0], upVector[1], upVector[2], 1);
	//rotate the upVector around the sideVector
	mat4 upVectorRotationMatrix = rotation3D(sideVector, rotation);
	newUpVector = upVectorRotationMatrix * newUpVector;
	setUpVector(newUpVector[0], newUpVector[1], newUpVector[2]);

	//calculate Rotation Matrix
	calculateRotationMatrix();

}



void camera::zoomIn(){

	if (zoomLevel == 3){
		return;
	}
	else{
		zoomLevel--;

		vec3 viewDirection = eye;
		viewDirection.normalize();
		eye = eye - viewDirection;
	}
	calculateRotationMatrix();

}

void camera::zoomOut(){

	if (zoomLevel == 19){
		return;
	}
	else{
		zoomLevel++;
		vec3 viewDirection = eye;
		viewDirection.normalize();
		eye = eye + viewDirection;
	}
	calculateRotationMatrix();
}


//functions for panning and pestalling the camera

/*this function will pan left with the camera, therefore moving both the eye and
 * reference point to the left as opposed to rotating around the reference point
 */
void camera::panLeft(){
	//move the reference point 1 step along the negative sideVector direction
	referencePoint = referencePoint - sideVector;
	eye = eye - sideVector;
}

void camera::panRight(){
	referencePoint = referencePoint + sideVector;
	eye = eye + sideVector;
}

void camera::pedestalUp(){
	referencePoint = referencePoint + upVector;
	eye = eye + upVector;
}

void camera::pedestalDown(){
	referencePoint = referencePoint - upVector;
	eye = eye - upVector;
}


//centers the camera in the scene
void camera::centerScene(){
	zoomLevel = 6.0;
	eye = vec3(0.0, 0.0, zoomLevel);
	upVector = vec3(0.0, 1.0, 0.0);
	sideVector = vec3(1.0, 0.0, 0.0);
	referencePoint = vec3(0.0,0.0,0.0);
	calculateRotationMatrix();
}

//center scene on selected face
void camera::centerOnSelectedFace(){
	//if no face is selected, do nothing
	if (currentFaceSelection == 0){
		return;
	}
	else{
		//calculate the centroid of the face
		Vertex* centroid = currentFaceSelection->getCentroid();
		vec3 centroidPoint(centroid->v[0], centroid->v[1], centroid->v[2]);

		//find the difference between the centroid and the reference point
		vec3 difference = centroidPoint - referencePoint;

		//set the camera's reference point to the centroid point
		referencePoint = centroidPoint;

		//translate the camera's eye by this same difference
		eye = eye - difference;

		//reset the sideVector

		//find the distance between the eye and the reference point
		float distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
				+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
				+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));

		//either zoom in or zoom out until distance is around 6
		if (distance > 6.0){
			do{
				//if it's farther away, zoom in
				zoomIn();
				//recalculate distance
				distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
								+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
								+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));
			}while(distance > 6.0);
		}
		else{
			do{
				//if it's too close zoom out
				zoomOut();
				//recalculate distance
				distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
								+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
								+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));
			}while(distance < 6.0);

		}

	}
}

void camera::centerOnSelectedVertex(){
	//if no vertex is selected, do nothing
	if (selectedVertex == 0){
		return;

	}
	else{

		vec3 centroidPoint(selectedVertex->v[0], selectedVertex->v[1], selectedVertex->v[2]);

		//find the difference between the centroid and the reference point
		vec3 difference = centroidPoint - referencePoint;

		//set the camera's reference point to the centroid point
		referencePoint = centroidPoint;

		//translate the camera's eye by this same difference
		eye = eye - difference;

		//reset the sideVector

		//find the distance between the eye and the reference point
		float distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
				+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
				+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));

		//either zoom in or zoom out until distance is around 6
		if (distance > 8.0){
			do{
				//if it's farther away, zoom in
				zoomIn();
				//recalculate distance
				distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
								+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
								+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));
			}while(distance > 8.0);
		}
		else{
			do{
				//if it's too close zoom out
				zoomOut();
				//recalculate distance
				distance = sqrt((eye[0]-referencePoint[0])*(eye[0]-referencePoint[0])\
								+ (eye[1]-referencePoint[1])*(eye[1]-referencePoint[1])\
								+ (eye[2]-referencePoint[2])*(eye[2]-referencePoint[2]));
			}while(distance < 8.0);

		}

	}
}




