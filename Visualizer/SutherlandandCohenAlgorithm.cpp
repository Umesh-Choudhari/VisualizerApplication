#include "stdafx.h"
#include "SutherlandandCohenAlgorithm.h"

SutherlandandCohenAlgorithm::SutherlandandCohenAlgorithm(Line& line, Line& diagonalLine)
{
    lineDrawingBySutherlandCohen(line, diagonalLine);
}

SutherlandandCohenAlgorithm::~SutherlandandCohenAlgorithm()
{

}

//Compute Binary Code
int SutherlandandCohenAlgorithm::computeBinaryCode(double x, double y,Line& diagonalLine)
{
    int code = INSIDE;
    if (x < diagonalLine.getPoint1().x())
    {
        code |= LEFT;
    }
    else if (x > diagonalLine.getPoint2().x())
    {
        code |= RIGHT;
    }

    if (y < diagonalLine.getPoint1().y())
    {
        code |= BOTTOM;
    }
    else if (y >  diagonalLine.getPoint2().y())
    {
        code |= TOP;
    }
    return code;
}

//Sutherland cohen line cliping implimentation
void SutherlandandCohenAlgorithm::lineDrawingBySutherlandCohen(Line& line, Line& diagonalLine)
{

    verticesOfOrignalLine << diagonalLine.getPoint1().x() << diagonalLine.getPoint1().y();
    verticesOfOrignalLine << diagonalLine.getPoint2().x() << diagonalLine.getPoint1().y();

    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;
    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;

    verticesOfOrignalLine << diagonalLine.getPoint2().x() << diagonalLine.getPoint1().y();
    verticesOfOrignalLine << diagonalLine.getPoint2().x() <<  diagonalLine.getPoint2().y();

    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;
    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;

    verticesOfOrignalLine << diagonalLine.getPoint2().x() <<  diagonalLine.getPoint2().y();
    verticesOfOrignalLine << diagonalLine.getPoint1().x() <<  diagonalLine.getPoint2().y();

    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;
    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;

    verticesOfOrignalLine << diagonalLine.getPoint1().x() <<  diagonalLine.getPoint2().y();
    verticesOfOrignalLine << diagonalLine.getPoint1().x() << diagonalLine.getPoint1().y();

    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;
    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;

    verticesOfOrignalLine << line.getPoint1().x() << line.getPoint1().y();
    verticesOfOrignalLine << line.getPoint2().x() << line.getPoint2().y();

    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;
    colorOfOrignalLine << 1.0f << 1.0f << 0.0f;

    int code1 = computeBinaryCode(line.getPoint1().x(), line.getPoint1().y(), diagonalLine);
    int code2 = computeBinaryCode(line.getPoint2().x(), line.getPoint2().y(), diagonalLine);

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
                x = line.getPoint1().x() + (line.getPoint2().x() - line.getPoint1().x()) * ( diagonalLine.getPoint2().y() - line.getPoint1().y()) / (line.getPoint2().y() - line.getPoint1().y());
                y =  diagonalLine.getPoint2().y();
            }
            else if (code_out & BOTTOM)
            {
                x = line.getPoint1().x() + (line.getPoint2().x() - line.getPoint1().x()) * (diagonalLine.getPoint1().y() - line.getPoint1().y()) / (line.getPoint2().y() - line.getPoint1().y());
                y = diagonalLine.getPoint1().y();
            }
            else if (code_out & RIGHT)
            {
                y = line.getPoint1().y() + (line.getPoint2().y() - line.getPoint1().y()) * (diagonalLine.getPoint2().x() - line.getPoint1().x()) / (line.getPoint2().x() - line.getPoint1().x());
                x = diagonalLine.getPoint2().x();
            }
            else if (code_out & LEFT)
            {
                y = line.getPoint1().y() + (line.getPoint2().y() - line.getPoint1().y()) * (diagonalLine.getPoint1().x() - line.getPoint1().x()) / (line.getPoint2().x() - line.getPoint1().x());
                x = diagonalLine.getPoint1().x();
            }
            if (code_out == code1)
            {
                line.getPoint1().setX(x) ;
                line.getPoint1().setY(y) ;
                code1 = computeBinaryCode(line.getPoint1().x(), line.getPoint1().y(),diagonalLine);
            }
            else {
                line.getPoint2().setX(x);
                line.getPoint2().setY(y) ;
                float temp = line.getPoint2().x();
                float temp1 = line.getPoint2().y();
                code2 = computeBinaryCode(line.getPoint2().x(), line.getPoint2().y(),diagonalLine);
            }
        }
       
    } 
    if (accept)
    {
        verticesOfOrignalLine << line.getPoint1().x() << line.getPoint1().y();
        verticesOfOrignalLine << line.getPoint2().x() << line.getPoint2().y();

        colorOfOrignalLine << 150.0f << 0.0f << 0.0f;
        colorOfOrignalLine << 150.0f << 0.0f << 0.0f;
    }
    

}


