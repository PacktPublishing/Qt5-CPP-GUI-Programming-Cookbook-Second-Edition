import QtQuick 2.11
import QtQuick.Window 2.11

Window
{
    id: myWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Canvas
    {
        id: myCanvas
        width: myWindow.width
        height: myWindow.height

        onImageLoaded: requestPaint();

        onPaint:
        {
            var context = getContext('2d')

            context.fillStyle = 'white'
            context.fillRect(0, 0, width, height)

            context.lineWidth =  2
            context.strokeStyle = 'black'

            // Draw cross
            context.beginPath()
            context.moveTo(50, 50)
            context.lineTo(100, 100)
            context.closePath()
            context.stroke()

            context.beginPath()
            context.moveTo(100, 50)
            context.lineTo(50, 100)
            context.closePath()
            context.stroke()

            // Draw tick
            context.beginPath()
            context.moveTo(150, 90)
            context.lineTo(158, 100)
            context.closePath()
            context.stroke()

            context.beginPath()
            context.moveTo(180, 100)
            context.lineTo(210, 50)
            context.closePath()
            context.stroke()

            // Draw triangle
            context.lineWidth = 4
            context.strokeStyle = "red"
            context.fillStyle = "salmon"

            context.beginPath()
            context.moveTo(50,150)
            context.lineTo(150,150)
            context.lineTo(50,250)
            context.closePath()
            context.fill()
            context.stroke()

            // Draw circle
            context.lineWidth = 4
            context.strokeStyle = "blue"
            context.fillStyle = "steelblue"

            var pi = 3.141592653589793

            context.beginPath()
            context.arc(220, 200, 60, 0, pi, true)
            context.closePath()
            context.fill()
            context.stroke()

            context.beginPath()
            context.arc(220, 280, 60, 0, 2 * pi, true)
            context.closePath()
            context.fill()
            context.stroke()

            // Draw image
            context.drawImage("tux.png", 280, 10, 150, 174)
        }
    }
}
