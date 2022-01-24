import QtQuick 2.12

Rectangle{
    id: root
    height: 600
    width: 400
    property alias model: listModel
    property string message: ""
    property int fontPixelSize: 12
    signal backPressed()
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

        MyButton{
            id:backBt
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                leftMargin: parent.width*0.15
                rightMargin: parent.width*0.15
                bottomMargin: parent.height*0.1
            }
            txt:"back"
            height: parent.height*0.15
            onPressed: {
                root.backPressed()
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
