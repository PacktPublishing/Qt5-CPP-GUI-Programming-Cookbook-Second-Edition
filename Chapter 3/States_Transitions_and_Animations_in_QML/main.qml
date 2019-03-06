import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    visible: true
    width: 480;
    height: 320;

    /*Rectangle {
        id: myBox;
        width: 50;
        height: 50;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        color: "blue";*/

        /*ParallelAnimation {
            ScaleAnimator {
                target: myBox;
                from: 5;
                to: 1;
                duration: 2000;
            }
            RotationAnimator {
                target: myBox;
                from: 0;
                to: 360;
                duration: 1000;
            }
            running: true;
        }*/

        /*ScaleAnimator {
            target: myBox;
            from: 5;
            to: 1;
            duration: 2000;
            easing.type: Easing.InOutElastic;
            easing.amplitude: 2.0;
            easing.period: 1.5;
            running: true;
        }
    }*/

    Rectangle {
        id: background;
        anchors.fill: parent;
        color: "blue";

        SequentialAnimation on color
        {
            ColorAnimation { to: "yellow"; duration: 1000 }
            ColorAnimation { to: "red"; duration: 1000 }
            ColorAnimation { to: "blue"; duration: 1000 }
            loops: Animation.Infinite;
        }

        state: "RELEASED";

        states: [
            State {
                name: "PRESSED"
                PropertyChanges { target: background; color: "blue"}
            },
            State {
                name: "RELEASED"
                PropertyChanges { target: background; color: "red"}
            }
        ]

        MouseArea {
            anchors.fill: parent;
            onPressed: background.state = "PRESSED";
            onReleased: background.state = "RELEASED";
        }

        transitions: [
            Transition {
                from: "PRESSED"
                to: "RELEASED"
                ColorAnimation { target: background; duration: 200}
            },
            Transition {
                from: "RELEASED"
                to: "PRESSED"
                ColorAnimation { target: background; duration: 200}
            }
        ]
    }

    Text {
        id: myText;
        text: qsTr("Hello World");
        anchors.centerIn: parent;
        color: "white";
        font.pointSize: 15;
        /*SequentialAnimation on opacity {
                NumberAnimation { to: 0.0; duration: 200}
                NumberAnimation { to: 1.0; duration: 200}
                loops: Animation.Infinite;
            }
        NumberAnimation on rotation {
            from: 0;
            to: 360;
            duration: 2000;
            loops: Animation.Infinite;
        }*/
    }
}

