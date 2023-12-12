#pragma once
class Point
{
public:
	Point();
	Point(float x, float y);	
	~Point();

	float x();
	float y();

	void setX(float x);
	void setY(float y);

private:
	float mXCoordinate;
	float mYCoordinate;
};

