/********************************************************************************
** Form generated from reading UI file 'opengltest.ui'
**
** Created: Fri Apr 23 22:19:06 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLTEST_H
#define UI_OPENGLTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <controlpointtreewidget.h>
#include <facetreewidget.h>
#include <myexportbutton.h>
#include <vertextreewidget.h>
#include "LightsListWidget.h"
#include "myglwidget.h"
#include "myloadbutton.h"
#include "mymenu.h"

QT_BEGIN_NAMESPACE

class Ui_OpenGLTestClass
{
public:
    QAction *actionLoad_File;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    MyGLWidget *widget;
    QGroupBox *groupBox_4;
    LightsListWidget *listWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_5;
    QLabel *X_label_2;
    QDoubleSpinBox *doubleSpinBox_X_2;
    QLabel *Y_label_2;
    QDoubleSpinBox *doubleSpinBox_Y_2;
    QLabel *Z_label_2;
    QDoubleSpinBox *doubleSpinBox_Z_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSlider *verticalSlider;
    QLabel *label;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QGroupBox *groupBox_7;
    ControlPointTreeWidget *treeWidget_ControlPoints;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox_X_3;
    QDoubleSpinBox *doubleSpinBox_Y_3;
    QDoubleSpinBox *doubleSpinBox_Z_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_6;
    MyLoadButton *LoadButton;
    MyExportButton *ExportButton;
    QGroupBox *groupBox;
    VertexTreeWidget *treeWidget_Vertices;
    FaceTreeWidget *treeWidget_Faces;
    QPushButton *AddVertexToEdge;
    QPushButton *SplitQuadToTriangles;
    QPushButton *AddEdgeToFaces;
    QPushButton *DeleteVertex;
    QGroupBox *groupBox_2;
    QLabel *X_label;
    QDoubleSpinBox *doubleSpinBox_X;
    QLabel *Y_label;
    QDoubleSpinBox *doubleSpinBox_Y;
    QLabel *Z_label;
    QDoubleSpinBox *doubleSpinBox_Z;
    QGroupBox *groupBox_3;
    QLabel *R_label;
    QDoubleSpinBox *doubleSpinBox_R;
    QLabel *G_label;
    QDoubleSpinBox *doubleSpinBox_G;
    QLabel *B_label;
    QDoubleSpinBox *doubleSpinBox_B;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QCheckBox *checkBox;
    QPushButton *Smooth;
    QPushButton *DeleteFace;
    MyMenu *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGLTestClass)
    {
        if (OpenGLTestClass->objectName().isEmpty())
            OpenGLTestClass->setObjectName(QString::fromUtf8("OpenGLTestClass"));
        OpenGLTestClass->resize(1087, 762);
        actionLoad_File = new QAction(OpenGLTestClass);
        actionLoad_File->setObjectName(QString::fromUtf8("actionLoad_File"));
        centralWidget = new QWidget(OpenGLTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 1, 2, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(250, 200));
        listWidget = new LightsListWidget(groupBox_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 101, 131));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 100, 113, 32));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 130, 113, 32));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 160, 241, 61));
        X_label_2 = new QLabel(groupBox_5);
        X_label_2->setObjectName(QString::fromUtf8("X_label_2"));
        X_label_2->setGeometry(QRect(10, 30, 16, 16));
        doubleSpinBox_X_2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_X_2->setObjectName(QString::fromUtf8("doubleSpinBox_X_2"));
        doubleSpinBox_X_2->setGeometry(QRect(30, 30, 51, 22));
        doubleSpinBox_X_2->setMinimum(-10);
        doubleSpinBox_X_2->setMaximum(10);
        doubleSpinBox_X_2->setSingleStep(0.1);
        Y_label_2 = new QLabel(groupBox_5);
        Y_label_2->setObjectName(QString::fromUtf8("Y_label_2"));
        Y_label_2->setGeometry(QRect(90, 30, 16, 16));
        doubleSpinBox_Y_2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Y_2->setObjectName(QString::fromUtf8("doubleSpinBox_Y_2"));
        doubleSpinBox_Y_2->setGeometry(QRect(110, 30, 51, 22));
        doubleSpinBox_Y_2->setMinimum(-10);
        doubleSpinBox_Y_2->setMaximum(10);
        doubleSpinBox_Y_2->setSingleStep(0.1);
        Z_label_2 = new QLabel(groupBox_5);
        Z_label_2->setObjectName(QString::fromUtf8("Z_label_2"));
        Z_label_2->setGeometry(QRect(170, 30, 16, 16));
        doubleSpinBox_Z_2 = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_Z_2->setObjectName(QString::fromUtf8("doubleSpinBox_Z_2"));
        doubleSpinBox_Z_2->setGeometry(QRect(190, 30, 51, 22));
        doubleSpinBox_Z_2->setMinimum(-10);
        doubleSpinBox_Z_2->setMaximum(10);
        doubleSpinBox_Z_2->setSingleStep(0.1);
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 240, 101, 20));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 270, 101, 20));
        radioButton_3 = new QRadioButton(groupBox_4);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 300, 101, 20));
        verticalSlider = new QSlider(groupBox_4);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(100, 250, 22, 71));
        verticalSlider->setMaximum(100);
        verticalSlider->setSingleStep(1);
        verticalSlider->setValue(1);
        verticalSlider->setTracking(true);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(false);
        verticalSlider->setInvertedControls(false);
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 230, 16, 16));
        verticalSlider_2 = new QSlider(groupBox_4);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(120, 250, 22, 71));
        verticalSlider_2->setMaximum(100);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(groupBox_4);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(140, 250, 22, 71));
        verticalSlider_3->setMaximum(100);
        verticalSlider_3->setOrientation(Qt::Vertical);
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 230, 16, 16));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 230, 16, 16));
        line = new QFrame(groupBox_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 320, 241, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 180));
        treeWidget_ControlPoints = new ControlPointTreeWidget(groupBox_7);
        treeWidget_ControlPoints->setObjectName(QString::fromUtf8("treeWidget_ControlPoints"));
        treeWidget_ControlPoints->setGeometry(QRect(10, 20, 161, 111));
        pushButton = new QPushButton(groupBox_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 150, 61, 32));
        doubleSpinBox_X_3 = new QDoubleSpinBox(groupBox_7);
        doubleSpinBox_X_3->setObjectName(QString::fromUtf8("doubleSpinBox_X_3"));
        doubleSpinBox_X_3->setGeometry(QRect(180, 50, 62, 25));
        doubleSpinBox_X_3->setMinimum(-99.99);
        doubleSpinBox_X_3->setSingleStep(0.1);
        doubleSpinBox_Y_3 = new QDoubleSpinBox(groupBox_7);
        doubleSpinBox_Y_3->setObjectName(QString::fromUtf8("doubleSpinBox_Y_3"));
        doubleSpinBox_Y_3->setGeometry(QRect(180, 70, 62, 25));
        doubleSpinBox_Y_3->setMinimum(-99.99);
        doubleSpinBox_Y_3->setSingleStep(0.1);
        doubleSpinBox_Z_3 = new QDoubleSpinBox(groupBox_7);
        doubleSpinBox_Z_3->setObjectName(QString::fromUtf8("doubleSpinBox_Z_3"));
        doubleSpinBox_Z_3->setGeometry(QRect(180, 90, 62, 25));
        doubleSpinBox_Z_3->setMinimum(-99.99);
        doubleSpinBox_Z_3->setSingleStep(0.1);
        spinBox = new QSpinBox(groupBox_7);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 150, 56, 25));
        spinBox->setMinimum(2);
        spinBox->setMaximum(99);
        spinBox->setValue(4);
        spinBox_2 = new QSpinBox(groupBox_7);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(70, 150, 56, 25));
        spinBox_2->setMinimum(2);
        spinBox_2->setValue(4);
        spinBox_3 = new QSpinBox(groupBox_7);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(130, 150, 56, 25));
        spinBox_3->setMinimum(2);
        spinBox_3->setValue(4);
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 30, 81, 16));
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 111, 16));

        gridLayout->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(0, 0));
        groupBox_6->setMaximumSize(QSize(16777215, 50));
        LoadButton = new MyLoadButton(groupBox_6);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setGeometry(QRect(20, 20, 151, 21));
        ExportButton = new MyExportButton(groupBox_6);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(190, 20, 151, 21));

        gridLayout->addWidget(groupBox_6, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        treeWidget_Vertices = new VertexTreeWidget(groupBox);
        treeWidget_Vertices->setObjectName(QString::fromUtf8("treeWidget_Vertices"));
        treeWidget_Vertices->setGeometry(QRect(20, 20, 151, 192));
        treeWidget_Vertices->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeWidget_Faces = new FaceTreeWidget(groupBox);
        treeWidget_Faces->setObjectName(QString::fromUtf8("treeWidget_Faces"));
        treeWidget_Faces->setGeometry(QRect(190, 20, 151, 192));
        treeWidget_Faces->setSelectionMode(QAbstractItemView::ExtendedSelection);
        AddVertexToEdge = new QPushButton(groupBox);
        AddVertexToEdge->setObjectName(QString::fromUtf8("AddVertexToEdge"));
        AddVertexToEdge->setGeometry(QRect(0, 390, 181, 21));
        SplitQuadToTriangles = new QPushButton(groupBox);
        SplitQuadToTriangles->setObjectName(QString::fromUtf8("SplitQuadToTriangles"));
        SplitQuadToTriangles->setGeometry(QRect(180, 390, 181, 21));
        AddEdgeToFaces = new QPushButton(groupBox);
        AddEdgeToFaces->setObjectName(QString::fromUtf8("AddEdgeToFaces"));
        AddEdgeToFaces->setGeometry(QRect(0, 410, 181, 21));
        DeleteVertex = new QPushButton(groupBox);
        DeleteVertex->setObjectName(QString::fromUtf8("DeleteVertex"));
        DeleteVertex->setGeometry(QRect(180, 410, 181, 21));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 331, 61));
        X_label = new QLabel(groupBox_2);
        X_label->setObjectName(QString::fromUtf8("X_label"));
        X_label->setGeometry(QRect(10, 30, 16, 16));
        doubleSpinBox_X = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_X->setObjectName(QString::fromUtf8("doubleSpinBox_X"));
        doubleSpinBox_X->setGeometry(QRect(30, 30, 51, 22));
        doubleSpinBox_X->setMinimum(-99);
        doubleSpinBox_X->setSingleStep(0.1);
        Y_label = new QLabel(groupBox_2);
        Y_label->setObjectName(QString::fromUtf8("Y_label"));
        Y_label->setGeometry(QRect(90, 30, 16, 16));
        doubleSpinBox_Y = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Y->setObjectName(QString::fromUtf8("doubleSpinBox_Y"));
        doubleSpinBox_Y->setGeometry(QRect(110, 30, 51, 22));
        doubleSpinBox_Y->setMinimum(-99);
        doubleSpinBox_Y->setSingleStep(0.1);
        Z_label = new QLabel(groupBox_2);
        Z_label->setObjectName(QString::fromUtf8("Z_label"));
        Z_label->setGeometry(QRect(170, 30, 16, 16));
        doubleSpinBox_Z = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Z->setObjectName(QString::fromUtf8("doubleSpinBox_Z"));
        doubleSpinBox_Z->setGeometry(QRect(190, 30, 51, 22));
        doubleSpinBox_Z->setMinimum(-99);
        doubleSpinBox_Z->setSingleStep(0.1);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 280, 331, 91));
        R_label = new QLabel(groupBox_3);
        R_label->setObjectName(QString::fromUtf8("R_label"));
        R_label->setGeometry(QRect(10, 30, 16, 16));
        doubleSpinBox_R = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_R->setObjectName(QString::fromUtf8("doubleSpinBox_R"));
        doubleSpinBox_R->setGeometry(QRect(30, 30, 51, 22));
        doubleSpinBox_R->setMaximum(1);
        doubleSpinBox_R->setSingleStep(0.05);
        G_label = new QLabel(groupBox_3);
        G_label->setObjectName(QString::fromUtf8("G_label"));
        G_label->setGeometry(QRect(90, 30, 16, 16));
        doubleSpinBox_G = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_G->setObjectName(QString::fromUtf8("doubleSpinBox_G"));
        doubleSpinBox_G->setGeometry(QRect(110, 30, 51, 22));
        doubleSpinBox_G->setMaximum(1);
        doubleSpinBox_G->setSingleStep(0.05);
        B_label = new QLabel(groupBox_3);
        B_label->setObjectName(QString::fromUtf8("B_label"));
        B_label->setGeometry(QRect(170, 30, 16, 16));
        doubleSpinBox_B = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_B->setObjectName(QString::fromUtf8("doubleSpinBox_B"));
        doubleSpinBox_B->setGeometry(QRect(190, 30, 51, 22));
        doubleSpinBox_B->setMaximum(1);
        doubleSpinBox_B->setSingleStep(0.05);
        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(50, 60, 171, 22));
        horizontalSlider->setMaximum(128);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 61, 16));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(230, 60, 87, 20));
        Smooth = new QPushButton(groupBox);
        Smooth->setObjectName(QString::fromUtf8("Smooth"));
        Smooth->setGeometry(QRect(0, 430, 181, 21));
        DeleteFace = new QPushButton(groupBox);
        DeleteFace->setObjectName(QString::fromUtf8("DeleteFace"));
        DeleteFace->setGeometry(QRect(180, 430, 181, 23));

        gridLayout->addWidget(groupBox, 1, 2, 1, 1);

        OpenGLTestClass->setCentralWidget(centralWidget);
        menuBar = new MyMenu(OpenGLTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1087, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        OpenGLTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGLTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        OpenGLTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenGLTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OpenGLTestClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_File);

        retranslateUi(OpenGLTestClass);
        QObject::connect(widget, SIGNAL(sendMesh(Mesh*)), treeWidget_Vertices, SLOT(acceptMesh(Mesh*)));
        QObject::connect(widget, SIGNAL(sendMesh(Mesh*)), treeWidget_Faces, SLOT(acceptMesh(Mesh*)));
        QObject::connect(treeWidget_Faces, SIGNAL(redraw()), widget, SLOT(drawMesh()));
        QObject::connect(doubleSpinBox_R, SIGNAL(valueChanged(double)), treeWidget_Faces, SLOT(setR(double)));
        QObject::connect(doubleSpinBox_G, SIGNAL(valueChanged(double)), treeWidget_Faces, SLOT(setG(double)));
        QObject::connect(doubleSpinBox_B, SIGNAL(valueChanged(double)), treeWidget_Faces, SLOT(setB(double)));
        QObject::connect(treeWidget_Vertices, SIGNAL(redraw()), widget, SLOT(drawMesh()));
        QObject::connect(doubleSpinBox_X, SIGNAL(valueChanged(double)), treeWidget_Vertices, SLOT(setX(double)));
        QObject::connect(doubleSpinBox_Y, SIGNAL(valueChanged(double)), treeWidget_Vertices, SLOT(setY(double)));
        QObject::connect(doubleSpinBox_Z, SIGNAL(valueChanged(double)), treeWidget_Vertices, SLOT(setZ(double)));
        QObject::connect(treeWidget_Vertices, SIGNAL(updateMesh()), widget, SLOT(resendMesh()));
        QObject::connect(DeleteVertex, SIGNAL(clicked()), treeWidget_Vertices, SLOT(deleteVertex()));
        QObject::connect(AddVertexToEdge, SIGNAL(clicked()), treeWidget_Vertices, SLOT(addVertexToEdge()));
        QObject::connect(treeWidget_Faces, SIGNAL(updateMesh()), widget, SLOT(resendMesh()));
        QObject::connect(SplitQuadToTriangles, SIGNAL(clicked()), treeWidget_Faces, SLOT(SplitQuadToTriangles()));
        QObject::connect(AddEdgeToFaces, SIGNAL(clicked()), treeWidget_Vertices, SLOT(addEdgeBetweenFaces()));
        QObject::connect(treeWidget_Vertices, SIGNAL(addEdgeBetweenFaces(Vertex*)), treeWidget_Faces, SLOT(addEdgeBetweenFaces(Vertex*)));
        QObject::connect(treeWidget_Vertices, SIGNAL(clicked(QModelIndex)), treeWidget_Vertices, SLOT(activated()));
        QObject::connect(treeWidget_Vertices, SIGNAL(sendX(double)), doubleSpinBox_X, SLOT(setValue(double)));
        QObject::connect(treeWidget_Vertices, SIGNAL(sendY(double)), doubleSpinBox_Y, SLOT(setValue(double)));
        QObject::connect(treeWidget_Vertices, SIGNAL(sendZ(double)), doubleSpinBox_Z, SLOT(setValue(double)));
        QObject::connect(treeWidget_Faces, SIGNAL(clicked(QModelIndex)), treeWidget_Faces, SLOT(activated()));
        QObject::connect(treeWidget_Faces, SIGNAL(sendR(double)), doubleSpinBox_R, SLOT(setValue(double)));
        QObject::connect(treeWidget_Faces, SIGNAL(sendG(double)), doubleSpinBox_G, SLOT(setValue(double)));
        QObject::connect(treeWidget_Faces, SIGNAL(sendB(double)), doubleSpinBox_B, SLOT(setValue(double)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableXYZ(bool)), doubleSpinBox_X, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableXYZ(bool)), doubleSpinBox_Y, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableXYZ(bool)), doubleSpinBox_Z, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableRGB(bool)), doubleSpinBox_R, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableRGB(bool)), doubleSpinBox_G, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(enableRGB(bool)), doubleSpinBox_B, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableXYZ(bool)), doubleSpinBox_X, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableXYZ(bool)), doubleSpinBox_Y, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableXYZ(bool)), doubleSpinBox_Z, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableRGB(bool)), doubleSpinBox_R, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableRGB(bool)), doubleSpinBox_G, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_Vertices, SIGNAL(enableRGB(bool)), doubleSpinBox_B, SLOT(setEnabled(bool)));
        QObject::connect(widget, SIGNAL(sendFace(Face*)), treeWidget_Faces, SLOT(acceptFace(Face*)));
        QObject::connect(Smooth, SIGNAL(clicked()), widget, SLOT(smooth()));
        QObject::connect(treeWidget_Vertices, SIGNAL(sendVertex(Vertex*)), widget, SLOT(recieveSelectedVertex(Vertex*)));
        QObject::connect(LoadButton, SIGNAL(clicked()), LoadButton, SLOT(loadFile()));
        QObject::connect(LoadButton, SIGNAL(sendMesh(Mesh*)), widget, SLOT(receiveMesh(Mesh*)));
        QObject::connect(widget, SIGNAL(sendLights(Light*)), listWidget, SLOT(acceptLights(Light*)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), listWidget, SLOT(enable()));
        QObject::connect(ExportButton, SIGNAL(clicked()), ExportButton, SLOT(exportFile()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), listWidget, SLOT(disable()));
        QObject::connect(listWidget, SIGNAL(redraw()), widget, SLOT(drawMesh()));
        QObject::connect(radioButton, SIGNAL(clicked()), listWidget, SLOT(setToAmbient()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), listWidget, SLOT(setToDiffuse()));
        QObject::connect(radioButton_3, SIGNAL(clicked()), listWidget, SLOT(setToSpecular()));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), listWidget, SLOT(setR(int)));
        QObject::connect(verticalSlider_2, SIGNAL(valueChanged(int)), listWidget, SLOT(setG(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), listWidget, SLOT(setB(int)));
        QObject::connect(doubleSpinBox_X_2, SIGNAL(valueChanged(double)), listWidget, SLOT(setX(double)));
        QObject::connect(doubleSpinBox_Y_2, SIGNAL(valueChanged(double)), listWidget, SLOT(setY(double)));
        QObject::connect(doubleSpinBox_Z_2, SIGNAL(valueChanged(double)), listWidget, SLOT(setZ(double)));
        QObject::connect(listWidget, SIGNAL(itemSelectionChanged()), listWidget, SLOT(activated()));
        QObject::connect(listWidget, SIGNAL(sendX(double)), doubleSpinBox_X_2, SLOT(setValue(double)));
        QObject::connect(listWidget, SIGNAL(sendY(double)), doubleSpinBox_Y_2, SLOT(setValue(double)));
        QObject::connect(listWidget, SIGNAL(sendZ(double)), doubleSpinBox_Z_2, SLOT(setValue(double)));
        QObject::connect(listWidget, SIGNAL(sendR(int)), verticalSlider, SLOT(setValue(int)));
        QObject::connect(listWidget, SIGNAL(sendG(int)), verticalSlider_2, SLOT(setValue(int)));
        QObject::connect(listWidget, SIGNAL(sendB(int)), verticalSlider_3, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(sendMesh(Mesh*)), treeWidget_ControlPoints, SLOT(acceptMesh(Mesh*)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(sendVertex(Vertex*)), widget, SLOT(recieveSelectedVertex(Vertex*)));
        QObject::connect(pushButton, SIGNAL(clicked()), treeWidget_ControlPoints, SLOT(FFD()));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(updateMesh()), widget, SLOT(resendMesh()));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(clicked(QModelIndex)), treeWidget_ControlPoints, SLOT(activated()));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(sendX(double)), doubleSpinBox_X_3, SLOT(setValue(double)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(sendY(double)), doubleSpinBox_Y_3, SLOT(setValue(double)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(sendZ(double)), doubleSpinBox_Z_3, SLOT(setValue(double)));
        QObject::connect(doubleSpinBox_X_3, SIGNAL(valueChanged(double)), treeWidget_ControlPoints, SLOT(setX(double)));
        QObject::connect(doubleSpinBox_Z_3, SIGNAL(valueChanged(double)), treeWidget_ControlPoints, SLOT(setZ(double)));
        QObject::connect(doubleSpinBox_Y_3, SIGNAL(valueChanged(double)), treeWidget_ControlPoints, SLOT(setY(double)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(enableXYZ(bool)), doubleSpinBox_X_3, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(enableXYZ(bool)), doubleSpinBox_Y_3, SLOT(setEnabled(bool)));
        QObject::connect(treeWidget_ControlPoints, SIGNAL(enableXYZ(bool)), doubleSpinBox_Z_3, SLOT(setEnabled(bool)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(updateGL()));
        QObject::connect(treeWidget_Faces, SIGNAL(sendShine(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), treeWidget_Faces, SLOT(setShine(int)));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), treeWidget_Faces, SLOT(enableShine(bool)));
        QObject::connect(treeWidget_Faces, SIGNAL(sendShineBool(bool)), checkBox, SLOT(setChecked(bool)));
        QObject::connect(spinBox, SIGNAL(valueChanged(QString)), treeWidget_ControlPoints, SLOT(currS(QString)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(QString)), treeWidget_ControlPoints, SLOT(currT(QString)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(QString)), treeWidget_ControlPoints, SLOT(currU(QString)));
        QObject::connect(ExportButton, SIGNAL(requestMesh()), widget, SLOT(receiveMeshRequest()));
        QObject::connect(widget, SIGNAL(sendMesh(Mesh*)), ExportButton, SLOT(acceptMesh(Mesh*)));
        QObject::connect(ExportButton, SIGNAL(requestMtl()), LoadButton, SLOT(acceptMtlRequest()));
        QObject::connect(LoadButton, SIGNAL(sendMtl(string)), ExportButton, SLOT(acceptMtl(string)));
        QObject::connect(DeleteFace, SIGNAL(clicked()), treeWidget_Faces, SLOT(deleteFace()));

        QMetaObject::connectSlotsByName(OpenGLTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLTestClass)
    {
        OpenGLTestClass->setWindowTitle(QApplication::translate("OpenGLTestClass", "OpenGLTest", 0, QApplication::UnicodeUTF8));
        actionLoad_File->setText(QApplication::translate("OpenGLTestClass", "Load File", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("OpenGLTestClass", "Lighting", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("OpenGLTestClass", "Enable", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("OpenGLTestClass", "Disable", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("OpenGLTestClass", "Position", 0, QApplication::UnicodeUTF8));
        X_label_2->setText(QApplication::translate("OpenGLTestClass", "X:", 0, QApplication::UnicodeUTF8));
        Y_label_2->setText(QApplication::translate("OpenGLTestClass", "Y:", 0, QApplication::UnicodeUTF8));
        Z_label_2->setText(QApplication::translate("OpenGLTestClass", "Z:", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("OpenGLTestClass", "Ambient", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("OpenGLTestClass", "Diffuse", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("OpenGLTestClass", "Specular", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenGLTestClass", "R", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OpenGLTestClass", "G", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OpenGLTestClass", "B", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("OpenGLTestClass", "Free Form Deformation", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_ControlPoints->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("OpenGLTestClass", "Control Points", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("OpenGLTestClass", "FFD", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OpenGLTestClass", "Coordinates", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OpenGLTestClass", "No. Control Axes", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("OpenGLTestClass", "Polygon Mesh Load and Write", 0, QApplication::UnicodeUTF8));
        LoadButton->setText(QApplication::translate("OpenGLTestClass", "Load Mesh", 0, QApplication::UnicodeUTF8));
        ExportButton->setText(QApplication::translate("OpenGLTestClass", "Export Mesh", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OpenGLTestClass", "Editor", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_Vertices->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("OpenGLTestClass", "Vertices", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_Faces->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("OpenGLTestClass", "Faces", 0, QApplication::UnicodeUTF8));
        AddVertexToEdge->setText(QApplication::translate("OpenGLTestClass", "Add Vertex to Edge", 0, QApplication::UnicodeUTF8));
        SplitQuadToTriangles->setText(QApplication::translate("OpenGLTestClass", "Split Quad into Triangles", 0, QApplication::UnicodeUTF8));
        AddEdgeToFaces->setText(QApplication::translate("OpenGLTestClass", "Add Edge Between Faces", 0, QApplication::UnicodeUTF8));
        DeleteVertex->setText(QApplication::translate("OpenGLTestClass", "Delete Vertex", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("OpenGLTestClass", "Vertex Attributes", 0, QApplication::UnicodeUTF8));
        X_label->setText(QApplication::translate("OpenGLTestClass", "X:", 0, QApplication::UnicodeUTF8));
        Y_label->setText(QApplication::translate("OpenGLTestClass", "Y:", 0, QApplication::UnicodeUTF8));
        Z_label->setText(QApplication::translate("OpenGLTestClass", "Z:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("OpenGLTestClass", "Face Attributes", 0, QApplication::UnicodeUTF8));
        R_label->setText(QApplication::translate("OpenGLTestClass", "R:", 0, QApplication::UnicodeUTF8));
        G_label->setText(QApplication::translate("OpenGLTestClass", "G:", 0, QApplication::UnicodeUTF8));
        B_label->setText(QApplication::translate("OpenGLTestClass", "B:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OpenGLTestClass", "Shine:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("OpenGLTestClass", "Shine On", 0, QApplication::UnicodeUTF8));
        Smooth->setText(QApplication::translate("OpenGLTestClass", "Smooth", 0, QApplication::UnicodeUTF8));
        DeleteFace->setText(QApplication::translate("OpenGLTestClass", "Delete Face", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("OpenGLTestClass", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenGLTestClass: public Ui_OpenGLTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLTEST_H
