import QtQuick
import QtQuick.Dialogs
import DraggingLogic 1.0

Item {
    id: root
    signal exit

    FileDialog {
        id: saveFileDlg
        title: "保存文件"
        nameFilters: ["JSON 文件 (*.json)"]
        fileMode: FileDialog.SaveFile
        onAccepted: {
            DraggingLogic.saveAsFile(saveFileDlg.currentFile);
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
                    if (DraggingLogic.getIsSave()) {
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

    Rectangle {
        id: rect
        border.color: "black"
        border.width: 3
        MouseArea {
            anchors.fill: parent
            drag.target: rect
            drag.axis: Drag.XAndYAxis

            onPositionChanged: {
                DraggingLogic.setCoord(rect.x, rect.y);
            }
        }

        Component.onCompleted: {
            var info = DraggingLogic.getInfo();
            rect.width = info["width"];
            rect.height = info["height"];
            rect.x = info["x"];
            rect.y = info["y"];
        }
    }
}
