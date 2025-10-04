#include "gcircle.h"
#include <QJsonObject>
#include <QtMath>

GCircle::GCircle() {}

GCircle::GCircle(QVariantMap mp)
{
    info = mp;
    // 确保包含必要的属性
    if (!info.contains("type")) {
        info["type"] = "circle";
    }
}

QJsonObject GCircle::toJson()
{
    QJsonObject obj;
    obj["type"] = "circle";
    obj["centerX"] = info.value("centerX", 0).toReal();
    obj["centerY"] = info.value("centerY", 0).toReal();
    obj["radius"] = info.value("radius", 0).toReal();
    obj["z"] = info.value("z", 1).toInt();
    obj["name"] = info.value("name", "未命名").toString();
    obj["no"] = info.value("no", 0).toInt();
    return obj;
}

void GCircle::loadFromJson(QJsonObject obj)
{
    info.clear();
    info["type"] = "circle";
    info["centerX"] = obj["centerX"].toDouble();
    info["centerY"] = obj["centerY"].toDouble();
    info["radius"] = obj["radius"].toDouble();
    info["z"] = obj["z"].toInt();
    info["name"] = obj["name"].toString();
    info["no"] = obj["no"].toInt();
}

void GCircle::loadFromCoord(QVector2D st, QVector2D ed)
{
    info["type"] = "circle";
    // 使用st作为圆心，ed计算半径
    info["centerX"] = st.x();
    info["centerY"] = st.y();
    qreal dx = ed.x() - st.x();
    qreal dy = ed.y() - st.y();
    info["radius"] = qSqrt(dx * dx + dy * dy);
    if (!info.contains("z")) {
        info["z"] = 1;
    }
}

bool GCircle::isInnerSpace(qreal x, qreal y)
{
    qreal centerX = info.value("centerX", 0).toReal();
    qreal centerY = info.value("centerY", 0).toReal();
    qreal radius = info.value("radius", 0).toReal();
    
    qreal dx = x - centerX;
    qreal dy = y - centerY;
    qreal distance = qSqrt(dx * dx + dy * dy);
    
    return distance <= radius;
}

void GCircle::updatePosition(QVector2D relPos)
{
    qreal currentCenterX = info.value("centerX", 0).toReal();
    qreal currentCenterY = info.value("centerY", 0).toReal();
    
    info["centerX"] = currentCenterX + relPos.x();
    info["centerY"] = currentCenterY + relPos.y();
}
