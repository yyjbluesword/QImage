#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "operateimage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto operateImage = new OperateImage;
    engine.rootContext()->setContextProperty("operateImage",operateImage);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
