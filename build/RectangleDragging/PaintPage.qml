import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import GraphicLogic 1.0

Item {
    id: root
    signal exit
    property string drawMode: "move"
    property int selectedGraphicIndex: -1;

    onDrawModeChanged: {
        drawingCanvas.drawMode = drawMode;
        toolsPanel.drawMode = drawMode;
        rightPanel.drawMode = drawMode;
    }

    onSelectedGraphicIndexChanged: {
        drawingCanvas.selectedGraphicIndex = selectedGraphicIndex
        toolsPanel.selectedGraphicIndex = selectedGraphicIndex
        rightPanel.selectedGraphicIndex = selectedGraphicIndex
    }

    FileDialog {
        id: saveFileDlg
        title: "保存文件"
        nameFilters: ["JSON 文件 (*.json)"]
        fileMode: FileDialog.SaveFile
        onAccepted: {
            GraphicLogic.saveAsFile(saveFileDlg.currentFile);
        }
    }

    Item {
        id: menu
        height: 80
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        Row {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            spacing: 15
            anchors.leftMargin: 15
            MyButton {
                height: 60
                width: 120
                txt: "保存"

                onClicked: {
                    saveFileDlg.open();
                }
            }

            MyButton {
                height: 60
                width: 120
                txt: "返回"

                onClicked: {
                    if (GraphicLogic.getIsSave()) {
                        root.exit();
                    } else {
                        notSaveDlg.show();
                    }
                }
            }

            MyDialog {
                id: notSaveDlg
                tit: "提示"
                txt: "文件未保存，是否返回？"
                mode: "AcceptAndCancel"
                width: 400
                height: 250

                onAccept: {
                    root.exit();
                    GraphicLogic.clearAllGraphics();
                }
            }
        }

        Rectangle {
            x: 0
            y: menu.height - 2
            width: menu.width
            height: 2
            border.width: 1
            border.color: "black"
        }
    }

    GCanvas {
        id: drawingCanvas
        anchors.left: toolsPanel.right
        anchors.right: rightPanel.left
        anchors.top: menu.bottom
        anchors.bottom: parent.bottom
        drawMode: root.drawMode
        selectedGraphicIndex: root.selectedGraphicIndex

        onUpdate: {
            console.log("画布更新");
            root.selectedGraphicIndex = drawingCanvas.selectedGraphicIndex;
            rightPanel.updateLayerList();
        }
    }

    ToolsPanel {
        id: toolsPanel
        anchors.left: parent.left
        anchors.top: menu.bottom
        anchors.bottom: parent.bottom
        width: 140
        drawMode: root.drawMode
        selectedGraphicIndex: root.selectedGraphicIndex

        onUpdate: {
            console.log("工具面板更新");
            root.drawMode = toolsPanel.drawMode
            root.selectedGraphicIndex = toolsPanel.selectedGraphicIndex
            drawingCanvas.requestPaint();
        }
    }

    RightPanel {
        id: rightPanel
        anchors.top: menu.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 250
        drawMode: root.drawMode
        selectedGraphicIndex: root.selectedGraphicIndex

        onUpdate: {
            console.log("右面板更新");
            root.selectedGraphicIndex = rightPanel.selectedGraphicIndex
            drawingCanvas.requestPaint();
        }
    }
}
