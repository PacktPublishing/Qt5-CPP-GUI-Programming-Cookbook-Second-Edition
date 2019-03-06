#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>
#include <QQuickItem>
#include <QQuickView>
#include "myclass.h"

int main(int argc, char *argv[])
{
    // Register your class to QML
    qmlRegisterType<MyClass>("MyClassLib", 1, 0, "MyClass");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects().value(0);

    QObject* messageText = root->findChild<QObject*>("messageText");
    messageText->setProperty("text", QVariant("C++ is now in control!"));
    messageText->setProperty("color", QVariant("green"));

    QObject* square = root->findChild<QObject*>("square");
    square->setProperty("color", QVariant("blue"));

    return app.exec();
}
