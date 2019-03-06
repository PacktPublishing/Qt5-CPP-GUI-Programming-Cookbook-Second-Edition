#include "renderwindow.h"

RenderWindow::RenderWindow()
{
	setSurfaceType(QWindow::OpenGLSurface);

	QSurfaceFormat format;
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setVersion(3, 2);
	setFormat(format);

	openGLContext = new QOpenGLContext();
	openGLContext->setFormat(format);
	openGLContext->create();
	openGLContext->makeCurrent(this);
}

void RenderWindow::initializeGL()
{
	openGLFunctions = openGLContext->functions();

	static const char *vertexShaderSource =
	"#version 330 core\n"
	"layout(location = 0) in vec2 posAttr;\n"
	"layout(location = 1) in vec3 colAttr;\n"
	"out vec3 fragCol;\n"
	"void main() {\n"
	"fragCol = colAttr;\n"
	"gl_Position = vec4(posAttr, 1.0, 1.0); }";

	static const char *fragmentShaderSource =
	"#version 330 core\n"
	"in vec3 fragCol;\n"
	"out vec4 col;\n"
	"void main() {\n"
	"col = vec4(fragCol, 1.0); }";

	shaderProgram = new QOpenGLShaderProgram(this);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	shaderProgram->link();

	GLfloat vertices[] =
	{
		-0.3f, -0.5f,
		0.8f, -0.4f,
		0.2f,  0.6f
	};

	GLfloat vertices2[] =
	{
		0.5f, 0.3f,
		0.4f, -0.8f,
		-0.6f,  -0.2f
	};

	GLfloat colors[] =
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	vao = new QOpenGLVertexArrayObject();
	vao->create();
	vao->bind();

	vbo_vertices = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo_vertices->create();
	vbo_vertices->setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo_vertices->bind();
	vbo_vertices->allocate(vertices, sizeof(vertices) * sizeof(GLfloat));

	vbo_vertices2 = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo_vertices2->create();
	vbo_vertices2->setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo_vertices2->bind();
	vbo_vertices2->allocate(vertices2, sizeof(vertices2) * sizeof(GLfloat));

	vbo_colors = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo_colors->create();
	vbo_colors->setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo_colors->bind();
	vbo_colors->allocate(colors, sizeof(colors) * sizeof(GLfloat));

	vao->release();
}

void RenderWindow::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	glViewport(0, 0, width(), height());

	glClearColor(0.39f, 0.58f, 0.93f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	vao->bind();
	shaderProgram->bind();

	vbo_vertices->bind();
	shaderProgram->bindAttributeLocation("posAttr", 0);
	shaderProgram->enableAttributeArray(0);
	shaderProgram->setAttributeBuffer(0, GL_FLOAT, 0, 2);

	vbo_colors->bind();
	shaderProgram->bindAttributeLocation("colAttr", 1);
	shaderProgram->enableAttributeArray(1);
	shaderProgram->setAttributeBuffer(1, GL_FLOAT, 0, 3);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	vbo_vertices2->bind();
	shaderProgram->bindAttributeLocation("posAttr", 0);
	shaderProgram->enableAttributeArray(0);
	shaderProgram->setAttributeBuffer(0, GL_FLOAT, 0, 2);

	vbo_colors->bind();
	shaderProgram->bindAttributeLocation("colAttr", 1);
	shaderProgram->enableAttributeArray(1);
	shaderProgram->setAttributeBuffer(1, GL_FLOAT, 0, 3);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	shaderProgram->release();
	vao->release();
}

void RenderWindow::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);

	glViewport(0, 0, this->width(), this->height());
	this->update();
}
