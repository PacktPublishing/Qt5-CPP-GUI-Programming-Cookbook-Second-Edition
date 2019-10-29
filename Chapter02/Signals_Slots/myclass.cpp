#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
}

void MyClass::doSomething()
{
    QMessageBox::information(nullptr, "Hello", "Button has been clicked!");
}
