import QtQuick

Window {
    id: root
    modality: Qt.WindowModal
    property string tit
    property string txt
    property string mode: "Accept"
    signal accept
    signal cancel
    title: tit
    width: 300
    height: 200

    Text {
        anchors.centerIn: parent
        text: txt
        font.family: "黑体"
        font.pixelSize: 30
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.rightMargin: 10
        spacing: 15

        MyButton {
            id: acceptBut
            width: 100
            height: 40
            txt: "确认"
            visible: (mode == "AcceptAndCancel" || mode == "Accept") ? true : false;

            onClicked: {
                root.accept();
                root.close();
            }
        }

        MyButton {
            id: cancelBut
            width: 100
            height: 40
            txt: "取消"
            visible: (mode == "AcceptAndCancel" || mode == "Cancel") ? true : false;

            onClicked: {
                root.cancel();
                root.close();
            }
        }
    }
}
