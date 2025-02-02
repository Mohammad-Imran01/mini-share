#ifndef RECEIVERHANDLER_H
#define RECEIVERHANDLER_H

#include <QObject>

class ReceiverHandler : public QObject
{
    Q_OBJECT
public:
    explicit ReceiverHandler(QObject *parent = nullptr);

signals:
};

#endif // RECEIVERHANDLER_H
