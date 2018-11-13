import QtQuick 2.0

Rectangle {
    property alias textValue : buttonText.text

    signal activated()

    width: parent.width * 0.15
    height: width / 2
    radius: 5
    color: "#282828"
    border.color: "black"
    border.width: (mouseHomeButton.containsMouse) ? 1 : 0
    Text {
        id: buttonText
        color: "#96cb2d"
        font.family: "PT Mono"
        font.pixelSize: 16
        text: textValue
        font.bold: (mouseHomeButton.containsMouse) ? true : false

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
    MouseArea {
        id: mouseHomeButton
        anchors.fill: parent
        hoverEnabled: true
        onPressed: parent.activated()
    }
}
