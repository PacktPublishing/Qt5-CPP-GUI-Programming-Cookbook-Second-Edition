import QtQuick 2.4
import QtQuick.Window 2.2
import MyClassLib 1.0

Window {
    visible: true
    width: 480
    height: 320

    MyClass
    {
        id: myclass
    }

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
        Component.onCompleted: myclass.setMyObject(messageText);
    }
}
