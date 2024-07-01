import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 200
    title: "闪烁光标示例"

    Rectangle {
        id: cursor_control
        width: 2
        height: 20
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        visible: cursorVisible

        // 光标颜色
        color: "black"

        // 使用属性动画来创建闪烁效果
        PropertyAnimation on visible {
            from: true
            to: false
            duration: 500
            loops: Animation.Infinite
            easing.type: Easing.OutInQuad
        }
    }

    // 用于控制光标可见性的属性
    property bool cursorVisible: true

    // 定时器，用于切换光标的可见性
    Timer {
        running: true
        repeat: true
        interval: 500
        onTriggered: cursorVisible = !cursorVisible
    }
}
