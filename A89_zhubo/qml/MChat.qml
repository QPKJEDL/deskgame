import QtQuick 2.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

//Window{
//    id:window
//    width:300
//    height:500
//    visible:true
//    ListView{
//        add: Transition {
//        //设置增加Item时的动画 from 100,100  to不设置 就是默认在ListView
//            NumberAnimation {
//                properties: "x"
//                from: 100
//                duration: 1000
//            }
//        }
//        id:listview
//        snapMode: ListView.SnapToItem
//        anchors.top: parent.top
//        anchors.bottom: bottomrect.top
//        anchors.left:parent.left
//        anchors.right:parent.right
//        //anchors的对象要么是兄弟结点（提供id）
//        //要么就是子节点（parent）
////        delegate:Component{
////            Rectangle{
////                width:window.width
////                height:label1.height+20
////                BorderImage{
////                    //聊天气泡
////                    id:qipao
////                    source:"pao.png"
////                    width:label1.width+20
////                    height:label1.height<=30?30:label1.height+5
////                    //  width:20
////                    border.left: 10
////                    border.right: 10
////                    border.top:10
////                    border.bottom:10
////                    x:parent.width-width
////                    Text{
////                        id:label1
////                        /*************
////                        此处为可变大小的聊天气泡的重点
////                        根据获取值的长度 和每个字占的像素
////                        *************/
////                        width:label1.text.length * 12//<=10?label1.text.length*12:120
////                        font.pixelSize: 12
////                        anchors.centerIn:parent
////                        anchors.leftMargin:10
////                        wrapMode: Text.Wrap //多行文本 超过width就自动换行
////                        text:detail
////                    }
////                }
////            }
////        }
//        delegate: MText{}

//        model:ListModel{
//            id:listmodel
//            ListElement{
//                detail:"你好这是内容哈哈"

//            }
//        }
//    }
//    //底部
//    Rectangle{
//        height: 40
//        anchors.bottom: parent.bottom
//        id:bottomrect
//        Row{
//            TextField{
//                id:textfield
//                placeholderText: "输入内容"
//                height:bottomrect.height
//                width:window.width*0.7
//            }
//            Button{
//                text:"发送"
//                height:bottomrect.height
//                width:window.width*0.3
//                onClicked: {
//                    listmodel.append({"detail":textfield.text})
//                    listmodel.append(aLoader.item)
//                }
//            }
//        }
//    }

//    Loader{
//        id: aLoader
//        sourceComponent: MText
//    }
//}
Rectangle {
    id: rectangle
    width: parent.width
    height: parent.height
    color: "#272739"

    ListView {
        id: dataView
        x: 15
        anchors.rightMargin: 20
        anchors.leftMargin: 16
        anchors.bottomMargin: 50
        anchors.topMargin: 50
        anchors.fill: parent
        highlightFollowsCurrentItem: false
        snapMode: ListView.SnapToItem
        spacing: 2
        model: MDataBank{
            id: dataBank
        }
        delegate: MText{
        }
    }

    Image {
        id: image
        width: 50
        height: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 9
        anchors.right: parent.right
        anchors.rightMargin: 9
        source: "clear.png"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                module_chat.clear()
            }
        }
    }

    Connections{
        target: module_chat
        onShowText:{
            if(dataView.count > 500){
                dataView.remove
            }

            dataBank.append({"value":txt,"name":name,"userid":id})
            dataView.positionViewAtEnd();
        }
        onBan_finish:{
            dataBank.append({"value":txt})
            dataView.positionViewAtEnd();
        }
    }
}





/*##^##
Designer {
    D{i:1;anchors_height:0}D{i:5;anchors_height:100;anchors_width:100}
}
##^##*/
