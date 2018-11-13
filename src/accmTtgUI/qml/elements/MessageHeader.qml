import QtQuick 2.0

import "../customControls"

Item {

    //Header Title
    Item {
        id: headerTitle

        height: titleArea.height / 2
        width: headerGroup.width

        anchors.left: headerGroup.left
        anchors.bottom: headerGroup.top

        Text {
            text: qsTr("Message Header")

            color: "white"
            font.family: "PT Mono"
            font.pixelSize: 18
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    //Header Content
    Rectangle {
        id: headerGroup

        height: parent.height * 0.8
        width: parent.width * 0.9
        radius: 5

        anchors.bottom: parent.bottom
        anchors.left: parent.left

        color: "transparent"
        border.width: 2
        border.color: "white"

        MessageInputs {
            id: controlId
            labelText: "Control ID"

            height: titleArea.height / 2
            width: parent.width * 0.95

            anchors.top: parent.top
            anchors.left: parent.left

            anchors.topMargin: (parent.height - controlId.height * 3) / 2
        }

        MessageInputs {
            id: versionID
            labelText: "Version ID"

            height: controlId.height
            width: controlId.width

            anchors.top: controlId.bottom
            anchors.left: controlId.left
        }

        CVLabel {
            id: headerCV
            cv_Label: "Message Type"
            cv_Value: "cv_Value"

            height: controlId.height
            width: controlId.width

            anchors.top: versionID.bottom
            anchors.left: versionID.left
        }
    }
}
