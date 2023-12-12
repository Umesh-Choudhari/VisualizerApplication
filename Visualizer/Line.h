#pragma once
#include "Point.h"
class Line : public Point
{
public:
	Line();
	Line(Point pt1, Point pt2);
	~Line();
	Point& getPoint1();
	Point& getPoint2();

private:
	Point mPt1;
	Point mPt2;

};

