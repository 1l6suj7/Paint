#include "gtriangle.h"
#include <QJsonObject>
#include <QJsonArray>

GTriangle::GTriangle() {}

GTriangle::GTriangle(QVariantMap mp)
{
    info = mp;
    // 确保包含必要的属性
    if (!info.contains("type")) {
        info["type"] = "triangle";
    }
}

QJsonObject GTriangle::toJson()
{
    QJsonObject obj;
    obj["type"] = "triangle";
    
    QJsonArray pointsArray;
    QVariantList points = info.value("points").toList();
    for (const auto& point : points) {
        pointsArray.append(point.toDouble());
    }
    obj["points"] = pointsArray;
    obj["z"] = info.value("z", 1).toInt();
    obj["name"] = info.value("name", "未命名").toString();
    obj["no"] = info.value("no", 0).toInt();
    return obj;
}

void GTriangle::loadFromJson(QJsonObject obj)
{
    info.clear();
    info["type"] = "triangle";
    
    QJsonArray pointsArray = obj["points"].toArray();
    QVariantList points;
    for (const auto& point : pointsArray) {
        points.append(point.toDouble());
    }
    info["points"] = points;
    info["z"] = obj["z"].toInt();
    info["name"] = obj["name"].toString();
    info["no"] = obj["no"].toInt();
}

void GTriangle::loadFromCoord(QVector2D st, QVector2D ed)
{
    info["type"] = "triangle";
    
    // 创建一个等腰三角形
    qreal width = qAbs(ed.x() - st.x());
    qreal height = qAbs(ed.y() - st.y());
    
    // 三个顶点：顶部中心、左下、右下
    qreal topX = qMin(st.x(), ed.x()) + width / 2;
    qreal topY = qMin(st.y(), ed.y());
    qreal bottomY = qMax(st.y(), ed.y());
    qreal leftX = qMin(st.x(), ed.x());
    qreal rightX = qMax(st.x(), ed.x());
    
    QVariantList points;
    points << topX << topY;      // 顶点
    points << leftX << bottomY;  // 左下角
    points << rightX << bottomY; // 右下角
    
    info["points"] = points;
    if (!info.contains("z")) {
        info["z"] = 1;
    }
}

bool GTriangle::isInnerSpace(qreal x, qreal y)
{
    QVariantList points = info.value("points").toList();
    if (points.size() < 6) return false;
    
    // 获取三角形的三个顶点
    qreal x1 = points[0].toReal(), y1 = points[1].toReal();
    qreal x2 = points[2].toReal(), y2 = points[3].toReal();
    qreal x3 = points[4].toReal(), y3 = points[5].toReal();
    
    // 使用重心坐标法判断点是否在三角形内
    qreal denom = (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
    if (qAbs(denom) < 1e-10) return false; // 防除零
    
    qreal a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denom;
    qreal b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denom;
    qreal c = 1 - a - b;
    
    return (a >= 0 && b >= 0 && c >= 0);
}

void GTriangle::updatePosition(QVector2D relPos)
{
    QVariantList points = info.value("points").toList();
    if (points.size() < 6) return;
    
    // 移动所有顶点
    for (int i = 0; i < points.size(); i += 2) {
        points[i] = points[i].toReal() + relPos.x();     // x坐标
        points[i + 1] = points[i + 1].toReal() + relPos.y(); // y坐标
    }
    
    info["points"] = points;
}
