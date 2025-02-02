#ifndef RECEIVERHANDLER_H
#define RECEIVERHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

class ReceiverHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nameLabel MEMBER m_nameLabel NOTIFY nameLabelChanged FINAL)
    Q_PROPERTY(bool isConnected MEMBER m_isConnected NOTIFY isConnectedChanged FINAL)
    Q_PROPERTY(QString hostAddress MEMBER m_hostAddress NOTIFY hostAddressChanged FINAL)
    Q_PROPERTY(QString portNum MEMBER m_portNum NOTIFY portNumChanged FINAL)
public:
    explicit ReceiverHandler(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port); // Connect to the sender (server)
    Q_INVOKABLE void lookForServers(QString hostAddress, int port);
signals:
    void connected(); // Signal emitted when connected to the server
    void dataReceived(const QByteArray &data); // Signal emitted when data is received
    void disconnected(); // Signal emitted when disconnected from the server
    void errorOccurred(const QString &errorString); // Signal emitted when an error occurs

    void nameLabelChanged();
    void isConnectedChanged();
    void hostAddressChanged();
    void portNumChanged();

private slots:
    void handleConnected(); // Slot to handle successful connection
    void handleReadyRead(); // Slot to handle incoming data
    void handleDisconnected(); // Slot to handle disconnection
    void handleError(QAbstractSocket::SocketError socketError); // Slot to handle errors

private:
    QTcpSocket *m_socket; // TCP socket for communication

    QString m_nameLabel = "Sender";
    bool m_isConnected = false;
    QString m_hostAddress = "Unknown Device";
    QString m_portNum = "0.0.0.0";
};

#endif // RECEIVERHANDLER_H
