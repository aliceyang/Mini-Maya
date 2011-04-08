#include "Face.h"
#include <cassert>
#include <vector>
#include <cmath>

#define EPS 0.00001

Face::Face(){
	selected = -1;
	HE = 0;
	R = .5;
	G = .5;
	B = .5;
	origR = .5;
	origG = .5;
	origB = .5;
	ID = 0;
	centroid = new Vertex();
	numF = 0;
	material = new Material();
}

Face::Face(int id){
	selected = -1;
	ID = id;
	HE = 0;
	R = .5;
	G = .5;
	B = .5;
	origR = .5;
	origG = .5;
	origB = .5;
	ID = 0;
	centroid = new Vertex();
	numF = 0;
	material = new Material();
}

Face::~Face(){
	//delete HE;
}

//Functions

//sets the RGB values for this face
void Face::setRGB(float r, float g, float b){
	R = r;
	G = g;
	B = b;
	origR = r;
	origG = g;
	origB = b;
}


//returns the number of edges of this face
int Face::numEdges(){
	int edgeCount = 1;
	HalfEdge *loop = HE->NEXT;
	while(HE != loop){
		loop = loop->NEXT;
		edgeCount++;
	}
	return edgeCount;
}

//returns the centroid point of the face
Vertex* Face::getCentroid(){
	//if (centroid->getX() == 0 & centroid->getY() == 0){
	float sumX = 0.0;
	float sumY = 0.0;
	float sumZ = 0.0;
	HalfEdge *edge = HE;
	for (int i = 0; i < numEdges(); i++){
		sumX += edge->V->getX();
		sumY += edge->V->getY();
		sumZ += edge->V->getZ();
		edge = edge->NEXT;
	}
	Vertex *c = new Vertex( sumX/numEdges(), sumY/numEdges(), sumZ/numEdges() );
	centroid = c;
	return c;
	//}
//else{
	//	return centroid;
	//}
}


vector < Face* > Face::smooth(vector < Vertex* > vertices, float r, float g, float b){
	//std::cout<<"called FACE smooth"<<endl;
	//std::cout<<"my he "<<HE<<endl;
	//std::cout<<"my v1 "<<HE->V<<endl;
	//std::cout<<"sym? "<<HE->NEXT->SYM<<endl;

	//we're changing the number of edges somewhere along the way, so let's keep a copy of original number
	int num = numEdges();
	numF = numEdges();
	vector < HalfEdge* > edges;
	//create the new halfedges for this face and store them in a vector
	//edges.~vector< HalfEdge* >(); //clears the edges vector from any previous uses
	//Catmull-Clark produces all quads upon completion
	//so for each edge, we will need 3 new HalfEdges (the 4th being the original edge)
	for (int i = 0; i < num*3; i++){
		edges.push_back( new HalfEdge(i) );
	}

	//now we want to start assigning vertices
	//there should be 2 new edges pointing to each edge point
	//and numEdges() new edges pointing to the centroid
	//first let's collect the edge points in a vector
	vector < Vertex* > ep;
	HalfEdge* he = HE->NEXT;
	for (int j = 0; j < num; j++){
		//std::cout<<"HE edgePoint "<<he->edgePoint<<endl;
		bool exists = false;
		for (int v = 0; v < vertices.size(); v++){
			if ( abs(he->edgePoint->getX() - vertices.at(v)->getX()) < EPS & abs(he->edgePoint->getY() - vertices.at(v)->getY()) < EPS & abs(he->edgePoint->getZ() - vertices.at(v)->getZ()) < EPS ){
				ep.push_back(vertices.at(v));
				exists = true;
				break;
			}
		}
		if (exists == false){
			ep.push_back( new Vertex( he->edgePoint->getX(), he->edgePoint->getY(), he->edgePoint->getZ() ));
			std::cout<<"SHOULD NOT SEE THIS"<<endl;
		}
		he = he->NEXT;
	}


	//now assign the new edges
	int index = 0; //this will keep track of which edge in the vector of edges we are working with
	for (int k = 0; k < ep.size(); k++){
		//std::cout<<"ep "<<ep.at(k)<<endl;
		//edges.at(index)->V = new Vertex( ep.at(k)->getX(), ep.at(k)->getY(), ep.at(k)->getZ() );
		//edges.at(index + 1)->V = new Vertex( ep.at(k)->getX(), ep.at(k)->getY(), ep.at(k)->getZ() );
		edges.at(index)->V = ep.at(k);
		edges.at(index+1)->V = ep.at(k);
		index += 2;
	}
	//now assign the new edges that will point to the centroid
	Vertex* tempCent;
	for (int c = 0; c < vertices.size(); c++){
		if ( abs(centroid->getX() - vertices.at(c)->getX()) < EPS & abs(centroid->getY() - vertices.at(c)->getY()) < EPS & abs(centroid->getZ() - vertices.at(c)->getZ()) < EPS ){
			tempCent = vertices.at(c);
		}
	}
	for (int x = index; x < edges.size(); x++){
		//edges.at(x)->V = new Vertex( centroid->getX(), centroid->getY(), centroid->getZ() );
		edges.at(x)->V = tempCent;
	}

	/*std::cout<<"loop all "<<endl;
	for (int g = 0; g < edges.size(); g++){
		std::cout<<edges.at(g)->V<<endl;
	}*/

	//check vertices
	/*std::cout<<"vertices check"<<endl;
	for (int q = 0; q < edges.size(); q++){
		std::cout<<"edge"<<q<<" : "<<edges.at(q)->V->getX()<<", "<<edges.at(q)->V->getY()<<", "<<edges.at(q)->V->getZ()<<endl;
	}*/


	//we'll need new faces too, numEdges() - 1 new faces
	vector < Face* > faces;
	for (int f = 0; f < num - 1; f++){
		faces.push_back(new Face());
		//following 2 lines for testing purposes
		faces.at(f)->setRGB(r,g,b);
		r = r + 0.05;
		g = g + 0.05;
		b = b + 0.05;
		/*if (r > 1.0){
			r = 0.0;
		}
		if (g > 2.0){
			g = 0.0;
		}
		if (b > 3.0){
			b = 0.0;
		}*/
	}


	//now let's assign the "next" edges for these new edges
	//while we're at it, all the edges that are connected will be pointing to the same face
	//so let's assign that as well
	int tab = 0; //for keeping track
	int index2 = index; //we want to keep hold of the index number, so let's copy it
	HalfEdge* curr = HE; //will keep track as we cycle through original edges
	for (int y = 0; y < num; y++){
		if (y == 0){
			//std::cout<<"edges size "<<edges.size()<<endl;
			//std::cout<<"index2 = "<<index2<<endl;
			//std::cout<<"tab = "<<tab<<endl;
			edges.at(tab)->NEXT = edges.at(index2);
			//std::cout<<"ID "<<edges.at(index2)->ID<<endl;
			//std::cout<<"but here "<<edges.at(tab)->NEXT->ID<<endl;
			edges.at(index2)->NEXT = edges.at(index2-1);
			edges.at(index2-1)->NEXT = curr;

			edges.at(tab)->F = this;
			edges.at(index2)->F = this;
			edges.at(index2-1)->F = this;
		}
		else{
			//std::cout<<"edges size "<<edges.size()<<endl;
			//std::cout<<"index2 = "<<index2<<endl;
			//std::cout<<"tab = "<<tab<<endl;
			edges.at(tab)->NEXT = edges.at(index2);
			edges.at(index2)->NEXT = edges.at(tab-1);
			edges.at(tab-1)->NEXT = curr;

			edges.at(tab)->F = faces.at(y-1);
			edges.at(index2)->F = faces.at(y-1);
			edges.at(tab-1)->F = faces.at(y-1);
			curr->F = faces.at(y-1);
			faces.at(y-1)->HE = edges.at(tab);
		}
		tab += 2; 	//difficult to explain without a drawing
		index2 += 1;
		curr = curr->NEXT;
	}


	//now that we have that set up, let's take care of symmetrical edges
	///blargity blargh this was confusing
	///and I'm running out of variable names...
	HalfEdge* that = HE->NEXT;
	for (int a = 0; a < num; a++){
		edges.at(a*2)->SYM = that->SYM;
		if (a == num - 2){
			that = HE;
		}
		else{
			that = that->NEXT;
		}
	} //don't worry about the vice versa here, will be taken care of when adjacent faces call this method

	/* accounted for in adjustSym now
	HalfEdge* bleh = HE->NEXT;
	for (int b = 0; b < num; b++){
		HalfEdge* orig = edges.at(b*2)->SYM;
		HalfEdge* edg = edges.at(b*2)->SYM;
		while (edg->NEXT == orig){
			edg = edg->NEXT;
		}
		bleh->SYM = edg;
		if (b == num - 2){
			bleh = HE;
		}
		else{
			bleh = bleh->NEXT;
		}
	}*/

	int tab2 = 1;
	int index3 = index; //might need this again
	for (int c = 0; c < num; c++){ //haha, c++
		edges.at(tab2)->SYM = edges.at(index3);
		edges.at(index3)->SYM = edges.at(tab2);
		tab2 += 2;
		index3 += 1;
	}

	//we needed the old "next" structure to assign jawn above, now we need to restructure it
	HalfEdge* temp = HE;
	vector < HalfEdge* > origEdges;
	for (int e = 0; e < num; e++){
		origEdges.push_back(temp);
		temp = temp->NEXT;
	}
	for (int z = 0; z < num ; z++){
		origEdges.at(z)->NEXT = edges.at(z*2);
	}

	//and all that jazz! now to test...

	/*
	std::cout<<"edge0->N = "<<edges.at(0)->NEXT->ID<<endl;
	std::cout<<"from 0 "<<edges.at(0)->V->getX()<<", "<<edges.at(0)->V->getY()<<", "<<edges.at(0)->V->getZ()<<endl;
	std::cout<<"from 0 "<<edges.at(0)->NEXT->V->getX()<<", "<<edges.at(0)->NEXT->V->getY()<<", "<<edges.at(0)->NEXT->V->getZ()<<endl;
	std::cout<<"from 0 "<<edges.at(0)->NEXT->NEXT->V->getX()<<", "<<edges.at(0)->NEXT->NEXT->V->getY()<<", "<<edges.at(0)->NEXT->NEXT->V->getZ()<<endl;
	std::cout<<"same as 7? "<<edges.at(7)->V->getX()<<", "<<edges.at(7)->V->getY()<<", "<<edges.at(7)->V->getZ()<<endl;
	std::cout<<"from 0 "<<edges.at(0)->NEXT->NEXT->NEXT->V->getX()<<", "<<edges.at(0)->NEXT->NEXT->NEXT->V->getY()<<", "<<edges.at(0)->NEXT->NEXT->NEXT->V->getZ()<<endl;
	std::cout<<"edge1->N = "<<edges.at(1)->NEXT->ID<<endl;
	std::cout<<"edge2->N = "<<edges.at(2)->NEXT->ID<<endl;
	std::cout<<"edge3->N = "<<edges.at(3)->NEXT->ID<<endl;
	std::cout<<"edge4->N = "<<edges.at(4)->NEXT->ID<<endl;
	std::cout<<"edge5->N = "<<edges.at(5)->NEXT->ID<<endl;
	std::cout<<"edge6->N = "<<edges.at(6)->NEXT->ID<<endl;
	std::cout<<"edge7->N = "<<edges.at(7)->NEXT->ID<<endl;
	std::cout<<"edge8->N = "<<edges.at(8)->NEXT->ID<<endl;
	std::cout<<"edge9->N = "<<edges.at(9)->NEXT->ID<<endl;
	std::cout<<"edge10->N = "<<edges.at(10)->NEXT->ID<<endl;
	std::cout<<"edge11->N = "<<edges.at(11)->NEXT->ID<<endl;
	*/

	edges2 = edges;
	return faces;
}


//selects the face by either turning it white, or reverting to original color
void Face::select(){
	if(selected == -1){
		R = 1;
		G = 1;
		B = 1;
		selected = -1 * selected;
	}
	else{
		R = origR;
		G = origG;
		B = origB;
		selected = -1 * selected;
	}
}

void Face::adjustSym(){
	//HE->SYM->SYM = HE;
	//std::cout<<"numf "<<numF<<endl;
	for (int i = 0; i < numF; i++){
		//std::cout<<"edges2 "<<edges2.at(i*2)<<endl;
		edges2.at(i*2)->SYM->SYM = edges2.at(i*2);
	}
}

//FFD

float Face::minX(){
	float min = HE->V->getX();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getX() < min){
			min = HE0->V->getX();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return min;
}

float Face::minY(){
	float min = HE->V->getY();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getY() < min){
			min = HE0->V->getY();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return min;
}

float Face::minZ(){
	float min = HE->V->getZ();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getZ() < min){
			min = HE0->V->getZ();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return min;
}

float Face::maxX(){
	float max = HE->V->getX();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getX() > max){
			max = HE0->V->getX();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return max;
}

float Face::maxY(){
	float max = HE->V->getY();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getY() > max){
			max = HE0->V->getY();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return max;
}

float Face::maxZ(){
	float max = HE->V->getZ();
	HalfEdge* HE0 = HE;
	do{
		if (HE0->V->getZ() > max){
			max = HE0->V->getZ();
		}
		HE0 = HE0->NEXT;
	} while( HE0 != HE );
	return max;
}
