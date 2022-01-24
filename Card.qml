import QtQuick 2.0

Rectangle{
    id: root
    width: 40
    height: width
    property string _source: ""
    property bool _fliped: false
    signal taped(int index)
    color: flipped?"white":"orange"
    Image {
        id: img
        anchors.fill: parent
        visible: flipped
        source: image
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}D{i:1}
}
##^##*/
