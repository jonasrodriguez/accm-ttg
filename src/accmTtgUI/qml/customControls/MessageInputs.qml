import QtQuick 2.0

Item {
    property string labelText : "Label"

    Item {
        id: labelArea

        height: parent.height
        width: parent.width / 3
        anchors.left: parent.left

        Text {
            text: labelText
            color: "#96cb2d"
            font.family: "PT Mono"
            font.bold: true

            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: implicitHeight
        }
    }

    Rectangle {
        height: parent.height * 0.9
        width: parent.width - labelArea.width
        anchors.right: parent.right
        color: "#282828"
        radius: 5
        TextInput {
            color: "#cfc56a"
            font.family: "PT Mono"

            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: implicitHeight
        }
    }
}
