#include "myworker.h"

MyWorker::MyWorker(QObject *parent) : QObject(parent)
{

}

void MyWorker::process()
{
	int result = 0;
	for (int i = 0; i < 2000000000; ++i)
	{
		result += 1;
	}
	emit showResults(result);
	emit doneProcess();
}
