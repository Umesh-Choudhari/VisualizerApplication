#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizer.h"
#include "SymmetricDDA.h"

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();

public:
    QVector<QVector2D> mPixelVertices;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

private:
    QMenuBar*       mMenuBar;
    QToolBar*       mMainToolBar;
    QWidget*        mCentralWidget;
    QStatusBar*     mStatusBar;
    OpenGLWindow*   mRenderer;
    QPushButton*    mPushButton;
    QPushButton*    mPushButton2;

    QLineEdit* mLineEdit;
    QLineEdit* mLineEdit2;
    QLineEdit* mLineEdit3;
    QLineEdit* mLineEdit4;
    QLineEdit* mLineEdit5;
    QLineEdit* mLineEdit6;
    QLineEdit* mLineEdit7;
    QLineEdit* mLineEdit8;
    QLineEdit* mLineEdit9;
    QLineEdit* mLineEdit10;
    QLineEdit* mLineEdit11;
    QLineEdit* mLineEdit12;

    QLabel* mLabel;
    QLabel* mLabel2;
    QLabel* mLabel3;
    QLabel* mLabel4;
    QLabel* mLabel5;
    QLabel* mLabel6;
    QLabel* mLabel7;
    QLabel* mLabel8;
    QLabel* mLabel9;
    QLabel* mLabel10;
    QLabel* mLabel11;
    QLabel* mLabel12;
    QLabel* mLabel13;
    QLabel* mLabel14;

    float xCoordinate;
    float yCoordinate;
    float x1Coordinate;
    float y1Coordinate;
    float xMin;
    float yMin;
    float xMax;
    float yMax;

    SymmetricDDA symmetricDDAObj;

public slots:
    void clipLine();
    void drawLine();
};