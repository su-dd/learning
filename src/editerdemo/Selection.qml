import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Text Selection Demo"

    Item {
        anchors.fill: parent

        Text {
            id: textElement
            text: "这是一段可以支持文本选择的文本。"
            anchors.centerIn: parent
            font.pointSize: 20
            color: "black"

            property int selectionStart: -1
            property int selectionEnd: -1

            // 假设的字符宽度和高度，这需要根据实际字体进行调整
            property real charWidth: 15
            property real charHeight: 25

            MouseArea {
                anchors.fill: parent

                onPressed: {
                    var pos = mapToItem(textElement, mouse.x, mouse.y);
                    var index = textElement.positionAt(pos.x, 0).character;
                    if (index >= 0 && index < textElement.text.length) {
                        textElement.selectionStart = index;
                        textElement.selectionEnd = index;
                        updateSelectionRect();
                    }
                }

                onPositionChanged: {
                    if (mouse.buttons === Qt.LeftButton) {
                        var pos = mapToItem(textElement, mouse.x, mouse.y);
                        var index = textElement.positionAt(pos.x, 0).character;
                        if (index >= 0 && index < textElement.text.length) {
                            textElement.selectionEnd = index;
                            updateSelectionRect();
                        }
                    }
                }

                onReleased: {
                    // 处理选择结束的逻辑
                }
            }

            function updateSelectionRect() {
                if (selectionStart >= 0 && selectionEnd >= 0 && selectionStart <= selectionEnd) {
                    var startPos = textElement.positionToCoordinate(Qt.AlignLeft, selectionStart);
                    var endPos = textElement.positionToCoordinate(Qt.AlignLeft, selectionEnd);

                    // 估算选择区域的宽度
                    var width = (endPos.x - startPos.x) + charWidth;
                    if (width < charWidth) width = charWidth; // 至少显示一个字符的宽度

                    // 选择区域的Y坐标和高度通常是固定的，基于文本的baseline或顶部
                    var height = charHeight;
                    var y = startPos.y - (charHeight / 2); // 假设在文本基线上方居中

                    // 更新选择矩形
                    selectionRect.visible = true;
                    selectionRect.x = startPos.x;
                    selectionRect.y = y;
                    selectionRect.width = width;
                    selectionRect.height = height;
                } else {
                    selectionRect.visible = false;
                }
            }

            Rectangle {
                id: selectionRect
                anchors.fill: parent
                color: "lightblue"
                border.color: "black"
                border.width: 1
                visible: false
            }
        }
    }
}
