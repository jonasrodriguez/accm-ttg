import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../customControls"

Item {

    MessageInputs {
        id: msgName
        labelText: "Msg Name"

        height: titleArea.height / 2
        width: parent.width * 0.9

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: height
    }

    ColumnLayout {

        anchors.top: msgName.bottom
        anchors.left: parent.left
        anchors.leftMargin: msgName.height / 3

        RadioButton {
            id: radSend

            checked: true
            text: qsTr("Send")

            contentItem: Text {
                text: radSend.text
                color: "#96cb2d"
                font.family: "PT Mono"
                verticalAlignment: Text.AlignVCenter
                leftPadding: radSend.indicator.width + radSend.spacing
            }
        }
        RadioButton {
            id: radExpect

            text: qsTr("Expect")
            contentItem: Text {
                text: radExpect.text
                color: "#96cb2d"
                font.family: "PT Mono"
                verticalAlignment: Text.AlignVCenter
                leftPadding: radExpect.indicator.width + radExpect.spacing
            }
        }
    }
}
