#include <QCoreApplication>

#include "server.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	server* myServer = new server();
	myServer->startServer();

	return a.exec();
}
