#include "myworker.h"

MyWorker::MyWorker(QMutex *mutex)
{
	myMutex = mutex;
}

void MyWorker::process()
{
	//myMutex->lock();

	for (int i = 1; i < 100000; ++i)
	{
		*myInputNumber += i * i + 2 * i + 3 * i;
	}

	//myMutex->unlock();

	emit showResults(*myInputNumber);
	emit doneProcess();
}
