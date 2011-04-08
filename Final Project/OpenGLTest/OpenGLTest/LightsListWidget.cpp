/*
 * LightsListWidget.cpp
 *
 *  Created on: Apr 21, 2010
 *      Author: Joe Forzano
 */

#include "LightsListWidget.h"
#include <iostream>

#define AMBIENT 0
#define DIFFUSE 1
#define SPECULAR 2

int LightsListWidget::IDCounter = 0;

LightsListWidget::LightsListWidget(QWidget*Parent):
	QListWidget(Parent){
	currentLightTypeSelection = AMBIENT;
}

//empty Destructor
LightsListWidget::~LightsListWidget(){}

//================================//
//==============Slots=============//
//================================//

void LightsListWidget::acceptLights(Light* light){
	//dont accept lights if they've already been accepted
	if (lights.size() == 8) {
		return;
	}
	//store the lights vector
	lights.push_back(light);


	/*for each of the 8 lights, create a listItem for it
	 * and connect the two via the map
	 */
	QString lightName = "light ";
	//start of all light names

	//Name the light appropriately
	QString number = QString::number(IDCounter);
	IDCounter++;
	lightName = lightName + number;

	//create a listItem and add it to the widget
	QListWidgetItem* i = new QListWidgetItem(lightName);
	addItem(i);

	//map the item to the light it represents
	lightsMap[i] = light;

	//have first light selected
}

void LightsListWidget::setR(int r){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//account for fact that RGB sliders go from 1 to 100
	double rd = r / 100.0;
	//set the Lights r value based on the currentLightTypeSelection
	switch (currentLightTypeSelection){
		case AMBIENT:
			currentLight->ambientR = rd;
			break;
		case  DIFFUSE:
			currentLight->diffuseR = rd;
			break;
		case SPECULAR:
			currentLight->specularR = rd;
			break;
	}

	//tell the widget to redraw
	emit redraw();
}
void LightsListWidget::setG(int g){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//account for fact that RGB sliders go from 1 to 100
	double gd = g / 100.0;

	//set the Lights r value based on the currentLightTypeSelection
	switch (currentLightTypeSelection){
		case AMBIENT:
			currentLight->ambientG = gd;
			break;
		case  DIFFUSE:
			currentLight->diffuseG = gd;
			break;
		case SPECULAR:
			currentLight->specularG = gd;
			break;
	}

	//tell the widget to redraw
	emit redraw();
}
void LightsListWidget::setB(int b){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//account for fact that RGB sliders go from 1 to 100
	double bd = b / 100.0;

	//set the Lights r value based on the currentLightTypeSelection
	switch (currentLightTypeSelection){
		case AMBIENT:
			currentLight->ambientB = bd;
			break;
		case  DIFFUSE:
			currentLight->diffuseB = bd;
			break;
		case SPECULAR:
			currentLight->specularB = bd;
			break;
	}

	//tell the widget to redraw
	emit redraw();
}

void LightsListWidget::setX(double x){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//set X value
	currentLight->lightPositionX = x;

	emit redraw();
}


void LightsListWidget::setY(double y){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//set y value
	currentLight->lightPositionY = y;

	emit redraw();
}


void LightsListWidget::setZ(double z){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	//set z value
	currentLight->lightPositionZ = z;

	emit redraw();
}

//changes based on radio button selection
void LightsListWidget::setToAmbient(){
	currentLightTypeSelection = AMBIENT;
	activated();
}
void LightsListWidget::setToDiffuse(){
	currentLightTypeSelection = DIFFUSE;
	activated();
}
void LightsListWidget::setToSpecular(){
	currentLightTypeSelection = SPECULAR;
	activated();
}

void LightsListWidget::enable(){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	currentLight->enable();

	emit redraw();

}

void LightsListWidget::disable(){
	QListWidgetItem* currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	currentLight->disable();

	emit redraw();

}




//
void LightsListWidget::activated(){
	QListWidgetItem *currentSelection = currentItem();
	Light* currentLight = lightsMap[currentSelection];

	switch (currentLightTypeSelection){
		case AMBIENT:
			emit sendR((currentLight->ambientR)*100);
			emit sendG((currentLight->ambientG)*100);
			emit sendB((currentLight->ambientB)*100);
			break;
		case DIFFUSE:
			emit sendR((currentLight->diffuseR)*100);
			emit sendG((currentLight->diffuseG)*100);
			emit sendB((currentLight->diffuseB)*100);
			break;
		case SPECULAR:
			emit sendR((currentLight->specularR)*100);
			emit sendG((currentLight->specularG)*100);
			emit sendB((currentLight->specularB)*100);
			break;
	}

	//also display the current position
	emit sendX(currentLight->lightPositionX);
	emit sendY(currentLight->lightPositionY);
	emit sendZ(currentLight->lightPositionZ);
	//display the current shine


}
