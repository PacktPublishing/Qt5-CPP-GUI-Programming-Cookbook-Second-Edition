#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = 0);

    // Object pointer
    QObject* myObject;

    // Must call Q_INVOKABLE so that this function can be used in QML
    Q_INVOKABLE void setMyObject(QObject* obj);

signals:

public slots:
};

#endif // MYCLASS_H
