import QtQuick 2.0
import QtQuick.Controls 2.4

import "elements"
import "customControls"

Item {
    anchors.fill: parent

    //Title
    Rectangle {
        id: titleArea
        height: parent.height * 0.1
        width: parent.width * 0.5

        color: "transparent"
        border.width: 1
        border.color: "white"

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            text: qsTr("Message Modification Screen")
            color: "white"
            font.family: "PT Mono"
            font.pixelSize: 25

            anchors.centerIn: parent
        }
    }

    //Message Selector and Name

    MessageSelector {
        id: selectArea

        height: parent.height * 0.25
        width: parent.width * 0.4

        anchors.top: titleArea.bottom
        anchors.left: parent.left
    }

    //Message Header
    MessageHeader {
        id: msgHeader

        height: parent.height * 0.30
        width: parent.width - selectArea.width

        anchors.top: titleArea.bottom
        anchors.left: selectArea.right
    }

    //Message Type Selector
    ComboBox {
        id: msgType
        height: titleArea / 2
        model: ["Ack", "Hel", "Dst", "End"]

        anchors.top: selectArea.bottom
        anchors.left: parent.left
        anchors.topMargin: height / 3
    }

    //Message Body
    Loader {
        height: parent.height * 0.35
        width: parent.width

        anchors.top: msgType.bottom
        anchors.left: parent.left

        source: "elements/MessageBodyAck.qml"
    }

    //Buttoms
}
