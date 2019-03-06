#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent)
{
}

void MyClass::setMyObject(QObject* obj)
{
     // Set the object pointer
     myObject = obj;
}
