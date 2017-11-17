import QtQuick 2.9
import QtQuick.Controls 1.2
TableView {
    id: tableView
    frameVisible: false
    sortIndicatorVisible: true
    model:  sourceModel
    signal loadUrl(string url)
    function onClicked(index) {
        tableView.loadUrl(sourceModel.get(index).url)
    }

    Component.onCompleted:
    {
        tableView.doubleClicked.connect(tableView.onClicked);
    }

    TableViewColumn {
        id: titleColumn
        title: "Title"
        role: "title"
        movable: false
        resizable: false
        width: tableView.viewport.width - authorColumn.width

    }

    TableViewColumn {
        id: authorColumn
        title: "URL"
        role: "url"
        movable: false
        resizable: false
        width: tableView.viewport.width / 3
    }

    ListModel {
        id: sourceModel
        ListElement {
            title: "Google"
            url: "http://google.co.in"
        }

        ListElement {
            title: "Herbert West—Reanimator"
            url: "http://yahoo.co.in"
        }
    }
}
