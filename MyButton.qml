import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Button{
    id: root
    height: 40
    width: 60
    property int radius: height/4
    property string txt: ""
    background: Rectangle{
        radius: height/4
        color: "lightgray"
        Text {
            text: root.txt
            anchors.centerIn: parent
        }
    }
}
