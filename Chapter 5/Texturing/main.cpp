#include <QApplication>

#include "renderwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	RenderWindow window;
	window.setTitle("Hello World!");
	window.resize(640, 480);

	window.show();

	return app.exec();
}
