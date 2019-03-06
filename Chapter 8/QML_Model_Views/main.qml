import QtQuick 2.9
import QtQuick.Window 2.3

Window {
    visible: true
    width: 480
    height: 480

    MainForm {
        anchors.fill: parent

        MouseArea {
            onPressed: row1.opacity = 0.5
            onReleased: row1.opacity = 1.0
        }
    }
}
