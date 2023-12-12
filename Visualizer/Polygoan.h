#pragma once
#include "Line.h"
class Polygoan : public Line
{
public:
	Polygoan(QVector<Line> vectorOfLines);
	~Polygoan();
	QVector<Line>& getVectorOfLines();

private:
	QVector<Line> mVectorOfLines;
};

