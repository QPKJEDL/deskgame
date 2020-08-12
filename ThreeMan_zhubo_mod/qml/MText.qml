import QtQuick 2.0

Item{
    width: rectangle.width
    height: rectangle.height
    visible: true
    Rectangle {
        id: rectangle
        x: nam.contentWidth + 20
        width: word.contentWidth
        height: word.contentHeight + 10
        color: "#cca859"
        radius: 7
        layer.smooth: false
        Loader{
            sourceComponent: MText
        }

        Text {
            id: word
            y: (rectangle.height - word.height) / 2
            width: word.contentWidth
            height: word.contentHeight
            color: "#ffffff"
            text: value
            textFormat: Text.RichText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 34
        }
    }

    Text {
        id: nam
        width: nam.contentWidth
        height: 44
        color: "#ffffff"
        text: name
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 34

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                module_chat.pu_name(uid,name)
            }
        }
    }

    property string uid: userid
    signal ban(string id)
}

