import QtQuick 2.12
GridView{
    id: root
//    Rectangle{
//        anchors.fill: parent
//        color: "red"
//    }

    width: 100
    height: width
    signal pressed(int pos)
    property int rows: 10
    property int cols: 10
    property double cardSize: 0.9
//    property bool flipped: false
//    property string image: ""
    property bool blockField: false
    interactive: false
    cellWidth: width/cols
    cellHeight: height/rows
    MouseArea{
        id:blockingArea
        enabled: blockField
        anchors.fill: parent
    }
    delegate: Item{
        width: cellWidth
        height: width
        Card{
            width: cellWidth*cardSize
            anchors.centerIn: parent
            _fliped: flipped
            _source: image
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    root.pressed(index)
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
