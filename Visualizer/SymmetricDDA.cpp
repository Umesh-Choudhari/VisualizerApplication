#include "stdafx.h"
#include "SymmetricDDA.h"
#include "OpenGLWindow.h"

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
    const float gridSize = 8.0f;
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
void SymmetricDDA::drawLineBySymmetricDDA(Line& line, QVector<QVector2D>& pixelVertices)
{
    float dx = abs(line.getPoint2().x() - line.getPoint1().x());
    float dy = abs(line.getPoint2().y() - line.getPoint1().y());
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
    while (line.getPoint1().x() < line.getPoint2().x())
    {
        pixelVertices.append(QVector2D(round(line.getPoint1().x()), round(line.getPoint1().y())));
        pixelVertices.append(QVector2D(round(line.getPoint1().x()) + 1, round(line.getPoint1().y())));
        pixelVertices.append(QVector2D(round(line.getPoint1().x()) + 1, round(line.getPoint1().y()) + 1));
        pixelVertices.append(QVector2D(round(line.getPoint1().x()), round(line.getPoint1().y()) + 1));
        line.getPoint1().setX(deltaX + line.getPoint1().x());
        line.getPoint1().setY(deltaY + line.getPoint1().y());
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


