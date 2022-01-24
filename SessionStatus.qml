import QtQuick 2.0
Column{
    property int fontPixelSize: 12
    function updateSteps(num){
        stepsTxt.text = num
    }
    function updateFlipped(str){
        flippedTxt.text = str
    }
    function updateTime(str){
        timeTxt.text = str
    }
    Text{
        text: "Flipped: "
        font.pixelSize: fontPixelSize
        anchors{
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: -(flippedTxt.width)/2
        }
        Text{
            id: flippedTxt
            font.pixelSize: fontPixelSize
            anchors{
                left: parent.right
            }
            text: ""
        }
    }
    Text {
        text: "Steps: "
        font.pixelSize: fontPixelSize
        anchors{
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: -(stepsTxt.width)/2
        }
        Text{
            id: stepsTxt
            font.pixelSize: fontPixelSize
            anchors{
                left: parent.right
            }
            text: ""
        }
    }
    Text {
        text: "Time: "
        font.pixelSize: fontPixelSize
        anchors{
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: -(timeTxt.width)/2
        }
        Text{
            id: timeTxt
            font.pixelSize: fontPixelSize
            anchors{
                left: parent.right
            }
            text: ""
        }
    }
}
