/*
 * Light.cpp
 *
 *  Created on: Apr 21, 2010
 *      Author: jayfo
 */

#include "Light.h"
#include <iostream>
#include <QtOpenGL>

using namespace std;

//initialize the IDCounter
int Light::currentID = 0;


//creates a light with default settings
Light::Light(){

	//default ambient light is a white light at .8 intensity
	ambientR = .2;
	ambientG = .2;
	ambientB = .2;

	//default diffuse light is a white light at .2 intensity
	diffuseR = .8;
	diffuseG = .8;
	diffuseB = .8;

	//default specular highlight is a full-intensity white light
	specularR = 1.0;
	specularG = 1.0;
	specularB = 1.0;



	//default position is at (2,2,2,)
	lightPositionX = 2;
	lightPositionY = 2;
	lightPositionZ = 2;

	//initialize the ID to the current ID
	switch (currentID){
		case 0:
			ID = GL_LIGHT0;
			break;
		case 1:
			ID = GL_LIGHT1;
			break;
		case 2:
			ID = GL_LIGHT2;
			break;
		case 3:
			ID = GL_LIGHT3;
			break;
		case 4:
			ID = GL_LIGHT4;
			break;
		case 5:
			ID = GL_LIGHT5;
			break;
		case 6:
			ID = GL_LIGHT6;
			break;
		case 7:
			ID = GL_LIGHT7;
			break;
		//if the currID is larger than 7, just set
		//ID to 0--the light won't work
		default:
			ID = 0;
			break;
	}
	currentID++;

	enabled = false;
}

//creates a light with default settings, except for the position
Light::Light(float x, float y, float z){

	//default ambient light is a white light at .8 intensity
	ambientR = .8;
	ambientG = .8;
	ambientB = .8;

	//default diffuse light is a white light at .2 intensity
	diffuseR = .2;
	diffuseG = .2;
	diffuseB = .2;

	//default specular hightlight is a full-intensity white light
	specularR = 1.0;
	specularG = 1.0;
	specularB = 1.0;

	//position based on user input
	lightPositionX = x;
	lightPositionY = y;
	lightPositionZ = z;

	//initialize the ID to the current ID
	//initialize the ID to the current ID
	switch (currentID){
		case 0:
			ID = GL_LIGHT0;
			break;
		case 1:
			ID = GL_LIGHT1;
			break;
		case 2:
			ID = GL_LIGHT2;
			break;
		case 3:
			ID = GL_LIGHT3;
			break;
		case 4:
			ID = GL_LIGHT4;
			break;
		case 5:
			ID = GL_LIGHT5;
			break;
		case 6:
			ID = GL_LIGHT6;
			break;
		case 7:
			ID = GL_LIGHT7;
			break;
		//if the currID is larger than 7, just set
		//ID to 0--the light won't work
		default:
			ID = 0;
			break;
	}
	currentID++;

	enabled = false;
}
//empty destructor
Light::~Light(){}

//enable the light
void Light::enable(){
	enabled = true;
	glEnable(ID);
}
//disable the light
void Light::disable(){
	enabled = false;
	glDisable(ID);
}

/*These methods make the openGL calls that
 *set the material settings, the light settings,
 *and the position based on the camera's instance
 *variables
 */

void Light::setLighting(){
	//create RGBA arrays for each light type for color/intensity
	GLfloat qaAmbientLight[]	= {ambientR, ambientG, ambientB, 1.0};
	GLfloat qaDiffuseLight[]	= {diffuseR, diffuseG, diffuseB, 1.0};
	GLfloat qaSpecularLight[]	= {specularR, specularG, specularB, 1.0};
	//set the light to give off these RGBA values
	glLightfv(ID, GL_AMBIENT, qaAmbientLight);
	glLightfv(ID, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(ID, GL_SPECULAR, qaSpecularLight);

}

void Light::setPosition(){
	// Set the light position
	GLfloat LightPosition[]	= {lightPositionX, lightPositionY, lightPositionZ, 1.0};
	glLightfv(ID, GL_POSITION, LightPosition);
}

