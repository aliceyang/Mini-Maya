/*
 * Light.h
 *
 *  Created on: Apr 21, 2010
 *      Author: jayfo
 */

#ifndef LIGHT_H_
#define LIGHT_H_

class Light{

	friend class MyGLWidget;
	friend class LightsListWidget;

private:
	//******VARIABLES FOR LIGHTING*******//
	//The RGB values for the ambient light
	float ambientR;
	float ambientG;
	float ambientB;

	//The RGB values for the diffuse light
	float diffuseR;
	float diffuseG;
	float diffuseB;

	//The RGB values for the specular highlight
	float specularR;
	float specularG;
	float specularB;


	//The XYZ position of the light
	float lightPositionX;
	float lightPositionY;
	float lightPositionZ;

	//an ID for the light
	int ID;

	//tells whether light is enabled or not
	bool enabled;

public:
	//a ID counter for the class (so IDs are assigned from 0-7 as cameras
	//are created
	static int currentID;


	//constructor that sets up a default light
	Light();
	//constructor that sets up  a default light but takes position coordinates
	Light(float x, float y, float z);
	//empty destructor
	~Light();


	//enable/disable the lights
	void enable();
	void disable();

	/*These methods make the openGL calls that
	 *set the material settings, the light settings,
	 *and the position based on the camera's instance
	 *variables
	 */
	void setMaterial();
	void setLighting();
	void setPosition();


};


#endif /* LIGHT_H_ */
