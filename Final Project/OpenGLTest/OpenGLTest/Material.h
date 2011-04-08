#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

using namespace std;

class Material{

public:
	float ka[3]; //defines the ambient color of the material to be (r,g,b). The default is (0.2,0.2,0.2); 
	float kd[3]; //defines the diffuse color of the material to be (r,g,b). The default is (0.8,0.8,0.8); 
	float ks[3]; //defines the specular color of the material to be (r,g,b). This color shows up in highlights. The default is (1.0,1.0,1.0); 
	float d; //defines the transparency of the material to be alpha. The default is 1.0 (not transparent at all) Some formats use Tr instead of d; 
	float tr; //defines the transparency of the material to be alpha. The default is 1.0 (not transparent at all). Some formats use d instead of Tr; 
	float ns; //defines the shininess of the material to be s. The default is 0.0; 
	int illum; //denotes the illumination model used by the material. illum = 1 indicates a flat material with no specular highlights, so the value of Ks is not used. illum  = 2 denotes the presence of specular highlights, and so a specification for Ks is required. 
	string name;
	//does not handle textures

	//constructor
	Material();

};
#endif MATERIAL_H