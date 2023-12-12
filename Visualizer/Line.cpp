#include "stdafx.h"
#include "Line.h"

Line::Line()
{

}

Line::Line(Point pt1, Point pt2):
	mPt1(pt1),
	mPt2(pt2)
{

}

Line::~Line()
{

}

Point& Line::getPoint1()
{
	return mPt1;
}

Point& Line::getPoint2()
{
	return mPt2;
}
