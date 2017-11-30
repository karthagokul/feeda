import QtQuick 2.9
import QtQuick.Controls 1.2


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hi")

    function connectSignalsAndSlots()
    {
        //storypane.loadUrl.connect(storyview.onLoadUrlRequest);
    }

    Component.onCompleted:
    {
        connectSignalsAndSlots()
    }

    StoryPane
    {
        id:storypane;
        height: 200;
        anchors.top:parent.top;
        anchors.left:channelpane.right;
        anchors.right: parent.right;
        anchors.margins: 2;
    }

    ChannelPane
    {
        id:channelpane;
        anchors.top:parent.top
        anchors.left:parent.left
        width:parent.width/4
        anchors.bottom: parent.bottom
        anchors.margins: 2;
    }

    StoryPreview
    {
        id:storyview;
        anchors.left:channelpane.right;
        anchors.top:storypane.bottom;
        anchors.bottom: parent.bottom
        anchors.right: parent.right;
        anchors.margins: 2;

        function onLoadUrlRequest(urlString) {
            //storyview.url=urlString
        }
    }
}
