#include "stdafx.h"
#include "SymmetricDDA.h"
#include "OpenGLWindow.h"

using namespace symmetricDDAandSutherlandCohen;

SymmetricDDA::SymmetricDDA()
{

}

SymmetricDDA::~SymmetricDDA()
{

}

QVector<QVector2D>& SymmetricDDA::getPixelVertices()
{
    return mPixelVertices;
}

//Code to draw a grid
void SymmetricDDA::drawGrid(QVector<GLfloat>& vertices, QVector<GLfloat>& colors)
{
    const float gridSize = 50.0f;
    const float step = 1.0f;

    // Code to draw horizontal lines
    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        vertices << -gridSize / 2.0f << y;
        vertices << gridSize / 2.0f << y;

        colors << 1.0f << 1.0f << 1.0f;
        colors << 1.0f << 1.0f << 1.0f;
    }

    // Code to draw Vertical lines
    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        vertices << x << -gridSize / 2.0f;
        vertices << x << gridSize / 2.0f;

        colors << 1.0f << 1.0f << 1.0f;
        colors << 1.0f << 1.0f << 1.0f;
    }
}

//Symmetric DDA implimentation
void SymmetricDDA::drawLineBySymmetricDDA(Line& line,QVector<GLfloat>& mVertices, QVector<QVector2D>& pixelVertices)
{
    float dx = abs(line.end().x() - line.start().x());
    float dy = abs(line.end().y() - line.start().y());
    float deltaX;
    float deltaY;
    if (dy > dx)
    {
        deltaX = dx / dy;
        deltaY = dy / dy;
    }
    else
    {
        deltaX = dx / dx;
        deltaY = dy / dx;
    }
    while (line.start().x() < line.end().x())
    {
        pixelVertices.append(QVector2D(round(line.start().x()), round(line.start().y())));
        pixelVertices.append(QVector2D(round(line.start().x()) + 1, round(line.start().y())));
        pixelVertices.append(QVector2D(round(line.start().x()) + 1, round(line.start().y()) + 1));
        pixelVertices.append(QVector2D(round(line.start().x()), round(line.start().y()) + 1));
        line.start().setX(deltaX + line.start().x());
        line.start().setY(deltaY + line.start().y());
    }

    int i = 0;
    while (i < pixelVertices.size())
    {
        QVector<QVector2D> qv;
        qv.append(pixelVertices[i]);
        i++;
        qv.append(pixelVertices[i]);
        i++;
        qv.append(pixelVertices[i]);
        i++;
        qv.append(pixelVertices[i]);
        i++;
        QVector3D fillColor(1.0f, 0.0f, 0.0f);
        openglWindow->fillSquare(qv, fillColor);
    }
}



