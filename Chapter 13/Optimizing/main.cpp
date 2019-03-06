#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>
#include <vector>
#include <QVector>

int testArray(int count)
{
	int sum = 0;
	int *myarray = new int[count];
	for (int i = 0; i < count; ++i)
		myarray[i] = i;
	for (int j = 0; j < count; ++j)
		sum += myarray[j];
	delete [] myarray;
	return sum;
}

int testVector(int count)
{
	int sum = 0;
	std::vector<int> myarray;
	for (int i = 0; i < count; ++i)
		myarray.push_back(i);
	for (int j = 0; j < count; ++j)
		sum += myarray.at(j);
	return sum;
}

int testQtVector(int count)
{
	int sum = 0;
	QVector<int> myarray;
	for (int i = 0; i < count; ++i)
		myarray.push_back(i);
	for (int j = 0; j < count; ++j)
		sum += myarray.at(j);
	return sum;
}

int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	// Test C++
	QTime* time = new QTime;
	time->start();
	int lastElapse = 0;

	int result = testArray(100000000);
	qDebug() << "Array:" << (time->elapsed() - lastElapse) << "msec";
	lastElapse = time->elapsed();

	int result2 = testVector(100000000);
	qDebug() << "STL vector:" << (time->elapsed() - lastElapse) << "msec";
	lastElapse = time->elapsed();

	int result3 = testQtVector(100000000);
	qDebug() << "Qt vector:" << (time->elapsed() - lastElapse) << "msec";
	lastElapse = time->elapsed();

	return a.exec();
}
