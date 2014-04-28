import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    ListView {
        width: 100; height: 100

        model: myModel
        delegate: Rectangle {
            height: 25
            width: 100
            Text { text: modelData }
        }
    }
}
