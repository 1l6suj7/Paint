import QtQuick

Item {
    id: root
    property string drawMode
    property int selectedGraphicIndex
    signal update

    Column {
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15

        MyButton {
            id: moveBtn
            width: 110
            height: 60
            txt: "移动"
            property bool isSelected: root.drawMode === "move"

            // 选中状态时使用不同颜色
            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "move";
                root.update();
            }
        }

        MyButton {
            id: lineBtn
            width: 110
            height: 60
            txt: "直线"
            property bool isSelected: root.drawMode === "line"

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "line";
                root.selectedGraphicIndex = -1;
                root.update();
            }
        }

        MyButton {
            id: rectBtn
            width: 110
            height: 60
            txt: "矩形"
            property bool isSelected: root.drawMode === "rectangle"

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "rectangle";
                root.selectedGraphicIndex = -1;
                root.update();
            }
        }

        MyButton {
            id: circleBtn
            width: 110
            height: 60
            txt: "圆形"
            property bool isSelected: root.drawMode === "circle"

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "circle";
                root.selectedGraphicIndex = -1;
                root.update();
            }
        }

        MyButton {
            id: triangleBtn
            width: 110
            height: 60
            txt: "三角形"
            property bool isSelected: root.drawMode === "triangle"

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "triangle";
                root.selectedGraphicIndex = -1;
                root.update();
            }
        }

        MyButton {
            id: hexagonBtn
            width: 110
            height: 60
            txt: "六边形"
            property bool isSelected: root.drawMode === "hexagon"

            Rectangle {
                anchors.fill: parent
                anchors.margins: 3
                color: parent.isSelected ? "lightblue" : "transparent"
                opacity: 0.3
                visible: parent.isSelected
            }

            onClicked: {
                root.drawMode = "hexagon";
                root.selectedGraphicIndex = -1;
                root.update();
            }
        }
    }

    Rectangle {
        x: root.width - 2
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 2
        border.width: 1
        border.color: "black"
    }
}
