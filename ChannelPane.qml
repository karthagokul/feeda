import QtQuick 2.0
import QtQuick.Controls 1.5

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
