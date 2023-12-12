#include "stdafx.h"
#include "Point.h"

Point::Point()
{

}

Point::Point(float x, float y)
	:mXCoordinate(0),
	 mYCoordinate(0)
{
	mXCoordinate = x;
	mYCoordinate = y;
}

Point::~Point()
{

}

float Point::x()
{
	return mXCoordinate;
}

float Point::y()
{
	return mYCoordinate;
}

void Point::setX(float x)
{
	mXCoordinate = x;
}

void Point::setY(float y)
{
	mYCoordinate = y;
}



