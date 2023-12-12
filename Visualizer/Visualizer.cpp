#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Line.h"
#include "SymmetricDDA.h"
#include "SutherlandandCohenAlgorithm.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mPushButton, &QPushButton::clicked, this, &Visualizer::clipLine);
    connect(mPushButton2, &QPushButton::clicked, this, &Visualizer::drawLine);
}

Visualizer::~Visualizer()
{

}

//Slot for Implimentation of Symmetric DDA
void Visualizer::drawLine()
{
    xCoordinate = mLineEdit9->text().toFloat();
    yCoordinate = mLineEdit10->text().toFloat();

    x1Coordinate = mLineEdit11->text().toFloat();
    y1Coordinate = mLineEdit12->text().toFloat();

    Point pt1(xCoordinate, yCoordinate);
    Point pt2(x1Coordinate, y1Coordinate);

    Line line(pt1, pt2);

    mVertices << pt1.x() << pt1.y();
    mVertices << pt2.x() << pt2.y();

    mColors << 0.0f << 1.0f << 0.0f;
    mColors << 0.0f << 1.0f << 0.0f;
 
    symmetricDDAObj.drawGrid(mVertices, mColors);
    symmetricDDAObj.drawLineBySymmetricDDA(line, mPixelVertices);
   

    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
    mRenderer->updateData(mVertices, mColors);

}


//Slot for Implimentation of sutherland cohen line clipping
void Visualizer::clipLine()
{
    xCoordinate = mLineEdit->text().toFloat();
    yCoordinate = mLineEdit2->text().toFloat();

    x1Coordinate = mLineEdit7->text().toFloat();
    y1Coordinate = mLineEdit8->text().toFloat();


    xMin = mLineEdit3->text().toFloat();
    yMin = mLineEdit4->text().toFloat();

    xMax = mLineEdit5->text().toFloat();
    yMax = mLineEdit6->text().toFloat();

    Point pt1(xCoordinate, yCoordinate);
    Point pt2(x1Coordinate, x1Coordinate);

    Point pt3(xMin, yMin);
    Point pt4(xMax, yMax);

    Line line(pt1, pt2);
    Line diagonalLine(pt3, pt4);

    SutherlandandCohenAlgorithm sutherlandCohen(line, diagonalLine);

    mRenderer->setVectorOfLines(sutherlandCohen.verticesOfOrignalLine);
    mRenderer->setColorOfLines(sutherlandCohen.colorOfOrignalLine);

    // Update data and trigger repaint
    mRenderer->updateData(sutherlandCohen.verticesOfOrignalLine, sutherlandCohen.colorOfOrignalLine);
}

//Implimentation of UI
void Visualizer::setupUi() {

    mCentralWidget = new QWidget(this);
    mCentralWidget->setObjectName("centralwidget");

    mLabel = new QLabel(this);
    mLabel->setObjectName("label");
    mLabel->setText("X coordinate");
    mLabel->setGeometry(QRect(0,0,85,20));

    mLineEdit = new QLineEdit(this);
    mLineEdit->setObjectName("lineEdit");
    mLineEdit->setGeometry(QRect(0, 25, 85, 20));

    mLabel2 = new QLabel(this);
    mLabel2->setObjectName("label_2");
    mLabel2->setText("Y coordinate");
    mLabel2->setGeometry(QRect(90,0,85,20));

    mLineEdit2 = new QLineEdit(this);
    mLineEdit2->setObjectName("lineEdit_2");
    mLineEdit2->setGeometry(QRect(90,25, 85, 20));

    mLabel3 = new QLabel(this);
    mLabel3->setObjectName("label");
    mLabel3->setText("          xMin");
    mLabel3->setGeometry(QRect(180, 0, 85, 20));

    mLineEdit3 = new QLineEdit(this);
    mLineEdit3->setObjectName("lineEdit_3");
    mLineEdit3->setGeometry(QRect(180, 25, 85, 20));

    mLabel4 = new QLabel(this);
    mLabel4->setObjectName("label");
    mLabel4->setText("      yMin");
    mLabel4->setGeometry(QRect(270, 0, 85, 20));

    mLineEdit4 = new QLineEdit(this);
    mLineEdit4->setObjectName("lineEdit_4");
    mLineEdit4->setGeometry(QRect(270, 25, 85, 20));

    mLabel5 = new QLabel(this);
    mLabel5->setObjectName("label");
    mLabel5->setText("          xMax");
    mLabel5->setGeometry(QRect(360, 0, 85, 20));

    mLineEdit5 = new QLineEdit(this);
    mLineEdit5->setObjectName("lineEdit_5");
    mLineEdit5->setGeometry(QRect(360, 25, 85, 20));

    mLabel6 = new QLabel(this);
    mLabel6->setObjectName("label");
    mLabel6->setText("      yMax");
    mLabel6->setGeometry(QRect(450, 0, 85, 20));

    mLineEdit6 = new QLineEdit(this);
    mLineEdit6->setObjectName("lineEdit_6");
    mLineEdit6->setGeometry(QRect(450, 25, 85, 20));

    mPushButton = new QPushButton(this);
    mPushButton->setObjectName("pushButton");
    mPushButton->setText("Clip Line");
    mPushButton->setGeometry(QRect(550, 0, 85, 50));

    mLabel7 = new QLabel(this);
    mLabel7->setObjectName("label");
    mLabel7->setText("X1 Coordinate");
    mLabel7->setGeometry(QRect(0, 55, 85, 20));

    mLineEdit7 = new QLineEdit(this);
    mLineEdit7->setObjectName("lineEdit_7");
    mLineEdit7->setGeometry(QRect(0, 80, 85, 20));

    mLabel8 = new QLabel(this);
    mLabel8->setObjectName("label");
    mLabel8->setText("Y1 Coordinate");
    mLabel8->setGeometry(QRect(90, 55, 85, 20));

    mLineEdit8 = new QLineEdit(this);
    mLineEdit8->setObjectName("lineEdit_6");
    mLineEdit8->setGeometry(QRect(90, 80, 85, 20));

    mLabel9 = new QLabel(this);
    mLabel9->setObjectName("label");
    mLabel9->setText("X Coordinate");
    mLabel9->setGeometry(QRect(740, 0, 85, 20));

    mLineEdit9 = new QLineEdit(this);
    mLineEdit9->setObjectName("lineEdit_6");
    mLineEdit9->setGeometry(QRect(740, 25, 85, 20));

    mLabel10 = new QLabel(this);
    mLabel10->setObjectName("label");
    mLabel10->setText("Y Coordinate");
    mLabel10->setGeometry(QRect(830, 0, 85, 20));

    mLineEdit10 = new QLineEdit(this);
    mLineEdit10->setObjectName("lineEdit_6");
    mLineEdit10->setGeometry(QRect(830, 25, 85, 20));

    mLabel11 = new QLabel(this);
    mLabel11->setObjectName("label");
    mLabel11->setText("X1 Coordinate");
    mLabel11->setGeometry(QRect(920, 0, 85, 20));

    mLineEdit11 = new QLineEdit(this);
    mLineEdit11->setObjectName("lineEdit_6");
    mLineEdit11->setGeometry(QRect(920, 25, 85, 20));

    mLabel12 = new QLabel(this);
    mLabel12->setObjectName("label");
    mLabel12->setText("Y1 Coordinate");
    mLabel12->setGeometry(QRect(1010, 0, 85, 20));

    mLineEdit12 = new QLineEdit(this);
    mLineEdit12->setObjectName("lineEdit_6");
    mLineEdit12->setGeometry(QRect(1010, 25, 85, 20));

    mLabel13 = new QLabel(this);
    mLabel13->setObjectName("label");
    mLabel13->setText("Line cliping by Sutherland Cohen algorithm");
    mLabel13->setGeometry(QRect(140, 110, 285, 20));

    mLabel14 = new QLabel(this);
    mLabel14->setObjectName("label");
    mLabel14->setText("Line drawing by Symmetric DDA");
    mLabel14->setGeometry(QRect(870, 110, 285, 20));

    mPushButton2 = new QPushButton(this);
    mPushButton2->setObjectName("pushButton");
    mPushButton2->setText("Draw Line");
    mPushButton2->setGeometry(QRect(1110, 0, 85, 50));

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(90, 140, 1000, 600));

    setWindowTitle(QCoreApplication::translate("Suthland Cohen and Symmetric DDA", "Suthland Cohen and Symmetric DDA", nullptr));

}