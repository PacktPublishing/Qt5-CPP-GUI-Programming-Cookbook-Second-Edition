#include "mainwindow.h"
#include <QApplication>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QThread>
#include <QDebug>

void printText(QString text, int count)
{
	for (int i = 0; i < count; ++i)
	{
		qDebug() << text << QThread::currentThreadId();
	}
	qDebug() << text << "Done";
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	// Single thread
	//printText("A", 100);
	//printText("B", 100);

	// Multithreading using QFuture
	QFuture<void> f1 = QtConcurrent::run(printText, QString("A"), 100);
	QFuture<void> f2 = QtConcurrent::run(printText, QString("B"), 100);
	QFuture<void> f3 = QtConcurrent::run(printText, QString("C"), 100);

	// Using QFutureWatcher
	QFutureWatcher<void> futureWatcher;
	QObject::connect(&futureWatcher, QFutureWatcher<void>::finished, &w, MainWindow::mySlot);
	futureWatcher.setFuture(f1);

	f1.waitForFinished();
	f2.waitForFinished();
	f3.waitForFinished();

	return a.exec();
}
