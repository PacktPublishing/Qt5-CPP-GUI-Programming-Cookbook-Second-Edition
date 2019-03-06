#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
}

void MyClass::doSomething()
{
	QMessageBox::information(this, "Hello", "Button has been clicked!");
}
