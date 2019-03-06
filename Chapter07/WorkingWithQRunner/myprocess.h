#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QRunnable>
#include <QDebug>

class MyProcess : public QRunnable
{
public:
	MyProcess();
	void run();
};

#endif // MYPROCESS_H
