#ifndef SENDHANDLER_H
#define SENDHANDLER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>


#define SENDER_PORT_START 4001

class SendHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nameLabel MEMBER m_nameLabel NOTIFY nameLabelChanged FINAL)
    Q_PROPERTY(bool isConnected MEMBER m_isConnected NOTIFY isConnectedChanged FINAL)
    Q_PROPERTY(QString hostAddress MEMBER m_hostAddress NOTIFY hostAddressChanged FINAL)
    Q_PROPERTY(QString portNum MEMBER m_portNum NOTIFY portNumChanged FINAL)

public:
    explicit SendHandler(QObject *parent = nullptr);
    void startServer(quint16 port);

signals:
    void newConnection(QTcpSocket *socket);
    void dataReceived(QTcpSocket *socket, const QByteArray &data);
    void clientDisconnected(QTcpSocket *socket);

    void nameLabelChanged();
    void isConnectedChanged();
    void hostAddressChanged();
    void portNumChanged();


private slots:
    void handleNewConnection();
    void handleReadyRead();
    void handleClientDisconnected();
    void handleError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;

    QString m_nameLabel = "Sender";
    bool m_isConnected = false;
    QString m_hostAddress = "Unknown Device";
    QString m_portNum = "0.0.0.0";
};

#endif // SENDHANDLER_H
