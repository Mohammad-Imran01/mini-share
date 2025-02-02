import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NetworkHandler 1.0
import SendHandler 1.0
import ReceiverHandler 1.0
import "./common"

Window {
    id: mainWindowId
    width: 510
    height: 680

    minimumHeight: height
    maximumHeight: height
    minimumWidth: width
    maximumWidth: width

    x: Screen.width - width * 1.1
    y: Screen.height / 2 - height / 2

    visible: true
    title: qsTr("Mini Share")

    color: /*objColId.constColBackground*/objColId.constColHeader


    property NetworkHandler     varHandle           : NetworkHandler.getInstance()
    property SendHandler        varSendHandler      : NetworkHandler.getSendHandler()
    property ReceiverHandler    varReceiverHandler  : NetworkHandler.getReceiverHandler()


    // Custom colors
    QtObject {
        id: objColId
        // Blue
        readonly property string constColBlueDark: "#000957"
        readonly property string constColBlue: "#344CB7"
        readonly property string constColBlueLight: "#577BC1"
        // Grey
        readonly property string constColGreyLighter: "#A5BFCC"
        readonly property string constColGreyLight: "#7E99A3"
        readonly property string constColGrey: "#4C585B"
        // UI Colors
        readonly property string constColHeader: "#4A628A"
        readonly property string constColBackground: "#7AB2D3"
        readonly property string constColButton: "#344CB7"
        readonly property string constColButtonPressed: "#577BC1"
    }



    Item {
        id: headerBoxId

        anchors {
            top:parent.top
            left:parent.left
            right:parent.right
            topMargin: -headerBoxId.radius
        }
        height: mainWindowId.height * 0.1

        Label {
            anchors.centerIn: parent
            text: "Mini Share"
            font.pixelSize: 24
            color: "white"
        }
    } // container text header

    Rectangle {
        id:mainRectId

        visible: false
        anchors {
            top:headerBoxId.bottom
            bottom:parent.bottom
            left:parent.left
            right:parent.right
            bottomMargin: -mainRectId.radius
        }
        radius: 20
        color: objColId.constColBackground


        RowLayout {
            spacing: 20
            anchors.centerIn: parent

            CxAboutNetwork {
                id: boxServerID
                Layout.fillWidth: true
                Layout.preferredHeight: mainWindowId.height * 0.26
                color: objColId.constColGreyLighter
                vatColorText: objColId.constColHeader

                // deviceName: varSendHandler.nameLabel
                // hostAddress: varSendHandler.hostAddress
                // portNum: varSendHandler.portNum
                // connectedState: varSendHandler.isConnected

                CxButton {
                    text: "Start"
                    onClicked: varHandle.iAmSenderClicked()

                    width:150
                    height:40
                    anchors {
                        bottom: parent.bottom
                        bottomMargin: 20
                        horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            CxAboutNetwork {
                id: boxClientID
                Layout.fillWidth: true
                Layout.preferredHeight: mainWindowId.height * 0.26
                color: objColId.constColGreyLighter
                vatColorText: objColId.constColHeader

                // deviceName      : varReceiverHandler.nameLabel
                // hostAddress     : varReceiverHandler.hostAddress
                // portNum         : varReceiverHandler.portNum
                // connectedState  : varReceiverHandler.isConnected

                CxButton {
                    text: "Start"
                    onClicked: varHandle.iAmSenderClicked()

                    width:150
                    height:40
                    anchors {
                        bottom: parent.bottom
                        bottomMargin: 20
                        horizontalCenter: parent.horizontalCenter
                    }
                }
            }

        }

    }

    Connections {
        target: varHandle
        function onServerPortChanged(portNum) {
            console.log("Server port changed to:", portNum)
        }
    }

    Rectangle {
        id:mainRect2Id

        visible: false
        anchors {
            top:headerBoxId.bottom
            bottom:parent.bottom
            left:parent.left
            right:parent.right
            bottomMargin: -mainRectId.radius
        }
        radius: 20
        color: objColId.constColBackground
    }
    Component.onCompleted: console.log("Application started")
}
