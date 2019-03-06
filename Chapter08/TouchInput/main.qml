import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true

    MainForm {
        anchors.fill: parent

        property int prevPointX: 0
        property int prevPointY: 0
        property int curPointX: 0
        property int curPointY: 0

        property int prevDistX: 0
        property int prevDistY: 0
        property int curDistX: 0
        property int curDistY: 0

        property int tuxWidth: tux.width
        property int tuxHeight: tux.height

        touchArea.onPressed:
        {
            if (touchArea.touchPoints[1].pressed)
            {
                if (touchArea.touchPoints[1].x < touchArea.touchPoints[0].x)
                    prevDistX = touchArea.touchPoints[1].x - touchArea.touchPoints[0].x
                else
                    prevDistX = touchArea.touchPoints[0].x - touchArea.touchPoints[1].x

                if (touchArea.touchPoints[1].y < touchArea.touchPoints[0].y)
                    prevDistY = touchArea.touchPoints[1].y - touchArea.touchPoints[0].y
                else
                    prevDistY = touchArea.touchPoints[0].y - touchArea.touchPoints[1].y

                tuxWidth = tux.width
                tuxHeight = tux.height
            }
        }

        touchArea.onUpdated:
        {
            if (!touchArea.touchPoints[1].pressed)
            {
                tux.x += touchArea.touchPoints[0].x - touchArea.touchPoints[0].previousX
                tux.y += touchArea.touchPoints[0].y - touchArea.touchPoints[0].previousY
            }
            else
            {
                if (touchArea.touchPoints[1].x < touchArea.touchPoints[0].x)
                    curDistX = touchArea.touchPoints[1].x - touchArea.touchPoints[0].x
                else
                    curDistX = touchArea.touchPoints[0].x - touchArea.touchPoints[1].x

                if (touchArea.touchPoints[1].y < touchArea.touchPoints[0].y)
                    curDistY = touchArea.touchPoints[1].y - touchArea.touchPoints[0].y
                else
                    curDistY = touchArea.touchPoints[0].y - touchArea.touchPoints[1].y

                tux.width = tuxWidth + prevDistX - curDistX
                tux.height = tuxHeight + prevDistY - curDistY
            }
        }
    }
}
