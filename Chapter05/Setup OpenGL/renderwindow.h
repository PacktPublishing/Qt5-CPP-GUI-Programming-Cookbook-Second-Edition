#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <GL/glu.h>
#include <QtOpenGL>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class RenderWindow : public QOpenGLWindow
{
public:
	RenderWindow();

protected:
	void initializeGL();
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	QOpenGLContext* openGLContext;
	QOpenGLFunctions* openGLFunctions;
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLVertexArrayObject* vao;
	QOpenGLBuffer* vbo_vertices;
};

#endif // RENDERWINDOW_H
