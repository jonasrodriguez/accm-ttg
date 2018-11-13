import QtQuick 2.0
import QtQuick.Layouts 1.3

import "customControls"

Item {
    anchors.fill: parent

    Item {
        id: sideBarImage
        width: parent.width * 0.9
        height: parent.height * 0.2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10

        Image {
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "images/werfenIcon.png"
        }
    }

    Item {
        id: upperSideBarContent
        width: sideBarImage.width * 0.9
        height: width
        visible: !dashboardLogic.hideNav
        anchors {top: sideBarImage.bottom; left: sideBarImage.left}
        anchors.topMargin: height / 3
        anchors.leftMargin: sideBarImage.height * 0.15

        SideBarButton {
            id: homeSide
            textItem.text: "Home"
            onActivated: dashboardLogic.buttonNavHome()
        }
        SideBarButton {
            id: msgSide
            textItem.text: "Messages"
            textItem.font.bold: false
            anchors.top: homeSide.bottom
            Rectangle {
                width: parent.width * 0.8
                height: 1
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.bottomMargin: parent.height * 0.1
            }
        }
        SideBarButton {
            id: dataSide
            textItem.text: "Data Model"
            textItem.font.pixelSize: 15
            onActivated: dashboardLogic.buttonNavHome()
            anchors.top: msgSide.bottom
            anchors.left: parent.left
            anchors.leftMargin: height / 3
        }
        SideBarButton {
            id: convSide
            textItem.text: "Conversation"
            textItem.font.pixelSize: 15
            onActivated: dashboardLogic.buttonNavHome()
            anchors.top: dataSide.bottom
            anchors.left: parent.left
            anchors.leftMargin: height / 3
        }
        SideBarButton {
            id: genSide
            textItem.text: "Generation"
            onActivated: dashboardLogic.buttonNavHome()
            anchors.top: convSide.bottom
        }
    }
}
