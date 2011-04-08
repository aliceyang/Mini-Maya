#include "HalfEdge.h"

HalfEdge::HalfEdge(){
	F = 0;
	V = 0;
	//make methods to set next and sym
	NEXT = 0;
	SYM = 0;
	edgePoint = new Vertex();
}

HalfEdge::HalfEdge(int id){
	ID = id;
}

HalfEdge::~HalfEdge(){
	//delete F, V, NEXT, SYM;
}

/* returns edgePoint = "average of the two neighbouring face points
 * and its two original endpoints" */
Vertex* HalfEdge::getEdgePoint(){
	//if (edgePoint == new Vertex()){
	float sumX = V->getX();
	float sumY = V->getY();
	float sumZ = V->getZ();
	std::cout<<"sumX = "<<sumX<<endl;
	std::cout<<"sumY = "<<sumY<<endl;
	std::cout<<"sumZ = "<<sumZ<<endl;
	std::cout<<"--------"<<endl;
	std::cout<<"Face ct? "<<F->getCentroid()<<" ";
	F->getCentroid()->print();
	sumX += F->getCentroid()->getX();
	sumY += F->getCentroid()->getY();
	sumZ += F->getCentroid()->getZ();
	std::cout<<"sumX = "<<sumX<<endl;
	std::cout<<"sumY = "<<sumY<<endl;
	std::cout<<"sumZ = "<<sumZ<<endl;
	std::cout<<"--------"<<endl;
	sumX += SYM->V->getX();
	sumY += SYM->V->getY();
	sumZ += SYM->V->getZ();
	std::cout<<"sumX = "<<sumX<<endl;
	std::cout<<"sumY = "<<sumY<<endl;
	std::cout<<"sumZ = "<<sumZ<<endl;
	std::cout<<"--------"<<endl;
	sumX += SYM->F->getCentroid()->getX();
	sumY += SYM->F->getCentroid()->getY();
	sumZ += SYM->F->getCentroid()->getZ();
	std::cout<<"sumX = "<<sumX<<endl;
	std::cout<<"sumY = "<<sumY<<endl;
	std::cout<<"sumZ = "<<sumZ<<endl;
	Vertex* ep = new Vertex( sumX/4, sumY/4, sumZ/4 );
	edgePoint = ep;
	std::cout<<"edgepoint is";
	ep->print();
	return ep;
	//}
	//else{
	//	return edgePoint;
	//}
}

//returns the midpoint along the edge
Vertex* HalfEdge::getMidpoint(){
	//if (midpoint == new Vertex()){
	float sumX = V->getX();
	float sumY = V->getY();
	float sumZ = V->getZ();
	sumX += SYM->V->getX();
	sumY += SYM->V->getY();
	sumZ += SYM->V->getZ();
	Vertex* m = new Vertex( sumX/2, sumY/2, sumZ/2 );
	midpoint = m;
	return m;
	//}
//else{
	//	return midpoint;
	//}
}
