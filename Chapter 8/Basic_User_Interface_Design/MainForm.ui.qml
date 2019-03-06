import QtQuick 2.5
import QtQuick.Dialogs.qml 1.0
import QtQuick.Window 2.10

Rectangle {
    id: rectangle4

    width: 360
    height: 360
    property alias passInput: passInput
    property alias userInput: userInput
    property alias loginButton: loginButton

    Rectangle {
        id: rectangle5
        x: 56
        y: 84
        width: 252
        height: 161
        color: "#ffffff"
        radius: 5
        border.color: "#5e5858"
        border.width: 2
    }

    MouseArea {
        id: loginButton
        x: 105
        y: 188
        width: 150
        height: 36
        anchors.verticalCenterOffset: 22
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 150
            height: 35
            color: "#bdbdbd"
            radius: 5
        }

        Text {
            id: text3
            x: 62
            y: 11
            anchors.centerIn: parent
            text: "Login"
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
        }
    }

    Text {
        id: text1
        x: 83
        y: 113
        text: qsTr("Username:")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 83
        y: 146
        width: 55
        height: 15
        text: qsTr("Password:")
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle2
        x: 164
        y: 111
        width: 115
        height: 20
        color: "#ffffff"
        radius: 5
        border.width: 1

        TextInput {
            id: userInput
            x: 0
            y: 0
            width: 115
            height: 20
            text: qsTr("user")
            echoMode: TextInput.Normal
        }
    }

    Rectangle {
        id: rectangle3
        x: 164
        y: 146
        width: 115
        height: 20
        color: "#ffffff"
        radius: 5
        border.width: 1

        TextInput {
            id: passInput
            x: 0
            y: 0
            width: 115
            height: 20
            text: qsTr("pass")
            font.family: "Times New Roman"
            echoMode: TextInput.Password
        }
    }
}
