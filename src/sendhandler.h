#ifndef SENDHANDLER_H
#define SENDHANDLER_H

#include <QObject>
#include <QTcpServer>

class SendHandler : public QObject
{
    Q_OBJECT
public:
    explicit SendHandler(QObject *parent = nullptr);

signals:
private:
    void handleError(QAbstractSocket::SocketError socketError);
    QTcpServer* m_server = nullptr;
};

#endif // SENDHANDLER_H
