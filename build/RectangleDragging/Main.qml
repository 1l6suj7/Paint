import QtQuick
import QtQuick.Controls

Window {
    width: 1500
    height: 800
    visible: true
    title: qsTr("绘图")

    Rectangle {
        anchors.fill: parent
        color: "#FFFFCC"
    }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: mainPage
    }

    Component {
        id: mainPage

        MainPage {
            onStart: { stack.push(paintPage); }
        }
    }

    Component {
        id: paintPage

        PaintPage {
            onExit: { stack.pop(); }
        }
    }
}
