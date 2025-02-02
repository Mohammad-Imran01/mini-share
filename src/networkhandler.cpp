#include "networkhandler.h"

#include "src/receiverhandler.h"
#include "src/sendhandler.h"

NetworkHandler *NetworkHandler::getInstance() {

    static NetworkHandler instance;
    return &instance;
}

void NetworkHandler::iAmSenderClicked() {
    setDeviceType(NetworkHandler::Sender);

    m_sendHandler =  new SendHandler(this);




    qWarning() << Q_FUNC_INFO << "I am sender";
}

void NetworkHandler::iAmRecieverClicked() {
    setDeviceType(NetworkHandler::Reciever);

    m_recieverHandler = new ReceiverHandler(this);

    // emit serverPortChanged(110);

    qWarning() << Q_FUNC_INFO << "I am reciever";
}

NetworkHandler::NetworkHandler(QObject *parent)
    : QObject(parent)
{/*
    m_recieverHandler = new ReceiverHandler(this);
    m_sendHandler     = new SendHandler(this);*/

    qDebug() << Q_FUNC_INFO << "NetworkHandler initialized";
}

NetworkHandler::DeviceType NetworkHandler::deviceType() const
{
    return m_deviceType;
}
void NetworkHandler::setDeviceType(const DeviceType &newDeviceType)
{
    if (m_deviceType == NetworkHandler::None || m_deviceType == newDeviceType)
        return;
    m_deviceType = newDeviceType;
    emit deviceTypeChanged();
}
