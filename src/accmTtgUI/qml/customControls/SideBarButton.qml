import QtQuick 2.0

Item {
    property alias textItem: buttonText

    signal activated()

    width: parent.width
    height: parent.height / 4

    Text {
        id: buttonText
        color: "white"
        font.family: "PT mono"
        font.pixelSize: 18
        font.bold: (mouseSideBar.containsMouse) ? true : false
        anchors.verticalCenter: parent.verticalCenter
    }
    MouseArea {
        id: mouseSideBar
        anchors.fill: parent
        hoverEnabled: true
        onPressed: parent.activated()
    }
}
