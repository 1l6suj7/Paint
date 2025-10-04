#include "ghexagon.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QtMath>

GHexagon::GHexagon() {}

GHexagon::GHexagon(QVariantMap mp)
{
    info = mp;
    // 确保包含必要的属性
    if (!info.contains("type")) {
        info["type"] = "hexagon";
    }
}

QJsonObject GHexagon::toJson()
{
    QJsonObject obj;
    obj["type"] = "hexagon";
    
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

void GHexagon::loadFromJson(QJsonObject obj)
{
    info.clear();
    info["type"] = "hexagon";
    
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

void GHexagon::loadFromCoord(QVector2D st, QVector2D ed)
{
    info["type"] = "hexagon";

    qreal centerX = (st.x() + ed.x()) / 2;
    qreal centerY = (st.y() + ed.y()) / 2;
    qreal width = qAbs(ed.x() - st.x());
    qreal height = qAbs(ed.y() - st.y());
    qreal radius = qMin(width, height) / 2;
    
    QVariantList points;
    const int sides = 6;
    for (int i = 0; i < sides; ++i) {
        qreal angle = 2 * M_PI * i / sides;
        qreal px = centerX + radius * qCos(angle);
        qreal py = centerY + radius * qSin(angle);
        points << px << py;
    }
    
    info["points"] = points;
    if (!info.contains("z")) {
        info["z"] = 1;
    }
}

bool GHexagon::isInnerSpace(qreal x, qreal y)
{
    QVariantList points = info.value("points").toList();
    if (points.size() < 6) return false; // 至少需要3个点（6个坐标值）
    
    // 使用射线法判断点是否在多边形内
    int intersections = 0;
    int numVertices = points.size() / 2;
    
    for (int i = 0; i < numVertices; ++i) {
        int next = (i + 1) % numVertices;
        
        qreal x1 = points[i * 2].toReal();
        qreal y1 = points[i * 2 + 1].toReal();
        qreal x2 = points[next * 2].toReal();
        qreal y2 = points[next * 2 + 1].toReal();
        
        // 检查水平射线是否与边相交
        if (((y1 <= y) && (y < y2)) || ((y2 <= y) && (y < y1))) {
            // 计算交点的x坐标
            qreal xIntersect = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
            if (x < xIntersect) {
                intersections++;
            }
        }
    }
    
    // 奇数个交点表示在多边形内
    return (intersections % 2) == 1;
}

void GHexagon::updatePosition(QVector2D relPos)
{
    QVariantList points = info.value("points").toList();
    if (points.size() < 4) return;
    
    // 移动所有顶点
    for (int i = 0; i < points.size(); i += 2) {
        points[i] = points[i].toReal() + relPos.x();     // x坐标
        points[i + 1] = points[i + 1].toReal() + relPos.y(); // y坐标
    }
    
    info["points"] = points;
}
