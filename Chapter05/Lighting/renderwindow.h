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
	QOpenGLBuffer* vbo_uvs;
	QOpenGLBuffer* vbo_normals;
	QOpenGLTexture* texture;

	QTime* time;
	int currentTime = 0;
	int oldTime = 0;
	float deltaTime = 0;
	float rotation = 0;
};

#endif // RENDERWINDOW_H
