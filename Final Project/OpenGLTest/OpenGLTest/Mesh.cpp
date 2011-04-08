#include "Mesh.h"
#include <vector>
#include <cassert>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cmath>

#define EPS 0.00001

Mesh::Mesh(){
	//vectors already instantiated
}

Mesh::~Mesh(){
	halfEdges.clear();
	faces.clear();
	vertices.clear();
}

//========================//
//======Operations========//
//========================//



//Adds a Vertex to an Edge
//Input: edge starting at vertex HE0->V; new VERTEX VN
//Goal: Insert VN on edge just after HE0->V
void Mesh::addVertexToEdge(HalfEdge *HE0){
	Vertex *VN = new Vertex(vertices.size());//its ID is the size of the vertices vector
	HalfEdge *HE1 = HE0->NEXT; //HE1 NEXT edge HalfEdge to get NEXT vertex//
	HalfEdge *HE2 = HE1->SYM; //HE2 other side of edge //

	HalfEdge *HENL = new HalfEdge(); //HE New Left//
	HalfEdge *HENR = new HalfEdge(); //HE New Right//

	HENL->NEXT = HE1;
	HE0->NEXT = HENL;
	HENR->NEXT = HE2->NEXT;
	HE2->NEXT = HENR;
	HENL->SYM = HENR;
	HENR->SYM= HENL;
	HENL->F = HE0->F;
	HENR->F = HE2->F;
	HENL->V = VN;
	HENR-> V = HE2->V;
	HE2->V = VN;

	//Average the coordinates of VN
	VN->v[0] = (HE0->V->v[0] + HE1->V->v[0])/2;
	VN->v[1] = (HE0->V->v[1] + HE1->V->v[1])/2;
	VN->v[2] = (HE0->V->v[2] + HE1->V->v[2])/2;

	//for later::add the newly made vertex and half edges to
	//their corresponding lists
	vertices.push_back(VN);
	halfEdges.push_back(HENL);
	halfEdges.push_back(HENR);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	GLWidget->updateDisplayList();

}

//Adds an edge between 2 faces that share a vertex
//Input: FACES FA and FB, and VERTEX HEA0->V and HEB0->V.
void Mesh::addEdgeBetweenFaces(Face *FA, Face *FB, Vertex* v){//HalfEdge *HEA0, HalfEdge *HEB0){
	//assert(HEA0->V == HEB0->V);
	Vertex *V1 = new Vertex(vertices.size());
	//set the coordinates of the new vertex to the same as the old one
	V1->setXYZ(v->v[0], v->v[1], v->v[2]);

	std::cout<<"new vertex coor:"<<std::ends;
	V1->print();

	HalfEdge *HENL = new HalfEdge(halfEdges.size()); //HE New Left //
	HalfEdge *HENR = new HalfEdge(halfEdges.size()); //HE New Right//

	//Find the HalfEdges needed
	HalfEdge* HEA0;
	HalfEdge* HEB0;

	//find HEA0
	for(int i = 0; i < halfEdges.size(); i++){
		if(halfEdges.at(i)->F == FA && halfEdges.at(i)->V == v){
			HEA0 = halfEdges.at(i); //originally HEA0
			//std::cout<<HEA0->ID<<std::endl;
			break;
		}
	}

	//find HEB0
	for(int i = 0; i < halfEdges.size(); i++){
		if(halfEdges.at(i)->F == FB && halfEdges.at(i)->V == v){
			HEB0 = halfEdges.at(i);//originally HEB0
			//std::cout<<HEB0->ID<<std::endl;
			break;
		}
	}

	HENL->NEXT = HEA0->NEXT; 
	HEA0->NEXT = HENL; 
	HENL->V = V1; 
	HENL->F = FA; 
	HENL->SYM = HENR;

	HENR->NEXT = HEB0->NEXT; 
	HEB0->NEXT = HENR; 
	HENR->V = HEA0->V; 
	HEB0->V = V1; 
	HENR->F = FB; 
	HENR->SYM = HENL;

	//Set Vertices of edges on the right to V1
	//HalfEdge* startEdge = HENL->NEXT; //HEA1
	//HalfEdge* currEdge = HENL->NEXT;
	//do{
	//	currEdge->SYM->V = V1;
	//	currEdge = currEdge->SYM->NEXT;
	//}while (currEdge != HEB0);

	//for later::add the newly made vertex and half edges to
	//their corresponding lists
	vertices.push_back(V1);
	halfEdges.push_back(HENL);
	halfEdges.push_back(HENR);

	//Now that a change to the mesh has been made, the display list must
	//be updated
	GLWidget->updateDisplayList();
}

void Mesh::SplitQuadToTriangles(Face *FACE1){
	//Check that FACE1 has exactly 4 edges, else return
	if(FACE1->numEdges() == 4){
		HalfEdge *HE0 = FACE1->HE;
		Face *FACE2 = new Face(faces.size()); //updates the face ID
		FACE2->R = FACE1->R;
		FACE2->G = FACE1->G;
		FACE2->B = FACE1->B;

		HalfEdge *HEL = new HalfEdge(); //HE New Left // 
		HalfEdge *HER = new HalfEdge(); //HE New Right//

		//FACE1 still points to its starting edge HE0, // 
		//and will contain the new HEL in its loop; // 
		//new FACE2 points to HER as its new starting edge//
		HEL->F = FACE1; 
		HER->F = FACE2;
		FACE2->HE = HER;

		HEL->SYM = HER;
		HER->SYM = HEL; 

		HEL->V = HE0->NEXT->NEXT->V; 
		HEL->NEXT = HE0->NEXT->NEXT->NEXT; 
		HER->NEXT = HE0->NEXT; 
		HER->NEXT->NEXT->NEXT = HER; 
		HE0->NEXT = HEL; 
		HER->V = HE0->V;

		//for later::add the newly made faces and half edges to
		//their corresponding lists
		faces.push_back(FACE2);
		halfEdges.push_back(HEL);
		halfEdges.push_back(HER);
	}

	//Now that a change to the mesh has been made, the display list must
	//be updated
	GLWidget->updateDisplayList();
}

//creates a face in the mesh based on the given vertices
//(in a vector) and establishes proper relations between
//vertices, faces, and halfedges
void Mesh::addFace(vector<Vertex*>v){
	//do i really need this??
	//yes. yes you do. implement this muthafuka later
}

//builds a cube mesh centered at the origin
Mesh* Mesh::makeCube(){
	Mesh *cube = new Mesh();

	//Initialize Faces (0-5: front back left right up down)
	for(int i = 0; i < 6; i++){
		cube->faces.push_back(new Face(i));
	}

	//Set Face Colors
	cube->faces.at(0)->setRGB(0,0,1);
	cube->faces.at(1)->setRGB(0,0,1);
	cube->faces.at(2)->setRGB(0,0,1);
	cube->faces.at(3)->setRGB(0,0,1);
	cube->faces.at(4)->setRGB(0,0,1);
	cube->faces.at(5)->setRGB(0,0,1);


	//Initialize vertices
	cube->vertices.push_back(new Vertex(1,1,1,0)); // right up front
	cube->vertices.push_back(new Vertex(1,-1,1,1)); //right down front
	cube->vertices.push_back(new Vertex(-1,1,1,2)); //left up front
	cube->vertices.push_back(new Vertex(-1,-1,1,3)); //left down front
	cube->vertices.push_back(new Vertex(1,1,-1,4)); //right up back
	cube->vertices.push_back(new Vertex(1,-1,-1,5)); //right down back
	cube->vertices.push_back(new Vertex(-1,1,-1,6)); //left up back
	cube->vertices.push_back(new Vertex(-1,-1,-1,7)); //left down back

	//Initialize HalfEdges
	for(int i = 0; i < 24; i++){
		cube->halfEdges.push_back(new HalfEdge(i));//assign ID's
	}

	//Establish proper Face->HE relations
	cube->faces.at(0)->HE = cube->halfEdges.at(0); //set starting HE for front face
	cube->faces.at(1)->HE = cube->halfEdges.at(4);
	cube->faces.at(2)->HE = cube->halfEdges.at(8);
	cube->faces.at(3)->HE = cube->halfEdges.at(12);
	cube->faces.at(4)->HE = cube->halfEdges.at(16);
	cube->faces.at(5)->HE = cube->halfEdges.at(20);

	//Establish proper HE->Face, Vertex, SYM and NEXT relations
	cube->halfEdges.at(0)->F = cube->faces.at(0);
	cube->halfEdges.at(0)->NEXT = cube->halfEdges.at(1);
	cube->halfEdges.at(0)->SYM = cube->halfEdges.at(18);
	cube->halfEdges.at(0)->V = cube->vertices.at(2);

	cube->halfEdges.at(1)->F = cube->faces.at(0);
	cube->halfEdges.at(1)->NEXT = cube->halfEdges.at(2);
	cube->halfEdges.at(1)->SYM = cube->halfEdges.at(11);
	cube->halfEdges.at(1)->V = cube->vertices.at(3);

	cube->halfEdges.at(2)->F = cube->faces.at(0);
	cube->halfEdges.at(2)->NEXT = cube->halfEdges.at(3);
	cube->halfEdges.at(2)->SYM = cube->halfEdges.at(22);
	cube->halfEdges.at(2)->V = cube->vertices.at(1);

	cube->halfEdges.at(3)->F = cube->faces.at(0);
	cube->halfEdges.at(3)->NEXT = cube->halfEdges.at(0);
	cube->halfEdges.at(3)->SYM = cube->halfEdges.at(13);
	cube->halfEdges.at(3)->V = cube->vertices.at(0);

	cube->halfEdges.at(4)->F = cube->faces.at(1);
	cube->halfEdges.at(4)->NEXT = cube->halfEdges.at(5);
	cube->halfEdges.at(4)->SYM = cube->halfEdges.at(16);
	cube->halfEdges.at(4)->V = cube->vertices.at(4);

	cube->halfEdges.at(5)->F = cube->faces.at(1);
	cube->halfEdges.at(5)->NEXT = cube->halfEdges.at(6);
	cube->halfEdges.at(5)->SYM = cube->halfEdges.at(15);
	cube->halfEdges.at(5)->V = cube->vertices.at(5);

	cube->halfEdges.at(6)->F = cube->faces.at(1);
	cube->halfEdges.at(6)->NEXT = cube->halfEdges.at(7);
	cube->halfEdges.at(6)->SYM = cube->halfEdges.at(20);
	cube->halfEdges.at(6)->V = cube->vertices.at(7);

	cube->halfEdges.at(7)->F = cube->faces.at(1);
	cube->halfEdges.at(7)->NEXT = cube->halfEdges.at(4);
	cube->halfEdges.at(7)->SYM = cube->halfEdges.at(9);
	cube->halfEdges.at(7)->V = cube->vertices.at(6);

	cube->halfEdges.at(8)->F = cube->faces.at(2);
	cube->halfEdges.at(8)->NEXT = cube->halfEdges.at(9);
	cube->halfEdges.at(8)->SYM = cube->halfEdges.at(17);
	cube->halfEdges.at(8)->V = cube->vertices.at(6);

	cube->halfEdges.at(9)->F = cube->faces.at(2);
	cube->halfEdges.at(9)->NEXT = cube->halfEdges.at(10);
	cube->halfEdges.at(9)->SYM = cube->halfEdges.at(7);
	cube->halfEdges.at(9)->V = cube->vertices.at(7);

	cube->halfEdges.at(10)->F = cube->faces.at(2);
	cube->halfEdges.at(10)->NEXT = cube->halfEdges.at(11);
	cube->halfEdges.at(10)->SYM = cube->halfEdges.at(23);
	cube->halfEdges.at(10)->V = cube->vertices.at(3);

	cube->halfEdges.at(11)->F = cube->faces.at(2);
	cube->halfEdges.at(11)->NEXT = cube->halfEdges.at(8);
	cube->halfEdges.at(11)->SYM = cube->halfEdges.at(1);
	cube->halfEdges.at(11)->V = cube->vertices.at(2);

	cube->halfEdges.at(12)->F = cube->faces.at(3);
	cube->halfEdges.at(12)->NEXT = cube->halfEdges.at(13);
	cube->halfEdges.at(12)->SYM = cube->halfEdges.at(19);
	cube->halfEdges.at(12)->V = cube->vertices.at(0);

	cube->halfEdges.at(13)->F = cube->faces.at(3);
	cube->halfEdges.at(13)->NEXT = cube->halfEdges.at(14);
	cube->halfEdges.at(13)->SYM = cube->halfEdges.at(3);
	cube->halfEdges.at(13)->V = cube->vertices.at(1);

	cube->halfEdges.at(14)->F = cube->faces.at(3);
	cube->halfEdges.at(14)->NEXT = cube->halfEdges.at(15);
	cube->halfEdges.at(14)->SYM = cube->halfEdges.at(21);
	cube->halfEdges.at(14)->V = cube->vertices.at(5);

	cube->halfEdges.at(15)->F = cube->faces.at(3);
	cube->halfEdges.at(15)->NEXT = cube->halfEdges.at(12);
	cube->halfEdges.at(15)->SYM = cube->halfEdges.at(5);
	cube->halfEdges.at(15)->V = cube->vertices.at(4);

	cube->halfEdges.at(16)->F = cube->faces.at(4);
	cube->halfEdges.at(16)->NEXT = cube->halfEdges.at(17);
	cube->halfEdges.at(16)->SYM = cube->halfEdges.at(4);
	cube->halfEdges.at(16)->V = cube->vertices.at(6);

	cube->halfEdges.at(17)->F = cube->faces.at(4);
	cube->halfEdges.at(17)->NEXT = cube->halfEdges.at(18);
	cube->halfEdges.at(17)->SYM = cube->halfEdges.at(8);
	cube->halfEdges.at(17)->V = cube->vertices.at(2);

	cube->halfEdges.at(18)->F = cube->faces.at(4);
	cube->halfEdges.at(18)->NEXT = cube->halfEdges.at(19);
	cube->halfEdges.at(18)->SYM = cube->halfEdges.at(0);
	cube->halfEdges.at(18)->V = cube->vertices.at(0);

	cube->halfEdges.at(19)->F = cube->faces.at(4);
	cube->halfEdges.at(19)->NEXT = cube->halfEdges.at(16);
	cube->halfEdges.at(19)->SYM = cube->halfEdges.at(12);
	cube->halfEdges.at(19)->V = cube->vertices.at(4);

	cube->halfEdges.at(20)->F = cube->faces.at(5);
	cube->halfEdges.at(20)->NEXT = cube->halfEdges.at(21);
	cube->halfEdges.at(20)->SYM = cube->halfEdges.at(6);
	cube->halfEdges.at(20)->V = cube->vertices.at(5);

	cube->halfEdges.at(21)->F = cube->faces.at(5);
	cube->halfEdges.at(21)->NEXT = cube->halfEdges.at(22);
	cube->halfEdges.at(21)->SYM = cube->halfEdges.at(14);
	cube->halfEdges.at(21)->V = cube->vertices.at(1);

	cube->halfEdges.at(22)->F = cube->faces.at(5);
	cube->halfEdges.at(22)->NEXT = cube->halfEdges.at(23);
	cube->halfEdges.at(22)->SYM = cube->halfEdges.at(2);
	cube->halfEdges.at(22)->V = cube->vertices.at(3);

	cube->halfEdges.at(23)->F = cube->faces.at(5);
	cube->halfEdges.at(23)->NEXT = cube->halfEdges.at(20);
	cube->halfEdges.at(23)->SYM = cube->halfEdges.at(10);
	cube->halfEdges.at(23)->V = cube->vertices.at(7);


	//==========================//
	//======TESTING AREA========//
	//==========================//


	//TESTING ADD VERTEX TO EDGE (PLEASE UNCOMMENT TO TEST)
	//cube->addVertexToEdge(cube->halfEdges.at(0));
	//cube->vertices.at(8)->setX(-1.6); //we know the newly added vertex is the 8th in the list, 
	//cube->vertices.at(8)->setY(0); //since originally there were 7
	//cube->vertices.at(8)->setZ(1.5);//you can also use the GUI to manipulate the coordinates

	//TESTING SPLIT QUAD TO TRIANGLE FACES (PLEASE UNCOMMENT TO TEST)
	//cube->SplitQuadToTriangles(cube->faces.at(0));
	//cube->faces.at(0)->R = 1;//one of the split faces will be blue
	//cube->faces.at(0)->G = 0;//The split faces are 0 and 6
	//cube->faces.at(0)->B = 0;//you can also use the GUI to change the colors

	//TESTING ADD EDGE BETWEEN FACE (PLEASE UNCOMMENT TO TEST)
	//cube->SplitQuadToTriangles(cube->faces.at(0)); //split a quad into triangles to create one of the edges to be used
	//cube->faces.at(0)->R = 1;//one of the split faces will be blue
	//cube->faces.at(0)->G = 0;//The split faces are 0 and 6
	//cube->faces.at(0)->B = 0;//you can also use the GUI to change the colors
	//cube->addEdgeBetweenFaces(cube->faces.at(4), cube->faces.at(6), cube->halfEdges.at(17), cube->halfEdges.at(25));
	//cube->vertices.at(8)->setXYZ(-0.8, 0.6, 1); //adjusts the coordinates of the newly made vertex 


	//testing planarity (need to convert isPlanar to static type)
	//Face* testFace = cube->faces.at(0);
	//std::cout<<"PLANARITY CHECK"<<std::endl;
	//std::cout<<"isPlanar:"<<isPlanar(testFace)<<std::endl;
	//std::cout<<""<<std::endl;

	//Testing ray-plane intersect
	/*Vertex *V1 = new Vertex(5,0,-2);
	Vertex *V2 = new Vertex(5,0,2);
	Face* testFace = cube->faces.at(0);
	std::cout<<"RAY IN PLANE TEST"<<std::endl;
	std::cout<<"rayPlaneIntersect:"<<rayPlaneIntersect(V1,V2,testFace);
	std::cout<<""<<std::endl;*/

	//Testing Point in Poly(Face)
	/*std::cout<<"POINT IN POLY CHECK"<<std::endl;
	Vertex *pointV = new Vertex(1,1,1);
	std::cout<<"pointInPoly:"<<pointInPoly(pointV, testFace)<<std::endl;
	std::cout<<""<<std::endl;*/

	//Testing Ray Poly Intersection
	/*Face* testFace;
	Vertex *V1, *V2;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 0"<<std::endl;
	testFace = cube->faces.at(0);
	V1 = new Vertex(0,.5,5);
	V2 = new Vertex(0,.5,-5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 1"<<std::endl;
	std::cout<<""<<std::endl;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 0"<<std::endl;
	testFace = cube->faces.at(0);
	V1 = new Vertex(0,-5,5);
	V2 = new Vertex(0,-5,-5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 0"<<std::endl;
	std::cout<<""<<std::endl;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 2"<<std::endl;
	testFace = cube->faces.at(2);
	V1 = new Vertex(-5,0,.5);
	V2 = new Vertex(5,0,.5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 1"<<std::endl;
	std::cout<<""<<std::endl;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 2"<<std::endl;
	testFace = cube->faces.at(2);
	V1 = new Vertex(-5,2,.5);
	V2 = new Vertex(5,2,.5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 0"<<std::endl;
	std::cout<<""<<std::endl;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 4"<<std::endl;
	testFace = cube->faces.at(4);
	V1 = new Vertex(0,-5,.5);
	V2 = new Vertex(0,5,.5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 1"<<std::endl;
	std::cout<<""<<std::endl;

	std::cout<<"RAY POLY INTERSECT TEST: FACE 4"<<std::endl;
	testFace = cube->faces.at(4);
	V1 = new Vertex(2,-5,.5);
	V2 = new Vertex(2,5,.5);
	std::cout<<"rayPolyIntersect:"<<rayPolyIntersect(V1, V2, testFace)<<std::endl;
	std::cout<<"expected: 0"<<std::endl;
	std::cout<<""<<std::endl;*/


	//Print check//
	/*std::cout<<cube->faces.size()<<" faces"<<std::endl;
	std::cout<<cube->vertices.size()<<" vertices"<<std::endl;
	std::cout<<cube->halfEdges.size()<<" halfEdges"<<std::endl;

	std::cout<<"print vertices"<<std::endl;
	for(int i = 0; i < cube->vertices.size(); i++){
		std::cout<<i <<":"<<std::ends;
		cube->vertices.at(i)->print();
	}*/

	return cube;
}

//draws the mesh with transformations applied
void Mesh::drawMesh(vec3 eye, vec3 reference, vec3 up){
	for(int i = 0; i < faces.size(); i++){
		if(!isPlanar(faces.at(i))){
			SplitQuadToTriangles(faces.at(i));
		}
	}


	Face* currFace;
	HalfEdge* edge;
	HalfEdge* origEdge;


	for(int i = 0; i < faces.size(); i++){
		currFace = faces.at(i);

		//get the normal to the face
		vec3 faceNormal = getNormal(currFace);
		//normalize
		faceNormal = faceNormal.normalize();
		glColor3f(currFace->R, currFace->G, currFace->B);

		//create RGBA arrays for each light type for color/intensity
		float ambientMaterialColor[4]={currFace->material->ka[0], currFace->material->ka[1], currFace->material->ka[2], 1.0};
		float diffuseMaterialColor[4]={currFace->material->kd[0], currFace->material->kd[1], currFace->material->kd[2], currFace->material->tr};
		//if specular highlight used
		if (currFace->material->illum == 2){
			float specularMaterialColor[4]={currFace->material->ks[0], currFace->material->ks[1], currFace->material->ks[2],1.0};
			glMaterialfv(GL_FRONT,GL_SPECULAR, specularMaterialColor);

		}
		//set the material to reflect these RGBA values
		glMaterialfv(GL_FRONT,GL_AMBIENT,ambientMaterialColor);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuseMaterialColor);
		//set the shininess of the material
		float shininess[1] = {currFace->material->ns};
		glMaterialfv(GL_FRONT,GL_SHININESS, shininess);


		glBegin(GL_POLYGON);
		//set the normal for each of the next vertices

		edge = currFace->HE;
		origEdge = currFace->HE;

		//loop through all the HE of this face
		do{
			//std::cout<<"drawing, x "<<edge->V->v[0]<<", y "<<edge->V->v[1]<<", z "<<edge->V->v[2]<<endl;
			glNormal3d(faceNormal[0], faceNormal[1], faceNormal[2]);
			glVertex3f(edge->V->v[0], edge->V->v[1], edge->V->v[2]);
			edge = edge->NEXT;
		} while(origEdge != edge && edge !=0);
		glEnd();

		//testing
		//Now draw all the edges around a face
		glColor3f(0,0,0);
		glBegin(GL_LINE_STRIP);
		//edges already instantiated above
		do{
			glVertex3f(edge->V->v[0], edge->V->v[1], edge->V->v[2]);
			edge = edge->NEXT;
		}while(origEdge != edge && edge != 0);
		glVertex3f(edge->V->v[0], edge->V->v[1], edge->V->v[2]); //one more to complete the loop (else one edge will not be drawn)
		glEnd();
	}
	glPointSize(4);
	glBegin(GL_POINTS);
	for (int g = 0; g < controlPoints.size(); g++){
		glVertex3f( controlPoints.at(g)->getX(), controlPoints.at(g)->getY(), controlPoints.at(g)->getZ() );
		//controlPoints.at(g)->print();
	}
	glEnd();


}

//deletes the specified vertex
void Mesh::deleteVertex(Vertex* v){
	//vector to store hanging vertices (will be used at end)
	vector<Vertex*> hangingvs;

	//find a halfEdge that points to the vertex
	HalfEdge* startEdge;
	for(int i = 0; i < halfEdges.size(); i++){
		if(halfEdges.at(i)->V == v){ 
			startEdge = halfEdges.at(i);
			break;
		}
	}

	//find all HE's that point to this vertex and store them in a vector called edges
	HalfEdge *currEdge = startEdge;
	vector<HalfEdge*> edges;
	do{
		edges.push_back(currEdge);
		if(currEdge->NEXT->SYM != 0)//testing if statement
			currEdge = currEdge->NEXT->SYM;
	}while(currEdge != startEdge);

	//delete references to edges
	for(int i = 0; i < edges.size(); i++){
		currEdge = edges.at(i);
		startEdge = currEdge;
		//Face *face = startEdge->F;
		do{
			//if(currEdge->SYM != 0){
			//	currEdge->SYM->SYM = 0;//deletes its SYM's reference to itself
			//}

			//delete edges from list of half edges
			halfEdges.erase(remove(halfEdges.begin(), halfEdges.end(), currEdge),halfEdges.end());
			currEdge = currEdge->NEXT;
		}while(startEdge != currEdge);

		//checks to see if the remaining vertices are not referenced by any of the half edges
		//These are "hanging vertices" and should be deleted.
		do{
			//std::cout<<"hanging vertex check"<<std::endl;

			Vertex* checkV = currEdge->V;
			//std::cout<<"vertex id:"<<checkV->ID<<std::endl;//print check
			bool hangingV = true;
			for(int i = 0; i < halfEdges.size(); i++){
				if(halfEdges.at(i)->V == checkV){
					//std::cout<<"halfEdge:"<<halfEdges.at(i)->ID<<std::endl;//print check
					hangingV = false;
					break;
				}
			}
			if(hangingV){
				//std::cout<<"removing hanging V check. Will remove v id:"<<checkV->ID<<std::endl;
				vertices.erase(remove(vertices.begin(), vertices.end(), checkV), vertices.end());
				hangingvs.push_back(checkV);//adds the hangingV to a vector that will be deleted at the end
			}
			currEdge = currEdge->NEXT;
		}while(startEdge != currEdge);


		//remove face from faces
		Face *face = startEdge->F;
		faces.erase(remove(faces.begin(), faces.end(), face),faces.end());
		//delete face;
		face = 0;
	}

	//Finally delete the vertex
	vertices.erase(remove(vertices.begin(), vertices.end(), v), vertices.end());
	delete v;

	//delete the hangingV's
	hangingvs.clear();


	//Print check//
	//std::cout<<faces.size()<<" faces"<<std::endl;
	//std::cout<<vertices.size()<<" vertices"<<std::endl;
	//std::cout<<halfEdges.size()<<" halfEdges"<<std::endl;
	//std::cout<<""<<std::endl;
	//std::cout<<"print vertices"<<std::endl;
	//for(int i = 0; i < vertices.size(); i++){
	//	std::cout<<i <<":"<<std::ends;
	//	vertices.at(i)->print();
	//}

	std::cout<<"vertex deleted"<<std::endl;

	//Now that a change to the mesh has been made, the display list must
	//be updated
	GLWidget->updateDisplayList();

}

//returns the normal vector for a plane
vec3 Mesh::getNormal(Face*F){

	HalfEdge* startEdge = F->HE;
	HalfEdge* currEdge = startEdge; // i
	HalfEdge* nextEdge = currEdge->NEXT; // j
	float a = 0;
	float b = 0;
	float c = 0; //initialized values for the vec3 normal vector

	//calculate the values for a, b, and c by looping through all the vertices (see notes)
	do{
		a = a + (currEdge->V->getY() - nextEdge->V->getY()) * (currEdge->V->getZ() + nextEdge->V->getZ());
		b = b + (currEdge->V->getZ() - nextEdge->V->getZ()) * (currEdge->V->getX() + nextEdge->V->getX());
		c = c + (currEdge->V->getX() - nextEdge->V->getX()) * (currEdge->V->getY() + nextEdge->V->getY());

		currEdge = currEdge->NEXT;
		nextEdge = nextEdge->NEXT;
	}while(currEdge!= startEdge);

	//return the normal vector
	return vec3(a,b,c);
}


//checks if the given face is planar
bool Mesh::isPlanar(Face *F){

	//for each vertex in the face, take the dot product between the unit length vector of 
	//2 vertices and the unit length normal vector at the polygon centroid. The face is planar
	//if the resulting value < EPSILON
	bool isPlanar = true;
	HalfEdge* startEdge = F->HE;
	HalfEdge* currEdge = startEdge; // i
	HalfEdge* nextEdge = currEdge->NEXT; // j
	float a = 0;
	float b = 0;
	float c = 0; //initialized values for the vec3 normal vector

	//calculate the values for a, b, and c by looping through all the vertices (see notes)
	do{
		a = a + (currEdge->V->getY() - nextEdge->V->getY()) * (currEdge->V->getZ() + nextEdge->V->getZ());
		b = b + (currEdge->V->getZ() - nextEdge->V->getZ()) * (currEdge->V->getX() + nextEdge->V->getX());
		c = c + (currEdge->V->getX() - nextEdge->V->getX()) * (currEdge->V->getY() + nextEdge->V->getY());

		currEdge = currEdge->NEXT;
		nextEdge = nextEdge->NEXT;
	}while(currEdge!= startEdge);

	//create the normal vector
	vec3 normal = vec3(a,b,c);

	//PRINT CHECK!
	//std::cout<<"normal:"<<a<<", "<<b<<", "<<c<<std::endl;

	//Now take the dot product between the normal vector and the vector between two consecutive vertices
	//and compare it to EPSILON
	do{
		vec3 v1 = vec3(currEdge->V->v); //v1 of an edge
		vec3 v2 = vec3(nextEdge->V->v); //v2 of an edge

		//std::cout<<"dot product:"<<(v2-v1) * normal<<std::endl;

		//check if the dot product is within EPSILON (greater than -E, less than +E)
		//if so, the planar. If not, then non planar
		if(!withinEpsilon((v2-v1) * normal)){
			isPlanar = false;
			break;
		}
		currEdge = currEdge->NEXT;
		nextEdge = nextEdge->NEXT;
	}while(currEdge != startEdge);

	return isPlanar;
}

//implementation of ray-plane intersection (plane is infinite)
//checks that the polygon is planar, but it need not be convex
//p1 and p2 define the 2 points of the ray
//returns the point of intersection
vec3 Mesh::rayPlaneIntersect(vec3 p1, vec3 p2, Face *F){
	bool intersect = false;
	vec3 intersection;
	if(isPlanar(F)){

		//find arbitrary vertex on the Face
		HalfEdge *he = F->HE;
		Vertex *v = he->V;

		//vec3 p1 = vec3(V1->getX(), V1->getY(), V1->getZ());
		//vec3 p2 = vec3(V2->getX(), V2->getY(), V2->getZ());
		vec3 normal = getNormal(F);
		vec3 s = vec3(v->getX(), v->getY(), v->getZ());
		vec3 ray = p2 - p1;
		float t;

		//PRINT CHECK!
		//std::cout<<"RAY PLANE INTERSECT"<<std::endl;
		//std::cout<<"p1:("<<p1[0]<<", "<<p1[1]<<", "<<p1[2]<<")"<<std::endl;
		//std::cout<<"p2:("<<p2[0]<<", "<<p2[1]<<", "<<p2[2]<<")"<<std::endl;
		//std::cout<<"s(arb pt on face):("<<s[0]<<", "<<s[1]<<", "<<s[2]<<")"<<std::endl;
		//std::cout<<"ray:("<<ray[0]<<", "<<ray[1]<<", "<<ray[2]<<")"<<std::endl;
		//std::cout<<"normal:("<<normal[0]<<", "<<normal[1]<<", "<<normal[2]<<")"<<std::endl;
		//std::cout<<"normal * ray: " << normal * ray <<std::endl;
		//std::cout<<""<<std::endl;

		//now solve for t using formula given in notes (t = N ·(S – P1) / N ·(P2 – P1))
		//first check if denominator = 0;
		if(withinEpsilon(normal * ray)){
			//the line P2 – P1 is parallel to the  plane and there are either no solutions 
			//or an infinite number (line in plane).
			intersect = false; 
		}
		else{
			t = (normal * (s-p1)) / (normal * (p2-p1));

			//PRINT CHECK!
			//std::cout<<"t is:"<<t<<std::endl;

			//If intersection with ray is required, check 0 <= t.
			if(0 <= t){
				intersect = true;
				intersection = p1 + t * (p2-p1);
				//if intersection occurs, return the intersection point
			}
		}
	}
	//PRINT CHECK!
	//std::cout<<"Face "<<F->ID<<" ray-plane intersection is: "<<intersection[0]<<", "<<intersection[1]<<", "<<intersection[2]<<std::endl;
	//std::cout<<""<<std::endl;
	return intersection;
}

//checks if a point lies on the specified face (in 2D)
//drops/disregards the specified coordinate (0=x, 1=y, 2=z)
//Note: this always processes the first 2 coordinates in the Vertex/vec3
bool Mesh::pointInPoly(vec3 p, Face *F, int toDrop){
	bool inside = false;
	vec3 p1;
	vec3 p2;
	vec3 point = p;
	HalfEdge *startEdge = F->HE;
	HalfEdge *currEdge = startEdge;
	HalfEdge *nextEdge = currEdge->NEXT;

	//first modify the point so appropriate coordinates are dropped.
	//this shouldn't be in the loop, since the edges are iterated, but the point should stay constant
	if(toDrop == 0){
		point[0] = point[1];//drops the x coordinate of the point
		point[1] = point[2]; 
	}

	else if(toDrop == 1){
		point[1] = point[2]; //drops the y coordinate. moves z up 1
	}

	else if(toDrop == 2){ //drops the z coordinate
		//no need to do anything since this automatially uses the first 2 coordinates)
	}


	//Now iterate through each edge using given code in slides
	do{
		p1 = vec3(currEdge->V->v); //get first edge endpoint from polygon (cast from vec4 to vec3)
		p2 = vec3(nextEdge->V->v); //get second edge endpoint from polygon

		//now modifies p1 and p2 (drops the specified coordinate)
		if(toDrop == 0){
			//drops the x coordinate (moves y up 1, z up 1)
			p1[0] = p1[1];
			p1[1] = p1[2];
			p2[0] = p2[1];
			p2[1] = p2[2];
		}

		else if(toDrop == 1){
			//drops the y coordinate (moves z up 1, x stays the same)
			p1[1] = p1[2];
			p2[1] = p2[2];
		}

		else if(toDrop == 2){
			//drops the z coordinate (x and y stay the same)
			//no need to do anything since this automatially uses the first 2 coordinates)
		}

		//PRINT CHECK!
		/*std::cout<<"dropped coordinate:"<<toDrop<<std::endl;
		std::cout<<"projection plane/modified point (with coordinates dropped)"<<std::endl;
		std::cout<<"point:"<<point[0]<<", "<<point[1]<<std::endl;
		std::cout<<"p1:"<<p1[0]<<", "<<p1[1]<<", "<<std::endl;
		std::cout<<"p2:"<<p2[0]<<", "<<p2[1]<<", "<<std::endl;
		std::cout<<""<<std::endl;*/


		if(p1[1] > p2[1]){ //want p1 to p2 to point in +y direction
			vec3 temp = p1;
			p1 = p2;
			p2 = temp;
		}

		if(point[1] > p1[1]){ //above lower edge point
			if(point[1] <= p2[1]){ //below upper edge endpoint
				if(p1[1] != p2[1]){ //if edge is not horizontal do half-plane check
					//z of cross product (point-p1, p2-p1)>0 means we're to the right
					if((point[0] - p1[0]) * (p2[1] - p1[1])
							-((p2[0] - p1[0]) * (point[1] - p1[1])) > 0){
						inside = !inside;
						// if true, point is to right of edge (and thus in the “strip”)
					}
				}
			}	
		}
		currEdge = currEdge->NEXT;
		nextEdge = nextEdge->NEXT;

	}while (currEdge != startEdge);

	return inside;
}

//checks whether the ray intersects the polygon
bool Mesh::rayPolyIntersect(vec3 p1, vec3 p2, Face *F){
	//first check if the polygon/face is planar
	//std::cout<<"planar ?? "<<isPlanar(F)<<endl;
	if(isPlanar(F)){
		//intersect ray with the Face and find the point of intersection
		vec3 intersection = rayPlaneIntersect(p1, p2, F);
		vec3 normal = getNormal(F);
		//Face *modifedFace = new Face(); //initialize face w/ dropped coordinate

		//determine which coordinate to drop (the largest one in the normal)
		int largest = 0;
		for(int i = 0; i < 3; i++){
			if(fabs(normal[i]) > fabs(normal[largest])){ //use absolute val to account for large neg values
				largest = i;
			}
		}

		//now run point-in-polygon while specifying which coordinate to ignore
		//the result indicates if the ray intersects the polygon (so return)
		return pointInPoly(intersection, F, largest);
	}

	return false;
}


//checks if the value is within epsilon 
bool Mesh::withinEpsilon(float f){
	if(f > -1*EPSILON && f < EPSILON){
		return true;
	}
	else
		return false;
}

void Mesh::smooth(){
	//std::cout<<"MESH SMOOTH CALLED"<<endl;

	//call this method for every face before we start smoothing things
	//if called after smoothing has started funny/bad things happen with numEdges()
	vector < Vertex* > newV = vertices;
	for (int i = 0; i < faces.size(); i++){
		Vertex* ct = faces.at(i)->getCentroid();
		//these will become new vertices, so let's add them
		newV.push_back(ct);
	}
	//same for edgepoints and midpoints
	for (int j = 0; j < halfEdges.size(); j++){
		Vertex* ep = halfEdges.at(j)->getEdgePoint();
		halfEdges.at(j)->getMidpoint();
		//the edgepoints will also become vertices, let's add those (NOT midpoints)
		bool added = false;
		for (int t = 0; t < newV.size(); t++){
			if( abs(ep->getX() - newV.at(t)->getX()) < EPS & abs(ep->getY() - newV.at(t)->getY()) < EPS & abs(ep->getZ() - newV.at(t)->getZ()) < EPS ){
				added = true;
			}
		}
		if (added == false){
			newV.push_back(ep);
		}
	}
	//after the methods have been called we can just refer to F->centroid, etc.

	//now we want to adjust the original vertices
	for (int v = 0; v < vertices.size(); v++){
		//find the edges that point to this vertex and save them in a vector
		vector < HalfEdge* > adjEdges;
		for (int e = 0; e < halfEdges.size(); e++){
			if (halfEdges.at(e)->V == vertices.at(v)){
				//if ( abs(halfEdges.at(e)->V->getX() - vertices.at(v)->getX()) < EPS & abs(halfEdges.at(e)->V->getY() - vertices.at(v)->getY()) < EPS & abs(halfEdges.at(e)->V->getZ() - vertices.at(v)->getZ()) < EPS ){
				adjEdges.push_back(halfEdges.at(e));
			}
		}
		//std::cout<<"adjEdge size "<<adjEdges.size()<<endl;
		//initialize floats to hold the x, y, and z values of the midpoints
		float edgeX = 0.0;
		float edgeY = 0.0;
		float edgeZ = 0.0;
		//and the x, y, and z for neighboring face centroids
		float faceX = 0.0;
		float faceY = 0.0;
		float faceZ = 0.0;
		for (int m = 0; m < adjEdges.size(); m++){
			//add edge midpoints
			edgeX += adjEdges.at(m)->midpoint->getX();
			edgeY += adjEdges.at(m)->midpoint->getY();
			edgeZ += adjEdges.at(m)->midpoint->getZ();
			//add face centroids
			faceX += adjEdges.at(m)->F->centroid->getX();
			faceY += adjEdges.at(m)->F->centroid->getY();
			faceZ += adjEdges.at(m)->F->centroid->getZ();
		}
		float valence = adjEdges.size();
		float edgeAvgX = edgeX/valence;
		float edgeAvgY = edgeY/valence;
		float edgeAvgZ = edgeZ/valence;
		float faceAvgX = faceX/valence;
		float faceAvgY = faceY/valence;
		float faceAvgZ = faceZ/valence;
		float finalX = (faceAvgX/valence) + ( (2*edgeAvgX) / valence ) + ( (vertices.at(v)->getX() * (valence-3) ) / valence );
		float finalY = (faceAvgY/valence) + ( (2*edgeAvgY) / valence ) + ( (vertices.at(v)->getY() * (valence-3) ) / valence );
		float finalZ = (faceAvgZ/valence) + ( (2*edgeAvgZ) / valence ) + ( (vertices.at(v)->getZ() * (valence-3) ) / valence );
		vertices.at(v)->v[0] = finalX;
		vertices.at(v)->v[1] = finalY;
		vertices.at(v)->v[2] = finalZ;
		//std::cout<<"switch ";
		//vertices.at(v)->print();
	}

	//now call smooth for all the faces
	//we added new faces in the process, we need to update the mesh face vector
	vector < Face* > newF = faces;
	vector < HalfEdge* > newE;
	float r = 0.0;
	float g = 0.0;
	float b = 0.0;
	int faceID = faces.size();
	for (int k = 0; k < faces.size(); k++){
		vector < Face* > f = faces.at(k)->smooth(newV, r, g, b);
		for (int x = 0; x < f.size(); x++){ //add these new faces to the existing set
			f.at(x)->ID = faceID;
			newF.push_back(f.at(x));
			faceID += 1;
		}
		r = r + (0.05*f.size());
		g = g + (0.05*f.size());
		b = b + (0.05*f.size());
		if (r > 1.0){
			r = 0.0;
		}
		if (g > 2.0){
			g = 0.0;
		}
		if (b > 3.0){
			b = 0.0;
		}
	}
	faces = newF;
	for (int f = 0; f < faces.size(); f++){
		faces.at(f)->adjustSym();
		//while we're trapezing through, add the new edges as well
		HalfEdge* orig = faces.at(f)->HE;
		HalfEdge* nex = faces.at(f)->HE;
		do{
			//this bit for adding the new vertices is not terribly efficient,
			//but was all I could think of for the moment
			bool vAdded = false;
			/*for (int vt = 0; vt < newV.size(); vt++){
				if (nex->V->getX() == newV.at(vt)->getX() & nex->V->getY() == newV.at(vt)->getY() & nex->V->getZ() == newV.at(vt)->getZ()){
					vAdded = true;
				}
			}
			if (vAdded == false){
				newV.push_back(nex->V);
			}*/
			newE.push_back(nex);
			nex = nex->NEXT;
		} while(nex != orig);
	}
	halfEdges = newE;
	vertices = newV;
	/*std::cout<<"num HE "<<halfEdges.size()<<endl;
	for (int w = 0; w < halfEdges.size(); w++){
		halfEdges.at(w)->V->print();
	}*/
	/*std::cout<<"vertices"<<endl;
	for (int d = 0; d < vertices.size(); d++){
		vertices.at(d)->print();
	}*/
	//FFD();

	//TESTING: Go through faces and split into triangles if not planar
}

void Mesh::FFD(){
	for (int t = 0; t < vertices.size(); t++){
		origVerts.push_back( new Vertex( vertices.at(t)->getX(), vertices.at(t)->getY(), vertices.at(t)->getZ() ) );
	}


	//we'll need to know the dimensions of the lattice we're to build
	//and we need to be sure that it contains all of the mesh
	//first let's find the min values
	float minX = faces.at(0)->minX();
	float minY = faces.at(0)->minY();
	float minZ = faces.at(0)->minZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->minX() < minX ){
			minX = faces.at(i)->minX();
		}
		if ( faces.at(i)->minY() < minY ){
			minY= faces.at(i)->minY();
		}
		if ( faces.at(i)->minZ() < minZ ){
			minZ = faces.at(i)->minZ();
		}
	}
	//and now the max values
	float maxX = faces.at(0)->maxX();
	float maxY = faces.at(0)->maxY();
	float maxZ = faces.at(0)->maxZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->maxX() > maxX ){
			maxX = faces.at(i)->maxX();
		}
		if ( faces.at(i)->maxY() > maxY ){
			maxY= faces.at(i)->maxY();
		}
		if ( faces.at(i)->maxZ() > maxZ ){
			maxZ = faces.at(i)->maxZ();
		}
	}

	//let's start with a 4X4X4 lattice
	//we have coordinate for the endpoints, now we need the two in the middle
	float xInc = (maxX - minX) / 3;
	float yInc = (maxY - minY) / 3;
	float zInc = (maxZ - minZ) / 3;

	float xCoor1 = minX + xInc;
	float xCoor2 = maxX - xInc;
	float yCoor1 = minY + yInc;
	float yCoor2 = maxY - yInc;
	float zCoor1 = minZ + zInc;
	float zCoor2 = maxZ - zInc;

	//now we need to create a lot of points
	vector <float> zs; //holds the z value so we can cycle through it in this manner
	zs.push_back(minZ);
	zs.push_back(zCoor1);
	zs.push_back(zCoor2);
	zs.push_back(maxZ);

	vector <float> ys; //holds the z value so we can cycle through it in this manner
	ys.push_back(minY);
	ys.push_back(yCoor1);
	ys.push_back(yCoor2);
	ys.push_back(maxY);

	//now let's create the points
	for (int j = 0; j < zs.size(); j++){
		for (int k = 0; k < ys.size(); k++){
			controlPoints.push_back( new Vertex (minX, ys.at(k), zs.at(j) ) );
			controlPoints.push_back( new Vertex (xCoor1, ys.at(k), zs.at(j) ) );
			controlPoints.push_back( new Vertex (xCoor2, ys.at(k), zs.at(j) ) );
			controlPoints.push_back( new Vertex (maxX, ys.at(k), zs.at(j) ) );
		}
	}
	for (int id = 0; id < controlPoints.size(); id++){
		controlPoints.at(id)->ID = id;
	}


	for (int t = 0; t < controlPoints.size(); t++){
		origCP.push_back( new Vertex( controlPoints.at(t)->getX(), controlPoints.at(t)->getY(), controlPoints.at(t)->getZ() ) );
	}

	//now let's create the embedded mesh where each vertex is ( x-minX, y-minY, z-minZ )
	//std::cout<<"vertice size "<<vertices.size()<<endl;
	for (int m = 0; m < vertices.size(); m++){
		embeddedMeshOld.push_back( new Vertex( origVerts.at(m)->getX() - minX, origVerts.at(m)->getY() - minY, origVerts.at(m)->getZ() - minZ ) );
		embeddedMeshOld.at(m)->print();
	}

	//calculate control points position based on this system now
	controlPointsNew.clear();
	for (int p = 0; p < controlPoints.size(); p++){
		controlPointsNew.push_back( new Vertex( controlPoints.at(p)->getX() - minX, controlPoints.at(p)->getY() - minY, controlPoints.at(p)->getZ() - minZ ) );
	}

	//and then do something funky based on the crazy slide formula?
	std::cout<<"embedded mesh"<<endl;
	for (int n = 0; n < embeddedMeshOld.size(); n++){
		float xnew = 0.0;
		float ynew = 0.0;
		float znew = 0.0;
		for (int c = 0; c < controlPoints.size(); c++){
			//from slides
			xnew += pow( embeddedMeshOld.at(n)->getX() + embeddedMeshOld.at(n)->getX(), 3) * controlPointsNew.at(c)->getX();
			ynew += pow( embeddedMeshOld.at(n)->getY() + embeddedMeshOld.at(n)->getY(), 3) * controlPointsNew.at(c)->getY();
			znew += pow( embeddedMeshOld.at(n)->getZ() + embeddedMeshOld.at(n)->getZ(), 3) * controlPointsNew.at(c)->getZ();

			//crap I'm totally making up, wooo
			//xnew += embeddedMeshOld.at(n)->getX() * ( (embeddedMeshOld.at(n)->getX() - controlPointsNew.at(c)->getX()) / (maxX-minX) );
			//ynew += embeddedMeshOld.at(n)->getY() * ( (embeddedMeshOld.at(n)->getY() - controlPointsNew.at(c)->getY()) / (maxY-minY) );
			//znew += embeddedMeshOld.at(n)->getZ() * ( (embeddedMeshOld.at(n)->getZ() - controlPointsNew.at(c)->getZ()) / (maxZ-minZ) );
		}
		embeddedMesh.push_back( new Vertex( xnew, ynew, znew ) );
		embeddedMesh.at(n)->print();
	}

	GLWidget->updateDisplayList();

	/*
	for (int h = 0; h < embeddedMesh.size(); h++){
		std::cout<<"WHATS GOING ON"<<endl;
		embeddedMesh.at(h)->print();
	}*/
}

void Mesh::deform(){
	//std::cout<<embeddedMesh.size()<<endl;
	vector<Vertex*> temp = embeddedMesh;

	//first let's find the min values
	float minX = faces.at(0)->minX();
	float minY = faces.at(0)->minY();
	float minZ = faces.at(0)->minZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->minX() < minX ){
			minX = faces.at(i)->minX();
		}
		if ( faces.at(i)->minY() < minY ){
			minY= faces.at(i)->minY();
		}
		if ( faces.at(i)->minZ() < minZ ){
			minZ = faces.at(i)->minZ();
		}
	}
	//and now the max values
	float maxX = faces.at(0)->maxX();
	float maxY = faces.at(0)->maxY();
	float maxZ = faces.at(0)->maxZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->maxX() > maxX ){
			maxX = faces.at(i)->maxX();
		}
		if ( faces.at(i)->maxY() > maxY ){
			maxY= faces.at(i)->maxY();
		}
		if ( faces.at(i)->maxZ() > maxZ ){
			maxZ = faces.at(i)->maxZ();
		}
	}

	//recalculate control points position based on this system now
	//controlPointsNew.clear();
	for (int p = 0; p < controlPoints.size(); p++){
		controlPointsNew.at(p)->setX( controlPoints.at(p)->getX() - minX );
		controlPointsNew.at(p)->setY( controlPoints.at(p)->getY() - minY );
		controlPointsNew.at(p)->setZ( controlPoints.at(p)->getZ() - minZ );
		//controlPointsNew.push_back( new Vertex( controlPoints.at(p)->getX() - minX, controlPoints.at(p)->getY() - minY, controlPoints.at(p)->getZ() - minZ ) );
	}

	//compute the new embedded mesh values
	//std::cout<<"embeddedMesh new"<<endl;
	vector<Vertex*> embeddedMeshNew;
	//std::cout<<"em size "<<embeddedMesh.size()<<endl;
	for (int n = 0; n < embeddedMesh.size(); n++){
		float xnew = 0.0;
		float ynew = 0.0;
		float znew = 0.0;
		for (int c = 0; c < controlPoints.size(); c++){
			xnew += pow( embeddedMeshOld.at(n)->getX() + embeddedMeshOld.at(n)->getX(), 3) * controlPointsNew.at(c)->getX();
			ynew += pow( embeddedMeshOld.at(n)->getY() + embeddedMeshOld.at(n)->getY(), 3) * controlPointsNew.at(c)->getY();
			znew += pow( embeddedMeshOld.at(n)->getZ() + embeddedMeshOld.at(n)->getZ(), 3) * controlPointsNew.at(c)->getZ();

			//crap I'm totally making up, wooo
			//xnew += embeddedMeshOld.at(n)->getX() * ( (embeddedMeshOld.at(n)->getX() - controlPointsNew.at(c)->getX()) / (maxX-minX) );
			//ynew += embeddedMeshOld.at(n)->getY() * ( (embeddedMeshOld.at(n)->getY() - controlPointsNew.at(c)->getY()) / (maxY-minY) );
			//znew += embeddedMeshOld.at(n)->getZ() * ( (embeddedMeshOld.at(n)->getZ() - controlPointsNew.at(c)->getZ()) / (maxZ-minZ) );
		}
		//embeddedMeshNew.at(n)->setX(xnew);
		//embeddedMeshNew.at(n)->setY(ynew);
		//embeddedMeshNew.at(n)->setZ(znew);
		Vertex* v = new Vertex( xnew, ynew, znew );
		embeddedMeshNew.push_back(v);
		//embeddedMeshNew.at(n)->print();
	}

	//std::cout<<"em size "<<embeddedMesh.size()<<endl;


	//find the differences between the new and old values
	//std::cout<<"differences"<<endl;
	//std::cout<<"emesh size "<<embeddedMeshNew.size()<<endl;
	vector<Vertex*> differences;
	for (int i = 0; i < embeddedMesh.size(); i++){
		//std::cout<<"hiya "<<embeddedMeshNew.at(i)->getX()<<" "<<embeddedMesh.at(i)->getX()<<endl;
		differences.push_back( new Vertex( embeddedMeshNew.at(i)->getX() - embeddedMesh.at(i)->getX(), embeddedMeshNew.at(i)->getY() - embeddedMesh.at(i)->getY(), embeddedMeshNew.at(i)->getZ() - embeddedMesh.at(i)->getZ()) );
		differences.at(i)->print();
	}


	//now alter the original vertices
	//std::cout<<"YO YO "<<vertices.size()<<" "<<differences.size()<<endl;
	for (int j = 0; j < vertices.size(); j++){
		vertices.at(j)->setX( origVerts.at(j)->getX() + differences.at(j)->getX() );
		vertices.at(j)->setY( origVerts.at(j)->getY() + differences.at(j)->getY() );
		vertices.at(j)->setZ( origVerts.at(j)->getZ() + differences.at(j)->getZ() );
	}

}

//crap deform to take the place
void Mesh::deform(int index){

	//first let's find the min values
	float minX = faces.at(0)->minX();
	float minY = faces.at(0)->minY();
	float minZ = faces.at(0)->minZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->minX() < minX ){
			minX = faces.at(i)->minX();
		}
		if ( faces.at(i)->minY() < minY ){
			minY= faces.at(i)->minY();
		}
		if ( faces.at(i)->minZ() < minZ ){
			minZ = faces.at(i)->minZ();
		}
	}
	//and now the max values
	float maxX = faces.at(0)->maxX();
	float maxY = faces.at(0)->maxY();
	float maxZ = faces.at(0)->maxZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->maxX() > maxX ){
			maxX = faces.at(i)->maxX();
		}
		if ( faces.at(i)->maxY() > maxY ){
			maxY= faces.at(i)->maxY();
		}
		if ( faces.at(i)->maxZ() > maxZ ){
			maxZ = faces.at(i)->maxZ();
		}
	}

	//let's start with a 4X4X4 lattice
	//we have coordinate for the endpoints, now we need the two in the middle
	float xInc = (maxX - minX) / 3;
	float yInc = (maxY - minY) / 3;
	float zInc = (maxZ - minZ) / 3;

	std::cout<<"Ladida "<<vertices.size()<<" "<<origCP.size()<<" "<<controlPoints.size()<<endl;

	for (int i = 0; i < vertices.size(); i++){
		if( vertices.at(i)->getX() - origCP.at(index)->getX() <= (xInc + EPS)){
			if( vertices.at(i)->getY() - origCP.at(index)->getY() <= (yInc + EPS)){
				if( vertices.at(i)->getZ() - origCP.at(index)->getZ() <= (zInc + EPS)){

					vertices.at(i)->setX( origVerts.at(i)->getX() + (controlPoints.at(index)->getX() - origCP.at(index)->getX()) );
					vertices.at(i)->setY( origVerts.at(i)->getY() + (controlPoints.at(index)->getY() - origCP.at(index)->getY()) );
					vertices.at(i)->setZ( origVerts.at(i)->getZ() + (controlPoints.at(index)->getZ() - origCP.at(index)->getZ()) );
				}
			}
		}
	}

	GLWidget->updateDisplayList();
}

void Mesh::FFD(int s, int t, int u){

	controlPoints.clear();

	for (int t = 0; t < vertices.size(); t++){
		origVerts.push_back( new Vertex( vertices.at(t)->getX(), vertices.at(t)->getY(), vertices.at(t)->getZ() ) );
	}


	//we'll need to know the dimensions of the lattice we're to build
	//and we need to be sure that it contains all of the mesh
	//first let's find the min values
	float minX = faces.at(0)->minX();
	float minY = faces.at(0)->minY();
	float minZ = faces.at(0)->minZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->minX() < minX ){
			minX = faces.at(i)->minX();
		}
		if ( faces.at(i)->minY() < minY ){
			minY= faces.at(i)->minY();
		}
		if ( faces.at(i)->minZ() < minZ ){
			minZ = faces.at(i)->minZ();
		}
	}
	//and now the max values
	float maxX = faces.at(0)->maxX();
	float maxY = faces.at(0)->maxY();
	float maxZ = faces.at(0)->maxZ();
	for (int i = 1; i < faces.size(); i++){
		if ( faces.at(i)->maxX() > maxX ){
			maxX = faces.at(i)->maxX();
		}
		if ( faces.at(i)->maxY() > maxY ){
			maxY= faces.at(i)->maxY();
		}
		if ( faces.at(i)->maxZ() > maxZ ){
			maxZ = faces.at(i)->maxZ();
		}
	}

	float xInc = abs(maxX - minX) / (s-1);
	float yInc = abs(maxY - minY) / (t-1);
	float zInc = abs(maxZ - minZ) / (u-1);

	vector<float> xs;
	for (int a = 0; a < s; a++){
		xs.push_back(minX + (a*xInc));
	}
	vector<float> ys;
	for (int b = 0; b < t; b++){
		ys.push_back(minY + (b*yInc));
	}
	vector<float> zs;
	for (int d = 0; d < u; d++){
		zs.push_back(minZ + (d*zInc));
	}

	//now let's create the points
	for (int j = 0; j < zs.size(); j++){
		for (int k = 0; k < ys.size(); k++){
			for (int l = 0; l < xs.size(); l++){
				controlPoints.push_back( new Vertex (xs.at(l), ys.at(k), zs.at(j) ) );
			}
		}
	}

	for (int id = 0; id < controlPoints.size(); id++){
		controlPoints.at(id)->ID = id;
	}


	for (int t = 0; t < controlPoints.size(); t++){
		origCP.push_back( new Vertex( controlPoints.at(t)->getX(), controlPoints.at(t)->getY(), controlPoints.at(t)->getZ() ) );
	}

	//now let's create the embedded mesh where each vertex is ( x-minX, y-minY, z-minZ )
	//std::cout<<"vertice size "<<vertices.size()<<endl;
	for (int m = 0; m < vertices.size(); m++){
		embeddedMeshOld.push_back( new Vertex( origVerts.at(m)->getX() - minX, origVerts.at(m)->getY() - minY, origVerts.at(m)->getZ() - minZ ) );
		//embeddedMeshOld.at(m)->print();
	}

	//calculate control points position based on this system now
	controlPointsNew.clear();
	for (int p = 0; p < controlPoints.size(); p++){
		controlPointsNew.push_back( new Vertex( controlPoints.at(p)->getX() - minX, controlPoints.at(p)->getY() - minY, controlPoints.at(p)->getZ() - minZ ) );
	}

	//and then do something funky based on the crazy slide formula?
	//std::cout<<"embedded mesh"<<endl;
	for (int n = 0; n < embeddedMeshOld.size(); n++){
		float xnew = 0.0;
		float ynew = 0.0;
		float znew = 0.0;
		for (int c = 0; c < controlPoints.size(); c++){
			//from slides
			xnew += pow( embeddedMeshOld.at(n)->getX() + embeddedMeshOld.at(n)->getX(), 3) * controlPointsNew.at(c)->getX();
			ynew += pow( embeddedMeshOld.at(n)->getY() + embeddedMeshOld.at(n)->getY(), 3) * controlPointsNew.at(c)->getY();
			znew += pow( embeddedMeshOld.at(n)->getZ() + embeddedMeshOld.at(n)->getZ(), 3) * controlPointsNew.at(c)->getZ();

			//crap I'm totally making up, wooo
			//xnew += embeddedMeshOld.at(n)->getX() * ( (embeddedMeshOld.at(n)->getX() - controlPointsNew.at(c)->getX()) / (maxX-minX) );
			//ynew += embeddedMeshOld.at(n)->getY() * ( (embeddedMeshOld.at(n)->getY() - controlPointsNew.at(c)->getY()) / (maxY-minY) );
			//znew += embeddedMeshOld.at(n)->getZ() * ( (embeddedMeshOld.at(n)->getZ() - controlPointsNew.at(c)->getZ()) / (maxZ-minZ) );
		}
		embeddedMesh.push_back( new Vertex( xnew, ynew, znew ) );
		//embeddedMesh.at(n)->print();
	}

	GLWidget->updateDisplayList();

}

//deletes a face and replaces it with its centroid
void Mesh::deleteFace(Face *F){
	//check if face has less than 4 sides
	if(F->numEdges() < 4){
		return;
	}

	//check if incident faces have less than 4 sides
	HalfEdge *origEdge = F->HE;
	HalfEdge *currEdge = origEdge;
	do{
		if(currEdge->SYM->F->numEdges() <4)
			return;
		currEdge = currEdge->NEXT;
	}while(currEdge != origEdge);


	//Now on to the good stuff
	Vertex* centroid = F->getCentroid(); //find centroid of face to be deleted
	vertices.push_back(centroid); //addes the centroid to the vertices vector
	std::cout<<"centroid: ";
	centroid->print();

	vector<Vertex*> deleteV; //store Vertices to be deleted in queue
	vector<HalfEdge*> deleteHE; //store HalfEdges to be deleted in queue
	vector<HalfEdge*> deleteSYM; //stores all the Syms of the halfedges to be deleted
	vector<Face*> incidentFaces; //stores all the incident faces that might have their HE pointing to the one that will be deleted

	//Adds necessary elements to their vectors
	HalfEdge *orig = F->HE;
	HalfEdge *curr = orig;
	do{
		deleteV.push_back(curr->V);
		deleteHE.push_back(curr);
		deleteSYM.push_back(curr->SYM);
		incidentFaces.push_back(curr->SYM->F);
		curr = curr->NEXT;
	}while(curr != orig);

	//loop through vector of SYMs and reset their HE and V pointers
	for(int i = 0; i < deleteSYM.size(); i++){
		HalfEdge *sym = deleteSYM.at(i);
		HalfEdge *orig = sym;
		HalfEdge *curr = orig;
		HalfEdge *edge2 = sym->NEXT;
		HalfEdge *edge1;

		//Now find edge1
		do{
			if(curr->NEXT == sym && curr->NEXT->NEXT == edge2){
				edge1 = curr;
				std::cout<<"edge1 found"<<std::endl;
			}
			curr = curr->NEXT;
		}while(curr != orig);

		//When edge 1 is found, reset its V and NEXT values to the centroid and edge 2
		edge1->NEXT = edge2;
		edge1->V = centroid;

		//Also reset the Face's HE to another one so it doesn't point at one in deleteSYM
		sym->F->HE = edge1;
	}

	//Now remove the stuff in deleteHE, deleteSYM, deleteV from the global vectors
	for(int i = 0; i < deleteHE.size(); i++){
		halfEdges.erase(remove(halfEdges.begin(), halfEdges.end(), deleteHE.at(i)), halfEdges.end());
		delete deleteHE.at(i);
	}

	for(int i = 0; i < deleteSYM.size(); i++){
		halfEdges.erase(remove(halfEdges.begin(), halfEdges.end(), deleteSYM.at(i)),halfEdges.end());
		delete deleteSYM.at(i);
	}

	for(int i = 0; i < deleteV.size(); i++){
		vertices.erase(remove(vertices.begin(), vertices.end(), deleteV.at(i)), vertices.end());
		delete deleteV.at(i);
	}

	//Finally remove the face
	faces.erase(remove(faces.begin(), faces.end(), F), faces.end());
	delete F;

	GLWidget->updateDisplayList();


}


//Face *face = startEdge->F;
//		faces.erase(remove(faces.begin(), faces.end(), face),faces.end());
//		//delete face;
//		face = 0;
//	}
//
//	//Finally delete the vertex
//	vertices.erase(remove(vertices.begin(), vertices.end(), v), vertices.end());
//	delete v;



//returns whether or not a face is convex
bool Mesh::isConvex(Face* toCheck){
	std::cout<<"check1"<<std::endl;
	HalfEdge *start = toCheck->HE;
	HalfEdge *curr = start;
	HalfEdge *next = curr->NEXT;
	Vertex* first = curr->V;
	Vertex* second = curr->NEXT->V;

	std::cout<<"check2"<<std::endl;

	float changex = 0;
	float changey = 0;
	float changez = 0;
	bool all = true;
	bool xpos = false;
	bool ypos = false;
	bool zpos = false;

	do{
		changex = abs(curr->V->getX()) - abs(next->V->getX());
		changey = abs(curr->V->getY()) - abs(next->V->getY());
		changez = abs(curr->V->getZ()) - abs(next->V->getZ());

		cout<<"prelim changes are "<<changex<<" "<<changey<<" "<<changez<<endl;

		xpos = isp(changex);
		ypos = isp(changey);
		zpos = isp(changez);
		curr = next;
		next = curr->NEXT;

		changex = abs(curr->V->getX()) - abs(next->V->getX());
		changey = abs(curr->V->getY()) - abs(next->V->getY());
		changez = abs(curr->V->getZ()) - abs(next->V->getZ());

		std::cout<<"check3"<<std::endl;


		if((isp(changex) != xpos)){
			std::cout<<"CHANGEX WRONG"<<std::endl;
			all = false;
		}
		if((changey != 0 && isp(changey)!=ypos)){
			all = false;
		}
		if((changez != 0 && isp(changez) != zpos)){
			all = false;
		}
		xpos = changex;
		ypos = changey;

		curr = curr->NEXT;
	}while(curr != start);

	return all;
}



//checks if a number is positive
bool Mesh::isp(double a){
	if(a>=0){
		return true;
	}
	return false;
}