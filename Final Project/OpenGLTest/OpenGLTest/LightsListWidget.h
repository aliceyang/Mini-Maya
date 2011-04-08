/*
 * LightsListWidget.h
 *
 *  Created on: Apr 21, 2010
 *      Author: jayfo
 */

#ifndef LIGHTSLISTWIDGET_H_
#define LIGHTSLISTWIDGET_H_

#include <map>
#include <vector>
#include <QtOpenGL>
#include <QtGui>
#include "Light.h"

using namespace std;

class LightsListWidget: public QListWidget{

	Q_OBJECT

	static int IDCounter;
private:
	//this has each list item hold a connection to
	//an actual Light object
	map<QListWidgetItem*,Light*> lightsMap;
	//the set of lights
	vector<Light*> lights;

	//integer representing the currently selected
	//radio button
	int currentLightTypeSelection;

public:
	LightsListWidget(QWidget* parent = 0);
	~LightsListWidget();

	//================================//
	//============Signals=============//
	//================================//
signals:

	void sendR(int r);
	void sendG(int g);
	void sendB(int b);
	void sendShine(int s);
	void sendX(double x);
	void sendY(double y);
	void sendZ(double z);
	void redraw();

	//================================//
	//==============Slots=============//
	//================================//
public slots:

	void acceptLights(Light*);
	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void setToAmbient();
	void setToDiffuse();
	void setToSpecular();
	void enable();
	void disable();

	void activated();//when user clicks on this widget. Displays RGB values of selected face


};

#endif /* LIGHTSLISTWIDGET_H_ */
