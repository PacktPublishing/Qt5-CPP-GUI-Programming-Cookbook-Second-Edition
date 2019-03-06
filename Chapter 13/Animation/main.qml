import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    id: window
    visible: true
    width: 650
    height: 650
    title: qsTr("Hello World")

    property int frame: 0;
    onAfterRendering: { frame++; }

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: { frame = 0; }
    }

    Repeater {
        model: 10000
        delegate:
            Image {
                id: tux
                source: "tux.png"
                //sourceSize.width: 50
                //sourceSize.height: 60
                width: 50
                height: 60
                smooth: true
                antialiasing: true
                asynchronous: false

                property double startX: Math.random() * 600;
                property double startY: Math.random() * 600;
                property double endX: Math.random() * 600;
                property double endY: Math.random() * 600;
                property double speed: Math.random() * 3000 + 1000;

                RotationAnimation on rotation{
                    loops: Animation.Infinite
                    from: 0
                    to: 360
                    duration: Math.random() * 3000 + 1000;
                }

                SequentialAnimation {
                    running: true
                    loops: Animation.Infinite

                    ParallelAnimation {
                        NumberAnimation {
                            target: tux
                            property: "x"
                            from: startX
                            to: endX
                            duration: speed
                            easing.type: Easing.InOutQuad
                         }

                         NumberAnimation {
                             target: tux
                             property: "y"
                             from: startY
                             to: endY
                             duration: speed
                             easing.type: Easing.InOutQuad
                          }
                     }

                    ParallelAnimation {
                        NumberAnimation {
                            target: tux
                            property: "x"
                            from: endX
                            to: startX
                            duration: speed
                            easing.type: Easing.InOutQuad
                         }

                         NumberAnimation {
                             target: tux
                             property: "y"
                             from: endY
                             to: startY
                             duration: speed
                             easing.type: Easing.InOutQuad
                          }
                     }
                }
            }
    }

    Text {
        property int frame: 0
        color: "red"
        text: ""
        x: 20
        y: 20
        font.pointSize: 20

        Timer {
            id: fpsTimer
            repeat: true
            interval: 1000
            running: true
            onTriggered: {
                parent.text = "FPS: " + frame + " fps"
            }
        }
    }
}
