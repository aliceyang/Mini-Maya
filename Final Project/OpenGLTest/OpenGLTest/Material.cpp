#include "Material.h"

Material::Material(){
	//default values for everything until reset
	ka[0] = 0.2;
	ka[1] = 0.2;
	ka[2] = 0.2;

	kd[0] = 0.8;
	kd[1] = 0.8;
	kd[2] = 0.8;

	ks[0] = 1.0;
	ks[1] = 1.0;
	ks[2] = 1.0;

	d = tr = 1.0;

	ns = 60.0;

	illum = 1;

	name = "default";
}
