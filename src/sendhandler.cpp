#include "sendhandler.h"

SendHandler::SendHandler(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::acceptError, this, &SendHandler::handleError);
}

void SendHandler::handleError(QAbstractSocket::SocketError socketError) {

}
