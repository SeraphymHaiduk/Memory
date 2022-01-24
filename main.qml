import QtQuick 2.12
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Window {
    id: root
    width: 400
    height: 640
    visible: true
    title: qsTr("Hello World")
    function startNewGame(size){
        menu.closeMenu()
        fieldModel.clear()
        controller.startNewGame(size)
        field.rows = size
        field.cols = size
    }
    Connections{
        target: controller
        onSessionInnitialised:{
            console.log("qml")
            console.log("arr: "+images+" size: "+size)
            for(var i = 0; i < size; i++){
                for(var j = 0; j < size; j++){
                    fieldModel.append({image:"Pictures/"+images[i*size+j],flipped:0})
                }
            }
        }
    }
    Connections{
        target: field
        onPressed:{
            console.log(1)
            controller.pressOn(pos/field.rows, pos%field.cols)
        }
    }
    Connections{
        target: controller
        onFlip:{
            fieldModel.set(x*field.rows+y,{"flipped":1})
        }
    }
    Timer{
        id: flipBackTimer
        repeat: false
        interval: 1000
        property var coords:[]
        onTriggered: {
            fieldModel.set(coords["x1"]*field.rows+coords["y1"],{"flipped":0})
            fieldModel.set(coords["x2"]*field.rows+coords["y2"],{"flipped":0})
            field.blockField = false
        }
    }
    Connections{
        target: controller
        onFlipBack:{
            fieldModel.set(x2*field.rows+y2,{"flipped":1})
            field.blockField = true
            flipBackTimer.start()
            flipBackTimer.coords = {
                "x1":x1,
                "y1":y1,
                "x2":x2,
                "y2":y2
            }
        }
    }
    Connections{
        target: controller
        onTimeUpdate:{
            status.updateTime(Qt.formatTime(time,"hh:mm:ss"))
        }
    }
    Connections{
        target: controller
        onScoreUpdate:{
            status.updateFlipped(score+"/"+(field.rows**2)/2)
        }
    }
    Connections{
        target: controller
        onStepsUpdate:{
            status.updateSteps(steps)
        }
    }
    Connections{
        target: controller
        onVictory:{
            menu.showScore(score,isRecord)
        }
    }

//    function updateSteps(num){
//        stepsTxt.text = num
//    }
//    function updateFlipped(str){
//        flippedTxt.text = str
//    }
//    function updateTime(str){
//        timeTxt.text = str
//    }

/*c++
    void timeUpdate(QString);
    void stepsUpdate(int);
    void scoreUpdate(int);
*/
    Page{
        anchors.fill: parent
        Component.onCompleted: {
            menu.showNewGame()
        }
        header: Rectangle{
            color: "lightgray"
            anchors{
                left: parent.left
                right: parent.right
            }
            height: root.height*0.075
            RowLayout{
                id:layout
                spacing: 10
                anchors{
                    fill: parent
                    leftMargin: spacing
                    rightMargin: spacing
                    topMargin: parent.height*0.1
                    bottomMargin: parent.height*0.1
                }
                MyButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    txt: "New Game"
                    radius: height/4
                    onPressed: {
                        menu.showNewGame()
                    }
                }
                MyButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    txt: "Records"
                    radius: height/4
                    onPressed: {
                        menu.showRecord(controller.getRecords())
                        /*{"10":{"steps":47,"time":"00:13:37","size":10},
                                        "8":{"steps":48,"time":"00:13:37","size":8},
                                        "6":{"steps":47,"time":"00:14:37","size":6},
                                        "4":{"steps":47,"time":"00:13:37","size":4}}*/
                    }
                }
            }
        }
        SessionStatus{
            id: status
            fontPixelSize: 20
            anchors{
                horizontalCenter: parent.horizontalCenter
                top: parent.top
                topMargin: 100
            }
        }
        ListModel{
            id:fieldModel
        }
        Field{
            id: field
            rows: 10
            cols: 10
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                margins: parent.width*0.05
            }
            model: fieldModel
        }
    }

    Component{
        id:newGameMenuComponent
        NewGameMenu{
            id:newGameMenu
            Component.onCompleted: {
                startNewGame.connect(root.startNewGame)
            }
            onCancelPressed: {
                menu.closeMenu()
            }
        }
    }
    Component{
        id:scoreMenuComponent
        ScoreMenu{
            id:scoreMenu
        }

    }
    Rectangle{
        id:menu
        function closeMenu(){
            menu.opacity = 0
        }
        function showNewGame(){
            menu.opacity = 1
            loader.sourceComponent = newGameMenuComponent
        }
        function showScore(dict, isRecord){
            menu.opacity = 1
            loader.sourceComponent = scoreMenuComponent
            loader.item.model.append({"steps":dict["steps"],"time":dict["time"],"size":dict["size"]})
            loader.item.message = isRecord?"It's new record!\n\tScore:":"Score:"
            loader.item.fontPixelSize = 16
        }
        function showRecord(list){
            menu.opacity = 1
            loader.sourceComponent = scoreMenuComponent
                for(var a in list){
                    loader.item.model.append({"steps":list[a]["steps"],"time":list[a]["time"],"size":list[a]["size"]})
                }
                loader.item.message = "Records:"
                loader.item.fontPixelSize = 16
        }
        anchors.fill: parent
        color: "#88888888"
        opacity: 0
        visible: opacity===0?false:true
        MouseArea{
            anchors.fill: parent
            onPressed: {
                menu.closeMenu()
            }
        }
        Loader{
            id:loader
            sourceComponent: newGameMenuComponent
            opacity: menu.opacity
            visible: opacity===0?false:true
            anchors{
                fill: parent
                leftMargin: parent.width*0.1
                rightMargin: parent.width*0.1
                topMargin: parent.height*0.05
                bottomMargin: parent.height*0.05
            }
        }
        Behavior on opacity {
            NumberAnimation{
                duration: 300
            }
        }

    }
}
