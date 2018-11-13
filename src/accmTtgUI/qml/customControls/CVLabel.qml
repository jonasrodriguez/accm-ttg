import QtQuick 2.0

Item {
    property string cv_Label : "Label"
    property string cv_Value : "cvValue"

    Item {
        id: cvTextLabel

        height: parent.height
        width: parent.width / 3
        anchors.left: parent.left

        Text {
            text: cv_Label
            color: "#96cb2d"
            font.family: "PT Mono"
            font.bold: true

            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: implicitHeight
        }
    }

    Rectangle {
        id: cvTextValue
        height: parent.height * 0.9
        width: parent.width * 0.55
        anchors.left: cvTextLabel.right
        color: "#282828"
        radius: 5
        Text {
            text: cv_Value
            color: "#cfc56a"
            font.family: "PT Mono"

            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: implicitHeight
        }
    }

    Rectangle {
        height: cvTextValue.height
        width: parent.width * 0.1
        anchors.right: parent.right
        color: "#f47023"
        radius: 15

        Text {
            text: qsTr("CV")
            color: "white"
            font.family: "PT Mono"
            font.bold: true

            anchors.centerIn: parent
        }
    }
}
