import QtQuick 2.0

Rectangle {
    id: dashboard

    Rectangle {
        id: sideBarArea
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width * 0.18
        color: "#097bed"

        SideBar {}
    }

    Rectangle {
        id: mainArea
        color: "#303030"
        anchors { top: parent.top; bottom: parent.bottom;
            left: sideBarArea.right; right: parent.right;
        }

        Loader{
            anchors.fill: parent
            source: dashboardLogic.navigation
        }
    }

    //Message Dialog Loader
    Loader {
        id: messageDialogLoader
        source: "MessageDialog.qml"
        active: false
        anchors.fill: parent
    }
}
