#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QDebug>

class MyWorker : public QObject
{
	Q_OBJECT
public:
	explicit MyWorker(QObject *parent = nullptr);

signals:
	void showResults(int res);
	void doneProcess();

public slots:
	void process();
};

#endif // MYWORKER_H
