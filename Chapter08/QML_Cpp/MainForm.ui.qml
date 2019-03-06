import QtQuick 2.4

Rectangle {    
    width: 360
    height: 360
    property alias messageText: messageText
    property alias rectangle1: rectangle1
    property alias mouseArea: mouseArea

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Text {
        id: messageText
        objectName: "messageText"
        anchors.centerIn: parent
        text: "Change this text using C++"
        anchors.verticalCenterOffset: 120
        anchors.horizontalCenterOffset: 0
        font.pointSize: 18
    }

    Rectangle {
        id: rectangle1
        objectName: "square"
        x: 80
        y: 66
        width: 200
        height: 200
        color: "#ff0d0d"
        anchors.verticalCenterOffset: -14
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
