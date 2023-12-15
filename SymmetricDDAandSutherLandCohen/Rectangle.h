#pragma once
#include "Line.h"
#include <vector>

namespace symmetricDDAandSutherlandCohen
{
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(Point3D inMin, Point3D inMax);
		~Rectangle();

	public:
		std::vector<Line> lines();

	private:
		std::vector<Line> mLines;
	};
}


