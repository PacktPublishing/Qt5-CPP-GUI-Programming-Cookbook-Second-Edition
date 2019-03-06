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

	time = new QTime();
	time->start();
}

void RenderWindow::initializeGL()
{
	openGLFunctions = openGLContext->functions();
	glEnable(GL_DEPTH_TEST);

	static const char *vertexShaderSource =
	"#version 330 core\n"
	"layout(location = 0) in vec3 posAttr;\n"
	"uniform mat4 matrix;\n"
	"out vec3 fragPos;\n"
	"void main() {\n"
	"fragPos = posAttr;\n"
	"gl_Position = matrix * vec4(posAttr, 1.0); }";

	static const char *fragmentShaderSource =
	"#version 330 core\n"
	"in vec3 fragPos;\n"
	"out vec4 col;\n"
	"void main() {\n"
	"col = vec4(fragPos, 1.0); }";

	shaderProgram = new QOpenGLShaderProgram(this);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
	shaderProgram->link();

	GLfloat vertices[] =
	{
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f
	};

	vao = new QOpenGLVertexArrayObject();
	vao->create();
	vao->bind();

	vbo_vertices = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
	vbo_vertices->create();
	vbo_vertices->setUsagePattern(QOpenGLBuffer::StaticDraw);
	vbo_vertices->bind();
	vbo_vertices->allocate(vertices, sizeof(vertices) * sizeof(GLfloat));

	vao->release();
}

void RenderWindow::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	// Delta time for each frame
	currentTime = time->elapsed();
	deltaTime = (float)(currentTime - oldTime) / 1000.0f;
	oldTime = currentTime;

	glViewport(0, 0, this->width(), this->height());

	glClearColor(0.39f, 0.58f, 0.93f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vao->bind();
	shaderProgram->bind();

	rotation += deltaTime * 50;

	QMatrix4x4 matrixMVP;
	QMatrix4x4 model, view, projection;
	model.translate(0, 1, 0);
	model.rotate(rotation, 0, 1, 0);
	view.lookAt(QVector3D(5, 5, 5), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
	projection.perspective(60.0f, ((float)this->width()/(float)this->height()), 0.1f, 100.0f);
	matrixMVP = projection * view * model;
	shaderProgram->setUniformValue("matrix", matrixMVP);

	vbo_vertices->bind();
	shaderProgram->bindAttributeLocation("posAttr", 0);
	shaderProgram->enableAttributeArray(0);
	shaderProgram->setAttributeBuffer(0, GL_FLOAT, 0, 3);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	shaderProgram->release();
	vao->release();

	this->update();
}

void RenderWindow::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);

	glViewport(0, 0, this->width(), this->height());
	this->update();
}
