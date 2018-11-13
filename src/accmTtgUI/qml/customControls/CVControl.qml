import QtQuick 2.0
import QtQuick.Controls 2.4

Popup {

    property string cvLabel : "cvLabel"

    GroupBox {
        anchors.fill: parent
        title: cvLabel

        MessageInputs {
            id: cvDN
            height: parent.height / 3
            width: parent.width / 2

            anchors.top: parent.top
            anchors.left: parent.left
            labelText: "DN"
        }

        MessageInputs {
            id: cvS
            labelText: "S"

            height: cvDN.height
            width: cvDN.width

            anchors.top: cvDN.bottom
            anchors.left: parent.left
        }

        MessageInputs {
            id: cvSN
            labelText: "SN"

            height: cvDN.height
            width: cvDN.width

            anchors.top: cvDN.bottom
            anchors.left: cvS.right
        }

        MessageInputs {
            id: cvSV
            labelText: "SV"

            height: cvDN.height
            width: cvDN.width

            anchors.top: cvS.bottom
            anchors.left: cvS.left
        }

        MessageInputs {
            id: cvV
            labelText: "v"

            height: cvDN.height
            width: cvDN.width

            anchors.top: cvSV.top
            anchors.left: cvSV.right
        }
    }
}
