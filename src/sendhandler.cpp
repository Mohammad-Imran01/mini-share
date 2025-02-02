#include "sendhandler.h"

SendHandler::SendHandler(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer(this);


    connect(m_server, &QTcpServer::newConnection, this, &SendHandler::handleNewConnection);
    connect(m_server, &QTcpServer::acceptError, this, &SendHandler::handleError);

    startServer(SENDER_PORT_START);
}

void SendHandler::startServer(quint16 port)
{
    if (!m_server->listen(QHostAddress::Any, port)) {
        if(port < SENDER_PORT_START+20) {
            qWarning() << "Server could not start:" << m_server->errorString() << "Trying again with port: " << port+2;
            startServer(port+2);
        } else {
            qWarning() << Q_FUNC_INFO << "Cannot start server consider restarting the application.";
        }
    } else {
        qInfo() << "Server started, listening on port" << port;
    }
}

void SendHandler::handleNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();

    m_clients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, &SendHandler::handleReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &SendHandler::handleClientDisconnected);
    connect(clientSocket, &QTcpSocket::errorOccurred, this, &SendHandler::handleError);

    qInfo() << "New client connected:" << clientSocket->peerAddress().toString() << ":" << clientSocket->peerPort();

    emit newConnection(clientSocket);
}

void SendHandler::handleReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    QByteArray data = clientSocket->readAll();
    qInfo() << "Received data from client:" << data;

    emit dataReceived(clientSocket, data);

    clientSocket->write(data);
}

void SendHandler::handleClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        return;
    }

    m_clients.removeOne(clientSocket);

    qInfo() << "Client disconnected:" << clientSocket->peerAddress().toString() << ":" << clientSocket->peerPort();

    emit clientDisconnected(clientSocket);

    clientSocket->deleteLater();
}

void SendHandler::handleError(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        qWarning() << "Client error:" << clientSocket->errorString();
    } else {
        qWarning() << "Server error:" << m_server->errorString();
    }
}
