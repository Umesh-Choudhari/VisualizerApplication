#include "stdafx.h"
#include "Polygoan.h"

Polygoan::Polygoan(QVector<Line> vectorOfLines)
{
	mVectorOfLines = vectorOfLines;
}

Polygoan::~Polygoan()
{

}

QVector<Line>& Polygoan::getVectorOfLines()
{
	return mVectorOfLines;
}