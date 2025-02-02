import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: parent.height*.2
        Repeater {
            model:3
            delegate: Rectangle {
                color: "black"
                radius: 2
                Layout.preferredHeight: 3
                Layout.fillWidth: true
                border {
                    color: "grey"
                }
            }
        }
    }
}
