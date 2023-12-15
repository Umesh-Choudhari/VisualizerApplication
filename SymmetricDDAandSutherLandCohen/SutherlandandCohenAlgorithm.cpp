#include "stdafx.h"
#include "SutherlandandCohenAlgorithm.h"

using namespace symmetricDDAandSutherlandCohen;

SutherlandandCohenAlgorithm::SutherlandandCohenAlgorithm(Line& line, Line& diagonalLine, QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{
    lineDrawingBySutherlandCohen(line, diagonalLine, mVertices, mColors);
}

SutherlandandCohenAlgorithm::~SutherlandandCohenAlgorithm()
{

}

//Compute Binary Code
int SutherlandandCohenAlgorithm::computeBinaryCode(double x, double y, Line& diagonalLine)
{
    int code = INSIDE;
    if (x < diagonalLine.start().x())
    {
        code |= LEFT;
    }
    else if (x > diagonalLine.end().x())
    {
        code |= RIGHT;
    }

    if (y < diagonalLine.start().y())
    {
        code |= BOTTOM;
    }
    else if (y > diagonalLine.end().y())
    {
        code |= TOP;
    }
    return code;
}

//Sutherland cohen line cliping implimentation
void SutherlandandCohenAlgorithm::lineDrawingBySutherlandCohen(Line& line, Line& diagonalLine, QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{

    mVertices << line.start().x() << line.start().y();
    mVertices << line.end().x() << line.end().y();

    mColors << 1.0f << 1.0f << 0.0f;
    mColors << 1.0f << 1.0f << 0.0f;

    int code1 = computeBinaryCode(line.start().x(), line.start().y(), diagonalLine);
    int code2 = computeBinaryCode(line.end().x(), line.end().y(), diagonalLine);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = line.start().x() + (line.end().x() - line.start().x()) * (diagonalLine.end().y() - line.start().y()) / (line.end().y() - line.start().y());
                y = diagonalLine.end().y();
            }
            else if (code_out & BOTTOM)
            {
                x = line.start().x() + (line.end().x() - line.start().x()) * (diagonalLine.start().y() - line.start().y()) / (line.end().y() - line.start().y());
                y = diagonalLine.start().y();
            }
            else if (code_out & RIGHT)
            {
                y = line.start().y() + (line.end().y() - line.start().y()) * (diagonalLine.end().x() - line.start().x()) / (line.end().x() - line.start().x());
                x = diagonalLine.end().x();
            }
            else if (code_out & LEFT)
            {
                y = line.start().y() + (line.end().y() - line.start().y()) * (diagonalLine.start().x() - line.start().x()) / (line.end().x() - line.start().x());
                x = diagonalLine.start().x();
            }
            if (code_out == code1)
            {
                line.start().setX(x);
                line.start().setY(y);
                code1 = computeBinaryCode(line.start().x(), line.start().y(), diagonalLine);
            }
            else {
                line.end().setX(x);
                line.end().setY(y);
                code2 = computeBinaryCode(line.end().x(), line.end().y(), diagonalLine);
            }
        }

    }
    if (accept)
    {
        mVertices << line.start().x() << line.start().y();
        mVertices << line.end().x() << line.end().y();

        mColors << 150.0f << 0.0f << 0.0f;
        mColors << 150.0f << 0.0f << 0.0f;
    }

}


