#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class ReceiverHandler;
class SendHandler;

class NetworkHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(DeviceType deviceType READ deviceType WRITE setDeviceType NOTIFY deviceTypeChanged FINAL)
public:
    enum DeviceType {None=0, Sender, Reciever};
    Q_ENUM(DeviceType)
    Q_INVOKABLE static NetworkHandler *getInstance();

    /**
     * This function will be triggered when the "I am Sender" button is clicked.
     * It will handle the client's side of the communication.
     * The function will:
     * 1. Connect to a remote server (specified by a hostname and port).
     * 2. Send data to the server (e.g., a message or file).
     *
     * The connection and sending process will be managed through the SendHandler.
     */
    Q_INVOKABLE void iAmSenderClicked();

    /**
     * This function will be triggered when the "I am Receiver" button is clicked.
     * It will handle the server's side of the communication.
     * The function will:
     * 1. Start listening for incoming connections on a specified port.
     * 2. Accept incoming connections and process received data from clients.
     *
     * The server setup and data receiving process will be managed through the ReceiverHandler.
     */
    Q_INVOKABLE void iAmRecieverClicked();
    
    DeviceType deviceType() const;
    void setDeviceType(const DeviceType &newDeviceType);

    Q_INVOKABLE ReceiverHandler* getReceiverHandler() { return m_recieverHandler; }
    Q_INVOKABLE SendHandler* getSendHandler() {return m_sendHandler; }

signals:
    void deviceTypeChanged();
    void serverPortChanged(int);

private: // constructor setup
    explicit NetworkHandler(QObject *parent = nullptr);

    NetworkHandler(const NetworkHandler&) = delete;
    NetworkHandler& operator=(const NetworkHandler&) = delete;

private: // private variables and functions.
    ReceiverHandler* m_recieverHandler = nullptr;
    SendHandler* m_sendHandler = nullptr;
    DeviceType m_deviceType;
};

#endif // NETWORKHANDLER_H
