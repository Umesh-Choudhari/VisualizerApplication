#pragma once
#include "Line.h"
#include "OpenGLWindow.h"

namespace symmetricDDAandSutherlandCohen
{
	class SymmetricDDA
	{
	public:
		SymmetricDDA();
		~SymmetricDDA();

	public:
		void drawGrid(QVector<GLfloat>& vertices, QVector<GLfloat>& colors);
		void drawLineBySymmetricDDA(Line& line, QVector<GLfloat>& mVertices, QVector<QVector2D>& pixelVertices);
		QVector<QVector2D>& getPixelVertices();
		
	private:
		OpenGLWindow* openglWindow;

	public:
		QVector<GLfloat> mVertices;
		QVector<GLfloat> mColors;

	private:
		QVector<QVector2D> mPixelVertices;

		GLint m_posAttr = 0;
		GLint m_colAttr = 0;
		GLint m_posAttr1 = 0;
		GLint m_colAttr1 = 0;
		GLint m_matrixUniform = 0;
	};

}


