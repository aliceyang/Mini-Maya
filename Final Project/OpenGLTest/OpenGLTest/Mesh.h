#ifndef MESH_H
#define MESH_H
#include "Face.h"
#include "Vertex.h"
#include "HalfEdge.h"
#include "algebra3.h"
#include "MyGLWidget.h"
#include <vector>
#define EPSILON .000001

using namespace std;

class MyGLWidget; //need to declare this class, since MyGL Widget has a pointer to here too

class Mesh{
public:
	vector<HalfEdge*> halfEdges; //stores a vector of half edges
	vector<Face*> faces; //keeps track of all faces in this mesh
	vector<Vertex*> vertices; //keeps track of all vertices in this mesh

	//sorry there's a crap-load of instance variables, I'm playing around with multiple things here
	vector<Vertex*> controlPoints; //keeps track of the lattice control points
	vector<Vertex*> origCP; //original control points to determine the difference
	vector<Vertex*> embeddedMesh; //"new" coordinates of mesh inside lattice (see slides)
	vector<Vertex*> embeddedMeshOld;
	vector<Vertex*> origVerts;
	vector<Vertex*> controlPointsNew; //keeps track of control points as they relate to themselves
	/*Have a pointer to this Mesh's corresponding MyGLWidget object
	 * so that when a change in the mesh is made, we can update its
	 * display list
	 */
	MyGLWidget* GLWidget;

	Mesh();
	~Mesh();

	//========================//
	//======Operations========//
	//========================//

	//Adds a Vertex to an Edge
	//Input: edge starting at vertex HE0->V; new VERTEX VN
	//Goal: Insert VN on edge just after HE0->V
	void addVertexToEdge(HalfEdge *HE0);

	//Adds an edge between 2 faces that share a vertex
	//Input: FACES FA and FB, and VERTEX HEA0->V and HEB0->V.
	void addEdgeBetweenFaces(Face *FA, Face *FB, Vertex* v);//HalfEdge *HEA0, HalfEdge *HEB0);
		
	//Split a quad into two triangles
	//Input: Face FACE1
	void SplitQuadToTriangles(Face *FACE1);

	//Creates a face based on exsisting given vertices (in a vector) and establishes 
	//proper relations between vertices,faces, and half edges.
	void addFace(vector<Vertex*> v);

	//builds cube mesh centered at the origin
	static Mesh* makeCube();

	//draws the mesh with transformations applied
	void drawMesh(vec3 eye, vec3 referencePoint, vec3 up);

	//deletes the specified vertex
	void deleteVertex(Vertex* v);

	//returns the normal vector (vec3) for the Face (unstatic later)
	static vec3 getNormal(Face*F);

	//planarity check with normal at the centroid (unstatic later)
	static bool isPlanar(Face *F);
	
	//implementation of ray-plane intersection (unstatic later)
	//uses the plane the Face is on
	//checks that the Face is planar, but it need not be convex. 
	//returns the point of intersection
	static vec3 rayPlaneIntersect(vec3 p1, vec3 p2, Face *F);

	//checks whether a point is in the face (unstatic later)
	static bool pointInPoly(vec3 p, Face *F, int toDrop);

	//checks whether the ray intersects the polygon (unstatic later)
	static bool rayPolyIntersect(vec3 p1, vec3 p2, Face *F);

	//checks if the value is within epsilon (unstatic later)
	static bool withinEpsilon(float f);

	//Catmull-Clark Subdivisions
	void smooth();

	//Free Form Deformations
	void FFD();
	void FFD(int s, int t, int u);

	void deform();

	void deform(int index); //input is the indice of the control point that has been moved


	//Geometer Functions
	void deleteFace(Face* F); //delete face by replacing it with its centroid

	bool isConvex(Face* toCheck); //checks if Face is convex

	bool isp(double a); //checks if a number is positive




};

#endif MESH_H
