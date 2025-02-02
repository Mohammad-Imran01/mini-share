import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: cntId
    property string deviceName: "Unknown Device"
    property string hostAddress: "0.0.0.0"
    property int portNum: -1

    property bool connectedState: false

    property string vatColorText:"blue"

    radius: 5
    color: connectedState ? "green" : "red"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Device Name: " + deviceName
            font.pixelSize: 18
            color: vatColorText
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            text: "Host Address: " + hostAddress
            font.pixelSize: 18
            color: vatColorText
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            text: "Port: " + (portNum >= 0 ? portNum : "Not Set")
            font.pixelSize: 18
            color: vatColorText
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
