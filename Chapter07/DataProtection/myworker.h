#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QDebug>
#include <QMutex>

class MyWorker : public QObject
{
	Q_OBJECT
public:
	explicit MyWorker(QMutex *mutex);
	int* myInputNumber;
	QMutex* myMutex;

signals:
	void showResults(int res);
	void doneProcess();

public slots:
	void process();
};

#endif // MYWORKER_H
