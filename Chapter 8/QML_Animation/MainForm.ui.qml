import QtQuick 2.5
import QtQuick.Controls 1.3

Rectangle {
    id: rectangle1
    width: 480
    property alias rectangle2: rectangle2

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1
    property alias mouseArea1: mouseArea1
    property alias fan: fan
    property alias mouseArea2: mouseArea2

    MouseArea {
        id: mouseArea1
        x: 303
        y: 304
        width: 150
        height: 150

        Image {
            id: fan
            x: 0
            y: 0
            width: 150
            height: 150
            source: "fan.png"
        }
    }

    MouseArea {
        id: mouseArea2
        x: 50
        y: 300
        width: 100
        height: 100

        Rectangle {
            id: rectangle2
            x: 0
            y: 0
            width: 100
            height: 100
            color: "blue"
        }
    }

    Button {
        id: button1
        y: 0
        height: 45
        text: qsTr("Button")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }



    Button {
        id: button2
        x: 0
        y: 45
        height: 45
        text: qsTr("Button")
        anchors.leftMargin: 0
        anchors.left: parent.left
        anchors.rightMargin: 0
        anchors.right: parent.right
    }



    Button {
        id: button3
        x: 0
        y: 90
        height: 45
        text: qsTr("Button")
        anchors.leftMargin: 0
        anchors.left: parent.left
        anchors.rightMargin: 0
        anchors.right: parent.right
    }


}
