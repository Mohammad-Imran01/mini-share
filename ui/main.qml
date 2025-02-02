import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import NetworkHandler 1.0
import "./common"

Window {
    id:mainWindowId
    width: 510
    height: 680

    minimumHeight: height
    maximumHeight: height
    minimumWidth: width
    maximumWidth: width

    x: Screen.width-width*1.1
    y: Screen.height/2 - height/2

    visible: true
    title: qsTr("Mini Share")

    color: objColId.constColBackground

    QtObject {
        id:objMainId
        property int varHeaderWidth:mainWindowId.width
        property int varHeaderHeight:mainWindowId.height*.1
    }

    property NetworkHandler varHandle: NetworkHandler.getInstance()

    QtObject {
        id:objColId

        // blue
        readonly property string constColBlueDark: "#000957"
        readonly property string constColBlue: "#344CB7"
        readonly property string constColBlueLight: "#577BC1"
        //grey
        readonly property string constColGreyLighter: "#A5BFCC"
        readonly property string constColGreyLight: "#7E99A3"
        readonly property string constColGrey: "#4C585B"

        readonly property string constColHeader:"#4A628A"
        readonly property string constColBackground:"#7AB2D3"
    }


    ColumnLayout {
        id:mainLayoutId
        anchors.fill: parent
        Rectangle {
            id:headerBoxId
            Layout.fillWidth: true
            Layout.preferredHeight: objMainId.varHeaderHeight
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            color: objColId.constColHeader

        }
        Item {
            Layout.fillHeight: true
        }
    }

    Loader {
        id:mainLoaderId
        height: parent.height*.26
        width: parent.width*.65
        anchors.centerIn: parent

        sourceComponent: compMainId
    }
    Component {
        id: compMainId
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 20
            CxButton {
                text:"Send"
                onClicked: NetworkHandler.iAmSenderClicked()
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            CxButton {
                text:"Recieve"
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: NetworkHandler.iAmRecieverClicked()
            }
        }
    }


    Connections {
        target: varHandle
        function onServerPortChanged(portNum) {
            console.log(portNum)
        }
    }


    Component.onCompleted: console.log("Hello, World!")
}
