#pragma once
#include "Rectangle.h"

namespace symmetricDDAandSutherlandCohen
{
	class SutherlandandCohenAlgorithm
	{
	public:
		SutherlandandCohenAlgorithm(Line& line, Line& diagonalLine, QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors);
		~SutherlandandCohenAlgorithm();

		int computeBinaryCode(double x, double y, Line& diagonalLine);
		void lineDrawingBySutherlandCohen(Line& line, Line& diagonalLine, QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors);

	public:
		QVector<GLfloat> verticesOfOrignalLine;
		QVector<GLfloat> colorOfOrignalLine;

	private:
		Line* mLine;

		const int INSIDE = 0;     // 0000
		const int LEFT   = 1;	  // 0001
		const int RIGHT  = 2;     // 0010
		const int BOTTOM = 4;     // 0100
		const int TOP    = 8;     // 1000
	};
}


