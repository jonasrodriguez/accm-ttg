import QtQuick 2.0
import QtQuick.Layouts 1.3

import "customControls"

Item {
    anchors.fill: parent

    HomeButton {
        id: newXte
        textValue: "NEW XTE"
        anchors.centerIn: parent
        anchors.verticalCenterOffset: - height
        onActivated: dashboardLogic.buttonNavConversation()
    }

    HomeButton {
        textValue: "LOAD XTE"
        anchors { top: newXte.bottom; left: newXte.left; topMargin: height / 3 }
        onActivated: console.log("Load XTE is not implemented yet :(")
    }
}
