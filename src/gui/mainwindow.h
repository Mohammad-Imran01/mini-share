#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QCoreApplication>

class MainWindow : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = nullptr);
signals:

};

#endif // MAINWINDOW_H
