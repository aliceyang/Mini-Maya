/*  
	MyGLWidget extends the QGLWidget class, which is the Qt Widget with built in OpenGL functionality.
	It has 3 essential functions: initializeGL, paintGL, resizeGL
	initializeGL - can be used to call some one time initialization parameters.  In this example, the clear color is set.
	paintGL - is called every time the QGLWidget needs to be repainted.  This is where you will visualize your geometry
	resizeGL - is called every time the QGLWidget is resized, and once initially as well.

*/

#include "MyGLWidget.h"
#include <iostream>
#include <math.h>
#include <QtGui>
#include <QtOpenGL>
#include <vector>
#include <math.h>


MyGLWidget::MyGLWidget(QWidget *parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	//default constructor, which will call the base constructor with some formatting parameters and the parent widget

	cam = new camera(); //creates new camera
	setFocusPolicy(Qt::StrongFocus);//for key press events
	
	//FOR HOMEWORK 6
	//m = Mesh::makeCube();
	//m->smooth();
	//now set the mesh's GLWidget to this
	m = new Mesh();
	m->GLWidget = this;

	//FOR FINAL PROJECT;
	displayListIndex = 1;

	bool centerOnVertex = false;

	//when the widget is created, lighting is off
	lightingEnabled = true;

	//push 8 lights on the vector
	for (int i = 0; i < 8; i++){
		Light* light = new Light();
		lights.push_back(light);
		//enable all the lights
		lights.at(i)->enable();
		if (i != 0){
			lights.at(i)->disable();
		}
	}



	orthographicView = false;

	rotationDisabled = false;

	inPerspectiveView = true;






}

//Deconstructor
MyGLWidget::~MyGLWidget(){
	delete cam;
	delete m;

}

void MyGLWidget::initializeGL(){


	glClearColor(0.0,0.0,0.0,1.0); //sets the background color
	glEnable(GL_DEPTH_TEST); //without this, order of drawing will determine which polygons are displayed
							// and not depth
	glDepthMask(GL_TRUE);



	//Here we set up the display list with an initial calling of
	//openGL functions to draw the cube

	//start the new display list with GL_COMPILE--this means that
	//the display list is created but the commands are not executed
	glNewList(displayListIndex, GL_COMPILE);
	//call the opengl commands to draw the mesh
		m->drawMesh(cam->eye, cam->referencePoint, cam->upVector);
	glEndList();
	
	emit sendMesh(m); //emits the cube mesh FaceTreeWidget and VertexTreeWidget

	//send the lights to the list widget

	for (int i = 0; i < 8; i++){
		emit sendLights(lights.at(i));
	}

}
void MyGLWidget::keyPressEvent(QKeyEvent *e){
	//a good place to process keystrokes

	//zoom out
	if(e->key() == Qt::Key_Z){
		cam->zoomIn();
		update();
	}

	//zoom in
	if(e->key() == Qt::Key_X){
		cam->zoomOut();
		update();
	}

	//rotate cube right/camera left
	if(e->key() == Qt::Key_Left){
		if (rotationDisabled){
			return;
		}
		cam->moveLeftRight(-5);
		update();
	}

	//rotate cube left/camera right
	if(e->key() == Qt::Key_Right){
		if (rotationDisabled){
			return;
		}
		cam->moveLeftRight(5);
		update();
	}

	//rotate cube down/camera up
	if(e->key() == Qt::Key_Up){
		if (rotationDisabled){
			return;
		}
		cam->moveUpDown(-5);
		update();
	}
	
	//rotate cube up/camera down
	if(e->key() == Qt::Key_Down){
		if (rotationDisabled){
			return;
		}
		cam->moveUpDown(5);
		update();
	}

	//***Panning and pedestalling the camera**
	//pan left
	if(e->key() == Qt::Key_A){
		cam->panLeft();
		update();
	}

	//pan right
	if(e->key() == Qt::Key_D){
		cam->panRight();
		update();
	}
	//pedestal Up
	if(e->key() == Qt::Key_W){
		cam->pedestalUp();
		update();
	}
	//pedestal down
	if(e->key() == Qt::Key_S){
		cam->pedestalDown();
		update();
	}
	//center scene
	if(e->key() == Qt::Key_C){
		cam->centerScene();
		update();
	}
	//center scene
	if(e->key() == Qt::Key_Space){
		if (cam->focusOnVertex == false){
			cam->centerOnSelectedFace();
			update();
		}
		else{
			cam->centerOnSelectedVertex();
			update();
		}
	}

	//Toggle lighting on/off
	if (e->key() == Qt::Key_L){
		if (lightingEnabled){
			disableLighting();
		}
		else{
			enableLighting();
		}
		update();
	}

	//go into top view
	if (e->key() == Qt::Key_1){
		frontView();
	}
	//go into right view
	if (e->key() == Qt::Key_2){
		rightProfile();
	}
	//go into right view
	if (e->key() == Qt::Key_3){
		leftProfile();
	}
	//go into right view
	if (e->key() == Qt::Key_4){
		topView();
	}
	//go into right view
	if (e->key() == Qt::Key_5){
		backView();
	}
	//go into right view
	if (e->key() == Qt::Key_6){
		bottomView();
	}
	//go into perspective view
	if (e->key() == Qt::Key_0){
		perspective();
	}
}

//calls made here are made every time the widget's contents are repainted.  notice how we are redrawing everything.
void MyGLWidget::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the screen and depth buffer
	glLoadIdentity(); //loads the identity matrix into the OpenGL matrix stack.  

	gluLookAt(cam->eye[0], cam->eye[1], cam->eye[2], cam->referencePoint[0], cam->referencePoint[1], cam->referencePoint[2], cam->upVector[0], cam->upVector[1], cam->upVector[2]);

	//execute the display list
	glCallList(displayListIndex);

	glLoadIdentity();

	glMatrixMode(GL_PROJECTION); //set the matrix mode to Projection
	glLoadIdentity(); //load the identity


	if (orthographicView){
		glOrtho(-3, 3, -3, 3, 1.0, 15.0);
	}
	else{
	//sets up a frustum for use in perspective viewing
	//glFrustum(left edge, right edge, bottom edge, top edge, distance to near clipping plane, distance to far clipping plane
	//the last two parameters must be positive.  this is the distance from the origin (0,0,0) to the near/far clipping plane
	//also remember that OpenGL points the camera in the direction of -z, so the front clipping plane is a plane stationed at z=-1,
	//and the far clipping plane is a plane stationed at z=-20
	glFrustum(-.5,.5,-.5,.5,1,60);
}
	glMatrixMode(GL_MODELVIEW); //change to the Modelview mode

	glLoadIdentity();
	if (lightingEnabled){
		// Lighting set up
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
		glEnable(GL_LIGHTING);


		/*  %%%NOTE: material RGB is set to be equal
		 * to light RGB--this is so that the material
		 * reflects the light at the same proportion
		 * that the light is giving off
		 */
		//set material intensity and color
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_DIFFUSE);
		//set up all lights that are enabled
		for (int i = 0; i < lights.size(); i++){
			if (lights.at(i)->enabled){
				lights.at(i)->enable();

				// Set lighting intensity and color
				lights.at(i)->setLighting();

				// Set the light position
				lights.at(i)->setPosition();
			}
		}
	}
	glLoadIdentity();

//	drawRay();
}

//this function is called every time the window is resized.
void MyGLWidget::resizeGL(int width, int height){
	int side = qMin(width, height);  //finds the min of the width and height.  helpful for different distortions of the window
	glViewport((width - side) / 2, (height - side) / 2, side, side); //set the viewport

}

//==Extra Credit==//

//void MyGLWidget::wheelEvent(QWheelEvent *event){
//	//handles zoom with mouse wheel
//	int numDegrees = event->delta() / 8;
//	int numSteps = numDegrees / 15;
//
//	if (event->orientation() == Qt::Vertical) {
//		cam->zoom(numSteps);
//		update();
//	}
//     event->accept();
// }

void MyGLWidget::mousePressEvent(QMouseEvent *event){
	//handles rotation with left mouse button
	prevX = event->x();
	prevY = event->y();

	//Given code for part 2 in Homework 7
	float x = event->x();
	float y = event->y();
	//std::cout<<"Someone clicked "<<x<<", "<<y<<std::endl;

	//change to normalized device coordinates
	x = x / this->width();
	y = y / this->height();

	//coordinate of eye
	vec3 eye = cam->getEye();//getViewVec();

	//up vector
	vec3 up = cam->getUp();

	//get viewing vector
	vec3 center = vec3(0,0,0); //different if center moves
	vec3 G = center - eye;

	//half viewing angles
	float fi = 30 * 3.14159/180.0; //26.56
	float theda = 30 * 3.14159/180.0;
	vec3 A = G ^ up;
	vec3 B = A ^ G;
	vec3 M = eye + G;
	vec3 H = (A*(G.length()*tan(theda)))/A.length();
	vec3 V = (B*(G.length()*tan(fi)))/B.length();
	P = M + (2*x - 1)*H + (1 - 2*y)*V; //testing
	std::cout << "The point is " <<P[0]<<", "<<P[1]<<", "<<P[2]<< std::endl;

	// The ray is: where t goes from 0 to infinity
	//vec3 R = eye + t*(P-eye)/(P-eye).length();
	//directionAtClick = d = (P-eye)/(P-eye).length();

	//defines the start and end points of the ray
	rayStart = eye;
	rayEnd = eye + 100*(P-eye)/(P-eye).length();

	//draws the ray
	drawRay();

	//selects the closer face (highlights as white)
	clickSelect();
	updateDisplayList();

	//code needed to intersect polygons would go here
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event){
	if(event->buttons() & Qt::LeftButton){
		dragRotate(event->x(), event->y());
	}
}

void MyGLWidget::mouseReleaseEvent(QMouseEvent *event){
	if(event->button() == Qt::LeftButton){
		dragRotate(event->x(), event->y());
	}
}

//rotates the cube from prevX to endX, and prevY to endY
void MyGLWidget::dragRotate(const int &endX, const int &endY){
	int xRotation = endX - prevX;
	int yRotation = endY - prevY;

	if (rotationDisabled){
		return;
	}
	if (xRotation < 0){
		cam->moveLeftRight(-xRotation);
	}
	else{
		cam->moveLeftRight(-xRotation);
	}
	if (yRotation < 0){
		cam->moveUpDown(-yRotation);
	}
	else{
		cam->moveUpDown(-yRotation);
	}

	prevX = endX; //updates prevX
	prevY = endY; //updates prevY
	update(); //repaints the scene
}

//FOR HOMEWORK 7 

//draws the ray using eyeAtClick and directionAtClick
void MyGLWidget::drawRay(){

	glLoadIdentity();
	gluLookAt(cam->eye[0], cam->eye[1], cam->eye[2], cam->referencePoint[0], cam->referencePoint[1], cam->referencePoint[2], cam->upVector[0], cam->upVector[1], cam->upVector[2]);

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex3f(rayStart[0], rayStart[1], rayStart[2]);
	glVertex3f(rayEnd[0], rayEnd[1], rayEnd[2]);
	glEnd();


	//std::cout<<"draw ray check"<<std::endl;
}


//changes the color of the frontmost face (to white)
void MyGLWidget::clickSelect(){
	// PART 3-4 Determine which face(polygon) lies under the cursor position. Need to choose the front-most one.
	
	vector<Face*> faces; //vector to store the faces the ray intersects (at most 2)
	
	std::cout<<"rayStart: "<<rayStart[0]<<" "<<rayStart[1]<<" "<<rayStart[2]<<std::endl;
	std::cout<<"rayEnd: "<<rayEnd[0]<<" "<<rayEnd[1]<<" "<<rayEnd[2]<<std::endl;

	for(int i= 0; i < m->faces.size(); i++){
		if(m->rayPolyIntersect(rayStart, rayEnd, m->faces.at(i))){ //something wrong with raypoly intersect?
			faces.push_back(m->faces.at(i));
		}
	}

	//PRINT CHECK!
	//std::cout<<"faces check: size = "<<faces.size()<<std::endl;
	//std::cout<<"intersecting faces:"<<std::endl;
	//for(int i; i < faces.size(); i++){
	//	std::cout<<faces.at(i)->ID<<std::endl;
	//}


	//if there are 2 faces the ray intersects, find the one that is closer to the eye
	Face* closerFace;
	if(faces.size() > 1){
		int closeri = 0;
		for(int i = 0; i < faces.size(); i++){
			//std::cout<<"print check"<<std::endl;
			//vec3 faceiInt = m->rayPlaneIntersect(startV, endV, faces.at(i));
			//vec3 faceCloseriInt = m->rayPlaneIntersect(startV, endV, faces.at(closeri));
			//if(distBetweenTwoVecs(rayStart,faceiIntersect) < distBetweenTwoVecs(rayStart,faceCloseriIntersect)){
				//closeri = i;

			//vec3 face = faces.at(i)->centroid() - rayStart; //vec3 diff between centroid and eye
			//vec3 closerFace = faces.at(closeri)->centroid() - rayStart;

			vec3 face = m->rayPlaneIntersect(rayStart, rayEnd, faces.at(i)) - rayStart;
			vec3 closerFace = m->rayPlaneIntersect(rayStart, rayEnd, faces.at(closeri)) - rayStart;

			//PRINT CHECK!
			//std::cout<<"rayStart: "<<rayStart[0]<<" "<<rayStart[1]<<" "<<rayStart[2]<<std::endl;
			//std::cout<<"Face i"<<faces.at(i)->ID<<" intersection:"<<face[0]<<" "<<face[1]<<" "<<face[2]<<std::endl;
			//std::cout<<"Face closeri"<<faces.at(i)->ID<<" intersection:"<<closerFace[0]<<" "<<closerFace[1]<<" "<<closerFace[2]<<std::endl;
			
			if(face.length2() < closerFace.length2()){ //compare the distances between each centroid and the eye
				closeri = i;
			}
		}

		Face *closerFace = faces.at(closeri);
		std::cout<<"closerFace ID:"<<closerFace->ID<<std::endl;
		std::cout<<""<<std::endl;
		
		emit sendFace(closerFace);
		closerFace->select();
		
		cam->currentFaceSelection = closerFace;
		cam->focusOnVertex = false;


	}

	//if the ray only intersects one face, then it automatically is the closerFace
	else if (faces.size() == 1){
		closerFace = faces.at(0);
		//now invert the color of the closerFace
		closerFace->select();
		emit sendFace(closerFace);
	}


	//TO DO: SELECTS THE CLOSEST VERTEX. WILL NEED TO ADD A MODE VARIABLE TO THIS 
	//FUNCTION LATER!



}

//finds the distance between two vec3's
double MyGLWidget::distBetweenTwoVecs(vec3 v1, vec3 v2){

	return sqrt((v2[0]-v1[0])*(v2[0]-v1[0]) + (v2[1]-v1[1])*(v2[1]-v1[1]) + (v2[2]-v1[2])*(v2[2]-v1[2]));

}

void MyGLWidget::updateDisplayList(){

	glNewList(displayListIndex, GL_COMPILE);
	//call the opengl commands to draw the mesh
		m->drawMesh(cam->eye, cam->referencePoint, cam->upVector);
	glEndList();
}

void MyGLWidget::disableLighting(){
	lightingEnabled = false;
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
}

void MyGLWidget::enableLighting(){
	lightingEnabled = true;
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_DIFFUSE);
}


//DIFFERNT VIEWS

void MyGLWidget::topView(){

		//store old eye if in perspective view
		if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
		}
		//set eye to be above referencepoint
		cam->eye[0] = 0;
		cam->eye[1] = cam->zoomLevel;
		cam->eye[2] = 0;
		//set the reference point
		vec3 newRef(0,0,0);
		cam->referencePoint = newRef;
		//set the up vector
		vec3 newUp(0,0,-1);
		cam->upVector = newUp;
		//set the side vector
		vec3 newSide(1,0,0);
		cam->sideVector = newSide;
		//disable rotation
		rotationDisabled = true;
		updateGL();
}

void MyGLWidget::rightProfile(){
	//store old eye if in perspective view
	if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
	}
	//set eye to be above referencepoint
	cam->eye[0] = cam->zoomLevel;
	cam->eye[1] = 0;
	cam->eye[2] = 0;
	//set the reference point
	vec3 newRef(0,0,0);
	cam->referencePoint = newRef;
	//set the up vector
	vec3 newUp(0,1,0);
	cam->upVector = newUp;
	//set the side vector
	vec3 newSide(0,0,-1);
	cam->sideVector = newSide;
	//disable rotation
	rotationDisabled = true;

	updateGL();
}

void MyGLWidget::perspective(){
	if (inPerspectiveView){
		return;
	}
	else{
		orthographicView = false;
		inPerspectiveView = true;
		//restore stored vectors/poins
		cam->eye = storedEye;
		cam->referencePoint = storedRef;
		cam->upVector = storedUp;
		cam->sideVector = storedSide;
		//restore rotation
		rotationDisabled = false;

		updateGL();
	}
}

void MyGLWidget::leftProfile(){
	//store old eye if in perspective view
	if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
	}
	//set eye to be above referencepoint
	cam->eye[0] = -(cam->zoomLevel);
	cam->eye[1] = 0;
	cam->eye[2] = 0;
	//set the reference point
	vec3 newRef(0,0,0);
	cam->referencePoint = newRef;
	//set the up vector
	vec3 newUp(0,1,0);
	cam->upVector = newUp;
	//set the side vector
	vec3 newSide(0,0,1);
	cam->sideVector = newSide;
	//disable rotation
	rotationDisabled = true;

	updateGL();
}

void MyGLWidget::frontView(){
	//store old eye if in perspective view
	if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
	}
	//set eye to be above referencepoint
	cam->eye[0] = 0;
	cam->eye[1] = 0;
	cam->eye[2] = cam->zoomLevel;
	//set the reference point
	vec3 newRef(0,0,0);
	cam->referencePoint = newRef;
	//set the up vector
	vec3 newUp(0,1,0);
	cam->upVector = newUp;
	//set the side vector
	vec3 newSide(1,0,0);
	cam->sideVector = newSide;
	//disable rotation
	rotationDisabled = true;

	updateGL();
}
void MyGLWidget::backView(){
	//store old eye if in perspective view
	if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
	}
	//set eye to be above referencepoint
	cam->eye[0] = 0;
	cam->eye[1] = 0;
	cam->eye[2] = -(cam->zoomLevel);
	//set the reference point
	vec3 newRef(0,0,0);
	cam->referencePoint = newRef;
	//set the up vector
	vec3 newUp(0,1,0);
	cam->upVector = newUp;
	//set the side vector
	vec3 newSide(-1,0,0);
	cam->sideVector = newSide;
	//disable rotation
	rotationDisabled = true;

	updateGL();
}
void MyGLWidget::bottomView(){
	//store old eye if in perspective view
	if (inPerspectiveView){
		storedEye = cam->eye;
		storedUp = cam->upVector;
		storedSide = cam->sideVector;
		storedRef = cam->referencePoint;
		//switch to orthographic
		orthographicView = true;
		inPerspectiveView = false;
	}
	//set eye to be above referencepoint
	cam->eye[0] = 0;
	cam->eye[1] = -(cam->zoomLevel);
	cam->eye[2] = 0;
	//set the reference point
	vec3 newRef(0,0,0);
	cam->referencePoint = newRef;
	//set the up vector
	vec3 newUp(0,0,1);
	cam->upVector = newUp;
	//set the side vector
	vec3 newSide(1,0,0);
	cam->sideVector = newSide;
	//disable rotation
	rotationDisabled = true;

	updateGL();
}

//================================//
//==========Public Slots==========//
//================================//

//redraws the mesh
void MyGLWidget::drawMesh(){
	update();
}

//resends the mesh to the 2 tree widgets and redraws the mesh
void MyGLWidget::resendMesh(){
	emit sendMesh(m);
	update();
}

void MyGLWidget::smooth(){
	m->smooth();
	updateDisplayList();
	emit resendMesh();
	updateGL();
}

//stores selected Vertex
void MyGLWidget::recieveSelectedVertex(Vertex * vertex){
	cam->selectedVertex = vertex;
	cam->focusOnVertex = true;
}

//receives mesh from Load Button
void MyGLWidget::receiveMesh(Mesh* mesh){
	std::cout<<"receiveMesh check"<<std::endl;
	m = mesh; 
	m->GLWidget = this;
	initializeGL();
	updateDisplayList();
	update();

}

void MyGLWidget::receiveMeshRequest(){
	std::cout<<"Export mesh request received"<<std::endl;
	emit sendMesh(m);
}
