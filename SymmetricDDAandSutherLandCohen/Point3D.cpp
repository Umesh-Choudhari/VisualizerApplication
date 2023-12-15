#include "stdafx.h"
#include "Point3D.h"

using namespace symmetricDDAandSutherlandCohen;

Point3D::Point3D(double inX, double inY) :
	mX(inX),
	mY(inY)
{

}

Point3D::~Point3D() 
{

}

double Point3D::x()
{
	return mX;
}

double Point3D::y()
{
	return mY;
}

void Point3D::setX(double inX)
{
	mX = inX;
}

void Point3D::setY(double inY)
{
	mY = inY;
}