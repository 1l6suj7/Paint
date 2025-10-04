import QtQuick
import QtQuick.Dialogs
import GraphicLogic 1.0

Item {
    id: root
    signal start

    Row {
        anchors.centerIn: parent
        spacing: 15

        MyButton {
            txt: "新建"

            onClicked: {
                root.start();
            }
        }

        MyButton {
            txt: "读取文件"

            onClicked: {
                openFileDlg.open();
            }
        }

        FileDialog {
            id: openFileDlg
            title: "读取文件"
            nameFilters: ["JSON 文件 (*.json)"]
            fileMode: FileDialog.OpenFile
            onAccepted: {
                GraphicLogic.loadFromFile(openFileDlg.currentFile);
            }
        }

        Connections {
            target: GraphicLogic

            function onLoadSucceeded() {
                start();
            }

            function onLoadFailed() {
                loadFailDlg.show();
            }
        }

        MyDialog {
            id: loadFailDlg
            tit: "错误"
            txt: "文件读取错误"
        }
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        anchors.left: parent.left
        anchors.leftMargin: 25
        text: "version: 0.1"
        font.pixelSize: 30
        font.family: "Consola"
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.right: parent.right
        anchors.rightMargin: 40
        text: "By 1l6suj7"
        font.pixelSize: 40
        font.family: "黑体"
        font.bold: true
    }
}
