import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    visible: true;
    width: 420;
    height: 380;
    Rectangle {
            anchors.fill: parent;
            color: "white";
        }

    AnimatedSprite {
            id: sprite;
            width: 128;
            height: 128;
            x: -128;
            y: parent.height / 2;
            source: "qrc:///horse_1.png";
            frameCount: 11;
            frameWidth: 128;
            frameHeight: 128;
            frameRate: 25;
            loops: Animation.Infinite;
            running: true;

            NumberAnimation {
                target: sprite;
                property: "x";
                from: -128;
                to: 512;
                duration: 3000;
                loops: Animation.Infinite;
                running: true;
            }
        }

    MouseArea {
            anchors.fill: parent
            onClicked: {
                if (sprite.paused)
                    sprite.resume();
                else
                    sprite.pause();
            }
    }
}

