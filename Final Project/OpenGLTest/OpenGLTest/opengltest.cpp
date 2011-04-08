/* the main window.  not much to do here.  */

#include "opengltest.h"
#include "MyGLWidget.h"

OpenGLTest::OpenGLTest(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);	
}

OpenGLTest::~OpenGLTest()
{

}
