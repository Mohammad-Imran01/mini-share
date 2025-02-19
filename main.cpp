#include "src/networkhandler.h"
#include "src/sendhandler.h"
#include "src/receiverhandler.h"
#include "src/gui/mainwindow.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SendHandler>("SendHandler", 1, 0, "SendHandler");
    qmlRegisterType<ReceiverHandler>("ReceiverHandler", 1, 0, "ReceiverHandler");

    qmlRegisterSingletonType<NetworkHandler>(
        "NetworkHandler", 1, 0, "NetworkHandler",
        [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            return NetworkHandler::getInstance();
        });

    MainWindow mainWindow;

    return app.exec();
}
