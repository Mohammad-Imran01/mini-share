#include "receiverhandler.h"

ReceiverHandler::ReceiverHandler(QObject *parent)
    : QObject{parent}, m_socket(new QTcpSocket(this))
{
    // Connect socket signals to slots
    connect(m_socket, &QTcpSocket::connected, this, &ReceiverHandler::handleConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &ReceiverHandler::handleReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &ReceiverHandler::handleDisconnected);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &ReceiverHandler::handleError);
}

void ReceiverHandler::connectToServer(const QString &host, quint16 port)
{
    m_socket->connectToHost(host, port);
    qInfo() << "Attempting to connect to server at" << host << ":" << port;
}

void ReceiverHandler::lookForServers(QString hostAddress, int port)
{

}

void ReceiverHandler::handleConnected()
{
    qInfo() << "Connected to server at" << m_socket->peerAddress().toString() << ":" << m_socket->peerPort();
    emit connected();
}

void ReceiverHandler::handleReadyRead()
{
    // Read all available data from the socket
    QByteArray data = m_socket->readAll();
    qInfo() << "Received data from server:" << data;

    // Emit the data received signal
    emit dataReceived(data);
}

void ReceiverHandler::handleDisconnected()
{
    qInfo() << "Disconnected from server.";
    emit disconnected();
}

void ReceiverHandler::handleError(QAbstractSocket::SocketError socketError)
{
    QString errorString = m_socket->errorString();
    qWarning() << "Socket error:" << errorString;
    emit errorOccurred(errorString);
}
