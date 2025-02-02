#include "mainwindow.h"

MainWindow::MainWindow(QObject *parent)
    : QQmlApplicationEngine(parent)
{
    const QUrl url(QStringLiteral("qrc:/mini-share/ui/main.qml"));

    // Connect to handle object creation failures
    QObject::connect(
        this,
        &QQmlApplicationEngine::objectCreationFailed,
        QCoreApplication::instance(),
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // Load the main QML file
    this->load(url);
}
