//Dummy UI , need to tweak later

import QtQuick 2.9
import QtQuick.Controls 2.2
import QtWebEngine 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        id:news_scroller;
        anchors.left:parent.left;
        anchors.top:parent.top;
        anchors.bottom: parent.bottom
        width: 150;

        ListView {
            width: parent.width
            model: 100
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: parent.width
            }
        }
    }
    WebEngineView {
        anchors.left:news_scroller.right;
        anchors.top:parent.top;
        anchors.bottom: parent.bottom
        anchors.right: parent.right;
        url: "http://www.qt.io"
    }



}
