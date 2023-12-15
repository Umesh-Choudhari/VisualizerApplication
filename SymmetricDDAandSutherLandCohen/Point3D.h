#pragma once

namespace symmetricDDAandSutherlandCohen
{
	class Point3D
	{
	public:
		Point3D(double inX, double inY);
		~Point3D();

	public:
		double x();
		double y();

		void setX(double inX);
		void setY(double inY);

	private:
		double mX;
		double mY;

	};

}
