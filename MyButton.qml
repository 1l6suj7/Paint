import QtQuick

Rectangle {
    id: but
    border.width: 3
    border.color: "black"
    width: 200
    height: 90
    color: "transparent"
    property int size: 30
    property string txt
    signal clicked

    Rectangle {
        id: inner
        anchors.fill: parent
        anchors.margins: but.border.width
        color: "lightsteelblue"
    }

    Text {
        anchors.centerIn: parent
        text: but.txt
        font.family: "黑体"
        font.pixelSize: but.size
    }

    PropertyAnimation {
        id: hoveredAnm
        target: inner
        property: "opacity"
        to: 0.4
        duration: 100
    }

    PropertyAnimation {
        id: unHoveredAnm
        target: inner
        property: "opacity"
        to: 1
        duration: 100
    }

    ColorAnimation {
        id: pressedAnm
        target: inner
        property: "color"
        to: "steelblue"
    }

    ColorAnimation {
        id: unpressedAnm
        target: inner
        property: "color"
        to: "lightsteelblue"
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent

        onContainsMouseChanged: {
            if (containsMouse) {
                hoveredAnm.start();
            } else {
                unHoveredAnm.start();
            }
        }

        onPressedChanged: {
            if (pressed) {
                pressedAnm.start();
            } else {
                unpressedAnm.start();
            }
        }

        onClicked: {
            but.clicked();
        }
    }
}
