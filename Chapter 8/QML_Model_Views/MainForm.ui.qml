import QtQuick 2.9

Rectangle {
    id: rectangle1

    property alias listView1: listView1
    property double sizeMultiplier: width / 480

    ListView {
        id: listView1
        y: 0
        height: 160
        orientation: ListView.Vertical
        boundsBehavior: Flickable.StopAtBounds
        anchors.fill: parent
        delegate: Item {
            width: 80 * sizeMultiplier
            height: 55 * sizeMultiplier
            Row {
                id: row1
                Rectangle {
                    width: listView1.width
                    height: 55 * sizeMultiplier
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#ffffff" }
                        GradientStop { position: 1.0; color: "#f0f0f0" }
                    }
                    opacity: 1.0

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                    }

                    Image {
                        anchors.verticalCenter: parent.verticalCenter
                        x: 15 * sizeMultiplier
                        width: 30 * sizeMultiplier
                        height: 30 * sizeMultiplier
                        source: icon
                    }

                    Text {
                        text: title
                        font.family: "Courier"
                        font.pixelSize: 17 * sizeMultiplier
                        x: 55 * sizeMultiplier
                        y: 10 * sizeMultiplier
                    }

                    Text {
                        text: subtitle
                        font.family: "Verdana"
                        font.pixelSize: 9 * sizeMultiplier
                        x: 55 * sizeMultiplier
                        y: 30 * sizeMultiplier
                    }

                    Image {
                        anchors.verticalCenter: parent.verticalCenter
                        x: parent.width - 35 * sizeMultiplier
                        width: 30 * sizeMultiplier
                        height: 30 * sizeMultiplier
                        source: "arrow.png"
                    }
                }
            }
        }
        model: ListModel {
            ListElement {
                title: "Home"
                subtitle: "Go back to dashboard"
                icon: "home.png"
            }

            ListElement {
                title: "Map"
                subtitle: "Help navigate to your destination"
                icon: "map.png"
            }

            ListElement {
                title: "Profile"
                subtitle: "Customize your profile picture"
                icon: "profile.png"
            }

            ListElement {
                title: "Search"
                subtitle: "Search for nearby places"
                icon: "search.png"
            }

            ListElement {
                title: "Settings"
                subtitle: "Customize your app settings"
                icon: "settings.png"
            }
        }
    }
}
