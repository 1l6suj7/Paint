import QtQuick
import QtQuick.Dialogs
import DraggingLogic 1.0

Item {
    id: root
    signal start

    Row {
        anchors.centerIn: parent
        spacing: 15

        MyButton {
            txt: "新建"

            onClicked: {
                DraggingLogic.setScale(300, 300);
                DraggingLogic.setCoord(1500 / 2 - 150, 800 / 2 - 150);
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
            nameFilters: ["JSON 文件 (*.json)", "所有文件 (*)"]
            fileMode: FileDialog.OpenFile
            onAccepted: {
                DraggingLogic.loadFromFile(openFileDlg.currentFile);
            }
        }

        Connections {
            target: DraggingLogic

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
}
