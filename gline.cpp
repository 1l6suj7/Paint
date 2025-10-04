#include "gline.h"
#include <QtMath>

GLine::GLine() {}

GLine::GLine(QVariantMap mp)
{
    info = mp;
    if (!info.contains("type")) {
        info["type"] = "line";
    }
}

QJsonObject GLine::toJson()
{
    QJsonObject obj;
    obj["type"] = "line";
    obj["startX"] = info["startX"].toDouble();
    obj["startY"] = info["startY"].toDouble();
    obj["endX"] = info["endX"].toDouble();
    obj["endY"] = info["endY"].toDouble();
    obj["z"] = info["z"].toInt();
    obj["name"] = info.value("name", "未命名").toString();
    obj["no"] = info.value("no", 0).toInt();
    return obj;
}

void GLine::loadFromJson(QJsonObject obj)
{
    info.clear();
    info["type"] = "line";
    info["startX"] = obj["startX"].toDouble();
    info["startY"] = obj["startY"].toDouble();
    info["endX"] = obj["endX"].toDouble();
    info["endY"] = obj["endY"].toDouble();
    info["z"] = obj["z"].toInt();
    info["name"] = obj["name"].toString();
    info["no"] = obj["no"].toInt();
}

void GLine::loadFromCoord(QVector2D st, QVector2D ed)
{
    info.clear();
    info["type"] = "line";
    info["startX"] = st.x();
    info["startY"] = st.y();
    info["endX"] = ed.x();
    info["endY"] = ed.y();
    if (!info.contains("z")) {
        info["z"] = 1;
    }
}

bool GLine::isInnerSpace(qreal x, qreal y)
{
    qreal startX = info.value("startX", 0).toReal();
    qreal startY = info.value("startY", 0).toReal();
    qreal endX = info.value("endX", 0).toReal();
    qreal endY = info.value("endY", 0).toReal();
    
    // 计算点到线段的距离
    qreal A = endY - startY;
    qreal B = startX - endX;
    qreal C = endX * startY - startX * endY;
    
    // 点到直线的距离公式：|Ax + By + C| / sqrt(A² + B²)
    qreal distance = qAbs(A * x + B * y + C) / qSqrt(A * A + B * B);
    
    // 检查点是否在线段范围内
    qreal minX = qMin(startX, endX);
    qreal maxX = qMax(startX, endX);
    qreal minY = qMin(startY, endY);
    qreal maxY = qMax(startY, endY);
    
    // 扩展一个容差范围
    const qreal tolerance = 5.0; // 5像素的容差
    
    bool inRange = (x >= minX - tolerance && x <= maxX + tolerance &&
                   y >= minY - tolerance && y <= maxY + tolerance);
    
    return (distance <= tolerance && inRange);
}

void GLine::updatePosition(QVector2D relPos)
{
    qreal currentStartX = info.value("startX", 0).toReal();
    qreal currentStartY = info.value("startY", 0).toReal();
    qreal currentEndX = info.value("endX", 0).toReal();
    qreal currentEndY = info.value("endY", 0).toReal();
    
    info["startX"] = currentStartX + relPos.x();
    info["startY"] = currentStartY + relPos.y();
    info["endX"] = currentEndX + relPos.x();
    info["endY"] = currentEndY + relPos.y();
}
