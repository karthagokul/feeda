//Dummy UI , need to tweak later

import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls 1.5
import QtWebEngine 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    Component.onCompleted:
    {
        storypane.loadUrl.connect(storyview.onLoadUrlRequest);
    }

    StoryPane
    {
        id:storypane;
        anchors.top:parent.top;
        anchors.left:parent.left;
        anchors.right: parent.right;
        height: 200;
    }

    WebEngineView {
        id:storyview;
        anchors.left:parent.left;
        anchors.top:storypane.bottom;
        anchors.bottom: parent.bottom
        anchors.right: parent.right;
        //url: "http://www.qt.io"

        function onLoadUrlRequest(urlString) {
            console.log("Sending to URL: " + urlString)
            storyview.url=urlString
        }
    }

    TreeView {
        TableViewColumn {
            title: "Name"
            role: "fileName"
            width: 300
        }
        TableViewColumn {
            title: "Permissions"
            role: "filePermissions"
            width: 100
        }
        model:0
    }

}
