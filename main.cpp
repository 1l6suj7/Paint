#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <cpp/graphiclogic.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    qmlRegisterSingletonInstance("GraphicLogic", 1, 0, "GraphicLogic", GraphicLogic::getInstance());
    engine.loadFromModule("Paint", "Main");
    return app.exec();
}
