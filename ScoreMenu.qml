import QtQuick 2.12

Rectangle{
    height: 600
    width: 400
    property alias model: listModel
    property string message: ""
    property int fontPixelSize: 12
    onVisibleChanged: {
        if(visible===false){
            listModel.clear()
        }
    }
    Text {
        text: message
        anchors{
            bottom: listview.top
            bottomMargin: height
            horizontalCenter: parent.horizontalCenter
        }
        font.pixelSize: fontPixelSize
    }
    ListView{
        id:listview
        anchors{
            fill:parent
            leftMargin: parent.width*0.2
            rightMargin: parent.width*0.2
            topMargin: parent.height*0.2
        }
        spacing: height*0.05
        interactive: false
        delegate: Column{
            width: listview.width
            Text {
                id: sizetxt
                text: "Size: "+size+"x"+size
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: fontPixelSize
            }
            Text {
                id: stepstxt
                text: "Steps: "+steps
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: fontPixelSize
            }
            Text {
                id: timetxt
                text: "Time: "+time
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: fontPixelSize
            }
        }
        model:ListModel{
            id:listModel
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/
