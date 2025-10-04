import QtQuick
import GraphicLogic 1.0

Canvas {
    id: drawingCanvas

    // 绘制模式：move, line, rectangle, circle, triangle, hexagon
    property string drawMode
    property int selectedGraphicIndex
    property bool isDrawing: false
    property var startPoint: null
    property var currentMousePos: null
    
    // 拖动相关属性
    property bool isDragging: false
    property var lastDragPos: null
    
    signal update()
    signal requestPropertyPanel()
    signal requestLayerPanel()

    onSelectedGraphicIndexChanged: {
        requestPaint();
    }

    onPaint: {
        var ctx = getContext("2d");
        ctx.clearRect(0, 0, width, height);
        ctx.fillStyle = "white";
        ctx.fillRect(0, 0, width, height);

        // 设置默认样式
        ctx.strokeStyle = "black";
        ctx.lineWidth = 2;
        ctx.fillStyle = "transparent";

        // 绘制所有图形
        drawAllGraphics(ctx);

        // 如果正在绘制，显示预览
        if (isDrawing && startPoint && drawMode !== "move") {
            drawPreview(ctx);
        }
    }

    function drawAllGraphics(ctx) {
        // 获取按z层级排序的图形索引列表（从低到高绘制，高层级的会覆盖低层级的）
        var orderedIndices = GraphicLogic.getGraphicsOrderByZ();

        for (var i = 0; i < orderedIndices.length; i++) {
            var graphicIndex = orderedIndices[i];
            var graphicInfo = GraphicLogic.getInfo(graphicIndex);
            drawSingleGraphic(ctx, graphicInfo, graphicIndex === selectedGraphicIndex);
        }
    }

    function drawSingleGraphic(ctx, info, isSelected) {
        if (!info || !info.type) return;

        // 检查图形是否可见
        if (info.visible === false) return;

        // 如果是选中的图形，使用不同颜色
        if (isSelected) {
            if (isDragging) {
                // 拖动时的样式
                ctx.strokeStyle = "orange";
                ctx.lineWidth = 3;
                ctx.shadowBlur = 5;
                ctx.shadowColor = "orange";
            } else {
                // 选中但未拖动的样式
                ctx.strokeStyle = "red";
                ctx.lineWidth = 3;
            }
        } else {
            // 普通样式
            ctx.strokeStyle = "black";
            ctx.lineWidth = 2;
        }

        switch(info.type) {
            case "rectangle":
                drawRectangle(ctx, info);
                break;
            case "circle":
                drawCircle(ctx, info);
                break;
            case "triangle":
                drawTriangle(ctx, info);
                break;
            case "hexagon":
                drawHexagon(ctx, info);
                break;
            case "line":
                drawLine(ctx, info);
                break;
        }
        
        // 重置阴影效果
        ctx.shadowBlur = 0;
        ctx.shadowColor = "transparent";
    }

    function drawRectangle(ctx, info) {
        if (info.x !== undefined && info.y !== undefined && info.width !== undefined && info.height !== undefined) {
            ctx.strokeRect(info.x, info.y, info.width, info.height);
        }
    }

    function drawCircle(ctx, info) {
        if (info.centerX !== undefined && info.centerY !== undefined && info.radius !== undefined) {
            ctx.beginPath();
            ctx.arc(info.centerX, info.centerY, info.radius, 0, 2 * Math.PI);
            ctx.stroke();
        }
    }

    function drawTriangle(ctx, info) {
        if (info.points && info.points.length >= 6) {
            ctx.beginPath();
            ctx.moveTo(info.points[0], info.points[1]);
            ctx.lineTo(info.points[2], info.points[3]);
            ctx.lineTo(info.points[4], info.points[5]);
            ctx.closePath();
            ctx.stroke();
        }
    }

    function drawHexagon(ctx, info) {
        if (info.points && info.points.length >= 4) {
            ctx.beginPath();
            ctx.moveTo(info.points[0], info.points[1]);
            for (var i = 2; i < info.points.length; i += 2) {
                ctx.lineTo(info.points[i], info.points[i + 1]);
            }
            ctx.closePath();
            ctx.stroke();
        }
    }

    function drawLine(ctx, info) {
        if (info.startX !== undefined && info.startY !== undefined && info.endX !== undefined && info.endY !== undefined) {
            ctx.beginPath();
            ctx.moveTo(info.startX, info.startY);
            ctx.lineTo(info.endX, info.endY);
            ctx.stroke();
        }
    }

    function drawPreview(ctx) {
        if (!startPoint || !currentMousePos) return;

        // 获取图形类计算的预览信息
        var previewInfo = GraphicLogic.getPreviewGraphicInfo(
            drawMode,
            startPoint.x, startPoint.y,
            currentMousePos.x, currentMousePos.y
        );

        if (!previewInfo || !previewInfo.type) return;

        ctx.strokeStyle = "gray";
        ctx.lineWidth = 1;
        ctx.setLineDash([5, 5]); // 虚线预览

        // 使用统一的绘制方法绘制预览
        drawSingleGraphic(ctx, previewInfo, false);

        ctx.setLineDash([]); // 重置虚线
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: {
            if (drawingCanvas.drawMode === "move") {
                if (drawingCanvas.isDragging) {
                    return Qt.ClosedHandCursor;
                } else {
                    // 检查鼠标是否在图形上
                    var graphicsCount = GraphicLogic.getGraphicsCount();
                    var currentPos = drawingCanvas.currentMousePos;
                    if (currentPos) {
                        for (var i = graphicsCount - 1; i >= 0; i--) {
                            if (GraphicLogic.isPointInGraphic(i, currentPos.x, currentPos.y)) {
                                return Qt.OpenHandCursor;
                            }
                        }
                    }
                    return Qt.ArrowCursor;
                }
            } else {
                return Qt.CrossCursor;
            }
        }

        onPositionChanged: {
            drawingCanvas.currentMousePos = {x: mouseX, y: mouseY};
            
            if (pressed && drawingCanvas.selectedGraphicIndex >= 0 && !drawingCanvas.isDragging) {
                drawingCanvas.isDragging = true;
                drawingCanvas.lastDragPos = {x: mouseX, y: mouseY};
            }

            if (drawingCanvas.isDrawing && drawingCanvas.drawMode !== "move") {
                // 正在绘制新图形，显示预览
                parent.requestPaint();
            } else if (drawingCanvas.isDragging && drawingCanvas.selectedGraphicIndex >= 0) {
                // 正在拖动选中的图形
                if (drawingCanvas.lastDragPos) {
                    var deltaX = mouseX - drawingCanvas.lastDragPos.x;
                    var deltaY = mouseY - drawingCanvas.lastDragPos.y;
                    
                    // 更新图形位置
                    GraphicLogic.updateGraphicPosition(drawingCanvas.selectedGraphicIndex, deltaX, deltaY);
                    parent.requestPaint();
                    drawingCanvas.requestPropertyPanel();
                }
                drawingCanvas.lastDragPos = {x: mouseX, y: mouseY};
            }
        }

        onPressed: {
            if (drawingCanvas.drawMode === "move") {
                // 检查是否点击了某个图形
                handleGraphicSelection(mouseX, mouseY);

            } else {
                // 开始绘制新图形
                drawingCanvas.startDrawing(mouseX, mouseY);
            }
        }

        onReleased: {
            if (drawingCanvas.isDrawing && drawingCanvas.drawMode !== "move") {
                drawingCanvas.finishDrawing(mouseX, mouseY);
            } else if (drawingCanvas.isDragging) {
                // 结束拖动
                drawingCanvas.isDragging = false;
                drawingCanvas.lastDragPos = null;
                drawingCanvas.requestPaint();
            }
        }
    }

    function handleGraphicSelection(x, y) {
        // 检查点击位置是否在某个图形内
        var graphicsCount = GraphicLogic.getGraphicsCount();
        for (var i = graphicsCount - 1; i >= 0; i--) {
            if (GraphicLogic.isPointInGraphic(i, x, y)) {
                selectedGraphicIndex = i;
                requestPaint();
                update();
                return;
            }
        }
        // 如果没有点击到图形，取消选择
        selectedGraphicIndex = -1;
        requestPaint();
        update();
    }

    function startDrawing(x, y) {
        startPoint = {x: x, y: y};
        isDrawing = true;
    }

    function finishDrawing(x, y) {
        if (!startPoint) return;

        var graphicInfo = GraphicLogic.getPreviewGraphicInfo(drawMode, startPoint.x, startPoint.y, x, y);
        graphicInfo["z"] = GraphicLogic.getMaxZLevel() + 1; // 设置图层为最高
        graphicInfo["no"] = GraphicLogic.getMaxNo() + 1;
        if (graphicInfo) {
            GraphicLogic.newGraphic(graphicInfo);
            requestPaint();
            drawingCanvas.requestLayerPanel();
        }
        isDrawing = false;
        startPoint = null;
    }
}
