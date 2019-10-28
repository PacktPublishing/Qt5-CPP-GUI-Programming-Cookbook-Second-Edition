import QtQuick 2.5

Rectangle {
    id: window

    width: 800
    height: 600

    Image {
        id: background
        anchors.fill: parent
        source: "login_bg.png"
    }

    Rectangle {
        id: topPanel
        height: 67
        transformOrigin: Item.Top
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#805bcce9"
            }

            GradientStop {
                position: 1
                color: "#80000000"
            }
        }

        Rectangle {
            id: shutdownButton
            x: 562
            width: 50
            height: 50
            color: "#27a9e3"
            radius: 2
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 10

            Image {
                id: image1
                anchors.fill: parent
                source: "shutdown_icon.png"
            }
        }

        Rectangle {
            id: restartButton
            x: 684
            width: 50
            height: 50
            color: "#27a9e3"
            radius: 2
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 66

            Image {
                id: image2
                anchors.fill: parent
                source: "restart_icon.png"
            }
        }
    }

    Text {
        id: dateTime
        color: "#ffffff"
        text: qsTr("Monday, 26-10-2015 3:14 PM")
        anchors.top: parent.top
        anchors.topMargin: 26
        anchors.left: parent.left
        anchors.leftMargin: 26
        font.pixelSize: 14
    }

    Rectangle {
        id: loginForm
        x: 221
        y: 311
        width: 360
        height: 200
        color: "#80000000"
        radius: 15
        anchors.verticalCenterOffset: 100
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text1
            x: 42
            y: 46
            color: "#ffffff"
            text: qsTr("Username:")
            font.pixelSize: 14
        }

        Text {
            id: text2
            x: 41
            y: 83
            color: "#ffffff"
            text: qsTr("Password:")
            font.pixelSize: 14
        }

        TextInput {
            id: textInput1
            x: 112
            y: 42
            width: 209
            height: 25
            text: qsTr("")
            font.family: "Verdana"
            font.pixelSize: 14

            Rectangle {
                id: rectangle1
                width: 15
                color: "#ffffff"
                radius: 5
                z: -1
                anchors.leftMargin: 0
                anchors.fill: parent
            }
        }

        TextInput {
            id: textInput2
            x: 112
            y: 79
            width: 209
            height: 25
            text: qsTr("")
            font.pixelSize: 14

            Rectangle {
                id: rectangle2
                width: 190
                color: "#ffffff"
                radius: 5
                z: -1
                anchors.leftMargin: 0
                anchors.fill: parent
            }
        }

        MouseArea {
            id: mouseArea1
            x: 43
            y: 135
            width: 278
            height: 31

            Rectangle {
                id: rectangle3
                color: "#27a9e3"
                radius: 5
                anchors.fill: parent
            }

            Text {
                id: text3
                x: 127
                y: 8
                color: "#ffffff"
                text: qsTr("Login")
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 14
            }
        }

        Image {
            id: logo
            x: -76
            y: -190
            width: 512
            height: 200
            fillMode: Image.Stretch
            source: "logo.png"
        }
    }
}
