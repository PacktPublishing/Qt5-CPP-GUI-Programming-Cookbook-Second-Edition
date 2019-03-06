import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480
    height: 550

    MainForm {
        anchors.fill: parent

        button1 {
            Behavior on y { SpringAnimation { spring: 2; damping: 0.2 } }

            onClicked: {
                button1.y = button1.y + (45 * 3)
            }
        }

        button2 {
            Behavior on y { SpringAnimation { spring: 2; damping: 0.2 } }

            onClicked: {
                button2.y = button2.y + (45 * 3)
            }
        }

        button3 {
            Behavior on y { SpringAnimation { spring: 2; damping: 0.2 } }

            onClicked: {
                button3.y = button3.y + (45 * 3)
            }
        }

        fan {
            RotationAnimation on rotation {
                id: anim01
                loops: Animation.Infinite
                from: 0
                to: -360
                duration: 1000
            }
        }

        mouseArea1 {
            onPressed: {
                if (anim01.paused)
                    anim01.resume()
                else
                    anim01.pause()
            }
        }

        rectangle2 {
            id: rect2
            state: "BLUE"
            states: [
                State {
                    name: "BLUE"
                    PropertyChanges {
                        target: rect2
                        color: "blue"
                    }
                },
                State {
                    name: "RED"
                    PropertyChanges {
                        target: rect2
                        color: "red"
                    }
                }
            ]
        }

        mouseArea2 {

            SequentialAnimation on x {
                loops: Animation.Infinite
                PropertyAnimation { to: 150; duration: 1500 }
                PropertyAnimation { to: 50; duration: 500 }
            }

            onClicked: {
                if (rect2.state == "BLUE")
                    rect2.state = "RED"
                else
                    rect2.state = "BLUE"
            }
        }
    }
}
