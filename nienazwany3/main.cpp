#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QSettings>
#include <iostream>
#include "Baza_danych.h"
#include <vector>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Baza_danych users;
    users.update();
    //users.check();
    //app.setApplicationName("lista");
    qmlRegisterType<Baza_danych>("Baza_danych",1,0,"Users");
    engine.rootContext()->setContextProperty("Baza_danych", &users);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
