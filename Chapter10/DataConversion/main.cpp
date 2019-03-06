#include <QCoreApplication>
#include <QDebug>
#include <QtMath>
#include <QDateTime>
#include <QTextCodec>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // String to number
    int numberA = 2;
    QString numberB = "5";
    qDebug() << "1) " << "2 + 5 =" << numberA + numberB.toInt();

    // Number to string
    float numberC = 10.25;
    float numberD = 2;
    QString result = QString::number(numberC * numberD);
    qDebug() << "2) " <<  "10.25 * 2 =" << result;

    // Floor
    float numberE = 10.3;
    float numberF = qFloor(numberE);
    qDebug() << "3) " << "Floor of 10.3 is" << numberF;

    // Ceil
    float numberG = 10.3;
    float numberH = qCeil(numberG);
    qDebug() << "4) " << "Ceil of 10.3 is" << numberH;

    // Date time from string
    QString dateTimeAString = "2016-05-04 12:24:00";
    QDateTime dateTimeA = QDateTime::fromString(dateTimeAString, "yyyy-MM-dd hh:mm:ss");
    qDebug() << "5) " << dateTimeA;

    // Date time to string
    QDateTime dateTimeB = QDateTime::currentDateTime();
    QString dateTimeBString = dateTimeB.toString("dd/MM/yy hh:mm");
    qDebug() << "6) " << dateTimeBString;

    // String to all uppercase
    QString hello1 = "hello world!";
    qDebug() << "7) " << hello1.toUpper();

    // String to all lowercase
    QString hello2 = "HELLO WORLD!";
    qDebug() << "8) " << hello2.toLower();

    // QVariant to double
    QVariant aNumber = QVariant(3.14159);
    double aResult = 12.5 * aNumber.toDouble();
    qDebug() << "9) 12.5 * 3.14159 =" << aResult;

    // QVariant different types
    qDebug() << "10) ";
    QVariant myData = QVariant(10);
    qDebug() << myData;
    myData = myData.toFloat() / 2.135;
    qDebug() << myData;
    myData = true;
    qDebug() << myData;
    myData = QDateTime::currentDateTime();
    qDebug() << myData;
    myData = "Good bye!";
    qDebug() << myData;

    return a.exec();
}
