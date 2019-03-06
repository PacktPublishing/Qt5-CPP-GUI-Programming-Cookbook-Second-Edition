import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 360
    height: 360

    MainForm {
        anchors.fill: parent
        loginButton.onClicked: {
            messageDialog.text = "Username is " + userInput.text + " and password is " + passInput.text
            messageDialog.visible = true
        }
    }

    MessageDialog {
        id: messageDialog
        title: "Fake login"
        text: ""
        onAccepted: {
            console.log("You have clicked the login button")
            Qt.quit()
        }
    }
}
