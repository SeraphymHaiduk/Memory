import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
Rectangle{
    id: root
    height: 600
    width: 400
    signal startNewGame(int size)
    property int checkedSize:10
    signal cancelPressed()
    Text {
        text: "New Game"
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: parent.height*0.05
        }
    }
    Text{
        id:difficultyTxt
        text: "Difficulty"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: parent.height*0.15
        }
    }
    ColumnLayout {
        id: layout
        anchors{
            top: difficultyTxt.bottom
            topMargin: difficultyTxt.height
            left: parent.left
            leftMargin: parent.width*0.2
            right: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: parent.height*0.2
        }
            RadioButton{
                id: x4txt
                text: "4x4"
                Layout.alignment: Qt.AlignLeft
                Layout.fillHeight: true
                onCheckedChanged: {
                    if(checked){
                        checkedSize = 4
                    }
                }
            }
            RadioButton{
                id: x6txt
                text: "6x6"
                Layout.alignment: Qt.AlignLeft
                Layout.fillHeight: true
                onCheckedChanged: {
                    if(checked){
                        checkedSize = 6
                    }
                }
            }
            RadioButton{
                id: x8txt
                text: "8x8"
                Layout.alignment: Qt.AlignLeft
                Layout.fillHeight: true
                onCheckedChanged: {
                    if(checked){
                        checkedSize = 8
                    }
                }
            }
            RadioButton{
                id: x10txt
                text: "10x10"
                Layout.alignment: Qt.AlignLeft
                Layout.fillHeight: true
                onCheckedChanged: {
                    if(checked){
                        checkedSize = 10
                    }
                }
                checked: true
            }
    }
    ListView{
        id: columnRight
        interactive: false
        anchors{
            top: difficultyTxt.bottom
            topMargin: difficultyTxt.height
            left: parent.horizontalCenter
            right: parent.right
            rightMargin: parent.width*0.2
            bottom: parent.bottom
            bottomMargin: parent.height*0.2
        }
        model:ListModel{
            id: listModel
            ListElement{rows_count: 4; cols_count: 4}
            ListElement{rows_count: 6; cols_count: 6}
            ListElement{rows_count: 8; cols_count: 8}
            ListElement{rows_count: 10; cols_count: 10}
        }
        spacing: height*1/15
        delegate:
            Field{
                width: columnRight.height/5
                height: columnRight.height/5
                rows: rows_count
                cols: cols_count
                cardSize: 0.7
                model: ListModel{
                    id:gridModel
                }
                Component.onCompleted: {
                    for(var i = 0; i < rows_count; i++){
                        for(var j = 0; j < cols_count; j++){
                            gridModel.append({image:"",flipped:0})
                        }
                    }
                }
            }
    }
    RowLayout{
        anchors{
            top:layout.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            margins: parent.height*0.04
        }
        MyButton{
            Layout.fillHeight: true
            Layout.fillWidth: true
            txt: "Cancel"
            onPressed: {
                root.cancelPressed()
            }
        }
        MyButton{
            Layout.fillHeight: true
            Layout.fillWidth: true
            txt:"Start"
            onPressed: {
                startNewGame(checkedSize)
            }
        }
    }
}


