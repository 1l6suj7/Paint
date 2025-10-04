import QtQuick
import QtQuick.Controls
import GraphicLogic 1.0

Item {
    id: root
    property int selectedGraphicIndex
    property string drawMode
    signal update()
    signal requestCanvas()

    onSelectedGraphicIndexChanged: {
        updatePropertyList();
        updateLayerList();
    }

    function getSelectedGraphicProperties() {
        if (selectedGraphicIndex < 0) return [];

        var graphicInfo = GraphicLogic.getInfo(selectedGraphicIndex);
        if (!graphicInfo) return [];

        var properties = [];
        properties.push({name: "类型", value: graphicInfo.type || "未知"});
        properties.push({name: "图层", value: graphicInfo.z || 1});

        switch(graphicInfo.type) {
            case "rectangle":
                properties.push({name: "X", value: Math.round(graphicInfo.x || 0)});
                properties.push({name: "Y", value: Math.round(graphicInfo.y || 0)});
                properties.push({name: "宽度", value: Math.round(graphicInfo.width || 0)});
                properties.push({name: "高度", value: Math.round(graphicInfo.height || 0)});
                break;
            case "circle":
                properties.push({name: "中心X", value: Math.round(graphicInfo.centerX || 0)});
                properties.push({name: "中心Y", value: Math.round(graphicInfo.centerY || 0)});
                properties.push({name: "半径", value: Math.round(graphicInfo.radius || 0)});
                break;
            case "line":
                properties.push({name: "起点X", value: Math.round(graphicInfo.startX || 0)});
                properties.push({name: "起点Y", value: Math.round(graphicInfo.startY || 0)});
                properties.push({name: "终点X", value: Math.round(graphicInfo.endX || 0)});
                properties.push({name: "终点Y", value: Math.round(graphicInfo.endY || 0)});
                break;
            case "triangle":
                properties.push({name: "点1", value: "(" + Math.round(graphicInfo.points[0]) + ", " + Math.round(graphicInfo.points[1]) + ")"});
                properties.push({name: "点2", value: "(" + Math.round(graphicInfo.points[2]) + ", " + Math.round(graphicInfo.points[3]) + ")"});
                properties.push({name: "点3", value: "(" + Math.round(graphicInfo.points[4]) + ", " + Math.round(graphicInfo.points[5]) + ")"});
                break;
            case "hexagon":
                if (graphicInfo.points && graphicInfo.points.length >= 2) {
                    for (var i = 0; i < graphicInfo.points.length; i += 2) {
                        properties.push({
                            name: "点" + (i/2 + 1),
                            value: "(" + Math.round(graphicInfo.points[i]) + ", " + Math.round(graphicInfo.points[i+1]) + ")"
                        });
                    }
                }
                break;
        }

        return properties;
    }

    function getModeText(mode) {
        switch(mode) {
            case "move": return "移动/选择";
            case "line": return "直线";
            case "rectangle": return "矩形";
            case "circle": return "圆形";
            case "triangle": return "三角形";
            case "hexagon": return "六边形";
            default: return "未知";
        }
    }

    function updatePropertyList() {
        propertiesRepeater.model = getSelectedGraphicProperties();
    }

    function updateLayerList() {
        layerList.model = GraphicLogic.getLayerList();
    }

    Item {
        id: info
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: root.height / 2

        Text {
            id: infoTitle
            text: "属性信息"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 10
            anchors.leftMargin: 15
            font.family: "黑体"
            font.pixelSize: 18
            font.bold: true
        }

        ScrollView {
            id: infoScrollView
            anchors.top: infoTitle.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 10

            Column {
                id: infoColumn
                width: infoScrollView.width
                spacing: 8

                Text {
                    id: noSelectionText
                    text: "未选择任何图形"
                    font.family: "黑体"
                    font.pixelSize: 14
                    color: "gray"
                    visible: selectedGraphicIndex === -1
                }

                // 当前绘制模式显示
                Row {
                    spacing: 10
                    Text {
                        text: "当前模式："
                        font.family: "黑体"
                        font.pixelSize: 14
                    }
                    Text {
                        text: root.getModeText(drawMode)
                        font.family: "黑体"
                        font.pixelSize: 14
                        color: "blue"
                        font.bold: true
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 1
                    color: "lightgray"
                    visible: selectedGraphicIndex >= 0
                }

                // 选中图形的属性信息
                Column {
                    id: selectedGraphicInfo
                    width: parent.width
                    spacing: 5
                    visible: selectedGraphicIndex >= 0

                    Text {
                        text: "选中图形属性："
                        font.family: "黑体"
                        font.pixelSize: 14
                        font.bold: true
                    }

                    Repeater {
                        id: propertiesRepeater
                        model: root.getSelectedGraphicProperties()

                        Row {
                            spacing: 10
                            Text {
                                text: modelData.name + ":"
                                font.family: "黑体"
                                font.pixelSize: 12
                                width: 60
                            }
                            Text {
                                text: modelData.value
                                font.family: "黑体"
                                font.pixelSize: 12
                                color: "darkblue"
                            }
                        }
                    }

                    // 图层操作按钮
                    Text {
                        text: "图层操作："
                        font.family: "黑体"
                        font.pixelSize: 12
                        font.bold: true
                    }

                    Row {
                        spacing: 5
                        MyButton {
                            width: 60
                            height: 28
                            txt: "置顶"
                            size: 20
                            onClicked: {
                                if (selectedGraphicIndex >= 0) {
                                    GraphicLogic.moveGraphicToTop(selectedGraphicIndex);
                                    root.update();
                                    root.updateLayerList();
                                    root.requestCanvas();
                                }
                            }
                        }

                        MyButton {
                            width: 60
                            height: 28
                            txt: "上移"
                            size: 20
                            onClicked: {
                                if (selectedGraphicIndex >= 0) {
                                    GraphicLogic.moveGraphicUp(selectedGraphicIndex);
                                    root.update();
                                    root.updateLayerList();
                                    root.requestCanvas();
                                }
                            }
                        }
                    }

                    Row {
                        spacing: 5
                        MyButton {
                            width: 60
                            height: 28
                            txt: "下移"
                            size: 20
                            onClicked: {
                                if (selectedGraphicIndex >= 0) {
                                    GraphicLogic.moveGraphicDown(selectedGraphicIndex);
                                    root.update();
                                    root.updateLayerList();
                                    root.requestCanvas();
                                }
                            }
                        }

                        MyButton {
                            width: 60
                            height: 28
                            txt: "置底"
                            size: 20
                            onClicked: {
                                if (selectedGraphicIndex >= 0) {
                                    GraphicLogic.moveGraphicToBottom(selectedGraphicIndex);
                                    root.update();
                                    root.updateLayerList();
                                    root.requestCanvas();
                                }
                            }
                        }
                    }

                    Rectangle {
                        width: parent.width
                        height: 1
                        color: "lightgray"
                    }

                    Row {
                        spacing: 10
                        MyButton {
                            width: 80
                            height: 30
                            txt: "删除"
                            size: 20
                            onClicked: {
                                if (selectedGraphicIndex >= 0) {
                                    GraphicLogic.deleteGraphic(selectedGraphicIndex);
                                    selectedGraphicIndex = -1;
                                    root.update();
                                    root.updateLayerList();
                                    root.requestCanvas();
                                }
                            }
                        }

                        MyButton {
                            width: 100
                            height: 30
                            txt: "取消选择"
                            size: 20
                            onClicked: {
                                selectedGraphicIndex = -1;
                                root.update();
                                root.updateLayerList();
                                root.requestCanvas();
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: rec1
        anchors.top: info.bottom
        height: 2
        anchors.left: parent.left
        anchors.right: parent.right
        border.width: 1
        border.color: "black"
    }

    Item {
        id: layer
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rec1.bottom

        Text {
            id: layerTitle
            text: "图层"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 10
            anchors.leftMargin: 15
            font.family: "黑体"
            font.pixelSize: 18
            font.bold: true
        }

        ListView {
            id: layerList
            z: 0
            clip: true
            anchors.top: layerTitle.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            boundsBehavior: Flickable.StopAtBounds
            spacing: 2
            focus: true  // 启用ListView焦点
            keyNavigationEnabled: false  // 禁用键盘导航避免冲突

            model: GraphicLogic.getLayerList()

            // MouseArea {
            //     anchors.fill: parent
            //     propagateComposedEvents: true

            //     onClicked: {
            //         if (selectedGraphicIndex === -1) return;
            //         selectedGraphicIndex = -1;
            //         root.update();
            //         mouse.accepted = false;
            //     }
            // }

            delegate: FocusScope {
                width: layerList.width
                height: 50

                Rectangle {
                    id: rect1
                    width: layerList.width
                    height: 50
                    border.color: (modelData.index === selectedGraphicIndex) ? "blue" : "grey"
                    border.width: (modelData.index === selectedGraphicIndex) ? 2 : 1
                    color: (modelData.index === selectedGraphicIndex) ? "lightblue" : "white"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            if (selectedGraphicIndex === modelData.index) return;
                            selectedGraphicIndex = modelData.index;
                            root.update();
                            root.updateLayerList();
                            root.requestCanvas();
                        }
                    }

                    Row {
                        anchors.left: parent.left
                        anchors.leftMargin: 8
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 8

                        // 可见性切换按钮
                        Rectangle {
                            width: 20
                            height: 20
                            border.color: "black"
                            border.width: 1
                            color: modelData.visible ? "lightgreen" : "lightgray"

                            Text {
                                anchors.centerIn: parent
                                text: modelData.visible ? "●" : "○"
                                font.pixelSize: 12
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    GraphicLogic.setGraphicVisibility(modelData.index, !modelData.visible);
                                    root.update();
                                    root.requestCanvas();
                                    root.updateLayerList();
                                }
                            }
                        }

                        // 图层信息
                        Column {
                            spacing: 5
                            TextField {
                                id: layerTextField
                                width: 120
                                height: 20
                                
                                text: modelData.name || "未命名"
                                font.family: "黑体"
                                font.pixelSize: 12
                                font.bold: true
                                verticalAlignment: Text.AlignVCenter
                                selectByMouse: true
                                
                                property string savedText: text
                                
                                // 每次数据更新时同步savedText
                                onTextChanged: {
                                    if (!activeFocus) {
                                        savedText = text;
                                    }
                                }
                                
                                onEditingFinished: {
                                    handleTextChange();
                                }
                                
                                onActiveFocusChanged: {
                                    if (activeFocus) {
                                        savedText = text;
                                        selectAll();
                                    } else {
                                        handleTextChange();
                                    }
                                }
                                
                                function handleTextChange() {
                                    if (text.trim() === "") {
                                        text = savedText;
                                    } else if (text !== savedText) {
                                        GraphicLogic.setGraphicName(modelData.index, text);
                                        savedText = text;
                                        root.updateLayerList();
                                    }
                                }
                                
                                Keys.onReturnPressed: {
                                    parent.focus = true; // 将焦点转移到父元素
                                }
                                
                                Keys.onEscapePressed: {
                                    text = savedText;
                                    parent.focus = true; // 将焦点转移到父元素
                                }
                            }
                            Text {
                                text: "图层 " + GraphicLogic.getNo(modelData.index)
                                font.family: "黑体"
                                font.pixelSize: 10
                                color: "gray"
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 2
        border.width: 1
        border.color: "black"
    }
}
