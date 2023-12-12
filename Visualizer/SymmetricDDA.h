#pragma once
#include "Line.h"
#include "OpenGLWindow.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class SymmetricDDA
{
public:
	SymmetricDDA();
	~SymmetricDDA();

	QVector<GLfloat> mVertices;
	QVector<GLfloat> mColors;
	QVector<QVector2D>& getPixelVertices();

public:
	void drawGrid(QVector<GLfloat>& vertices, QVector<GLfloat>& colors);
	void drawLineBySymmetricDDA(Line& line, QVector<QVector2D>& pixelVertices);

private:
	OpenGLWindow* openglWindow;

	QVector<QVector2D> mPixelVertices;

	GLint m_posAttr = 0;
	GLint m_colAttr = 0;
	GLint m_posAttr1 = 0;
	GLint m_colAttr1 = 0;
	GLint m_matrixUniform = 0;
};

