/* the main window.  */

#ifndef OPENGLTEST_H
#define OPENGLTEST_H

#include <QtGui/QMainWindow>
#include "ui_opengltest.h"

class OpenGLTest : public QMainWindow
{
	Q_OBJECT

public:
	OpenGLTest(QWidget *parent = 0, Qt::WFlags flags = 0);
	~OpenGLTest();

private:
	Ui::OpenGLTestClass ui;
};

#endif // OPENGLTEST_H
