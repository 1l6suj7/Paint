#include "grectangle.h"
#include <QJsonObject>

GRectangle::GRectangle() {}

GRectangle::GRectangle(QVariantMap mp)
{
    info = mp;
    // 确保包含必要的属性
    if (!info.contains("type")) {
        info["type"] = "rectangle";
    }
}

QJsonObject GRectangle::toJson()
{
    QJsonObject obj;
    obj["type"] = "rectangle";
    obj["x"] = info.value("x", 0).toReal();
    obj["y"] = info.value("y", 0).toReal();
    obj["width"] = info.value("width", 0).toReal();
    obj["height"] = info.value("height", 0).toReal();
    obj["z"] = info.value("z", 1).toInt();
    obj["name"] = info.value("name", "未命名").toString();
    obj["no"] = info.value("no", 0).toInt();
    return obj;
}

void GRectangle::loadFromJson(QJsonObject obj)
{
    info.clear();
    info["type"] = "rectangle";
    info["x"] = obj["x"].toDouble();
    info["y"] = obj["y"].toDouble();
    info["width"] = obj["width"].toDouble();
    info["height"] = obj["height"].toDouble();
    info["z"] = obj["z"].toInt();
    info["name"] = obj["name"].toString();
    info["no"] = obj["no"].toInt();
}

void GRectangle::loadFromCoord(QVector2D st, QVector2D ed)
{
    info["type"] = "rectangle";
    info["x"] = qMin(st.x(), ed.x());
    info["y"] = qMin(st.y(), ed.y());
    info["width"] = qAbs(ed.x() - st.x());
    info["height"] = qAbs(ed.y() - st.y());
    if (!info.contains("z")) {
        info["z"] = 1;
    }
}

bool GRectangle::isInnerSpace(qreal x, qreal y)
{
    qreal rectX = info.value("x", 0).toReal();
    qreal rectY = info.value("y", 0).toReal();
    qreal rectWidth = info.value("width", 0).toReal();
    qreal rectHeight = info.value("height", 0).toReal();
    
    return (x >= rectX && x <= rectX + rectWidth &&
            y >= rectY && y <= rectY + rectHeight);
}

void GRectangle::updatePosition(QVector2D relPos)
{
    qreal currentX = info.value("x", 0).toReal();
    qreal currentY = info.value("y", 0).toReal();
    
    info["x"] = currentX + relPos.x();
    info["y"] = currentY + relPos.y();
}
