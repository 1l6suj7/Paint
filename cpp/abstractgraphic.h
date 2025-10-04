#ifndef ABSTRACTGRAPHIC_H
#define ABSTRACTGRAPHIC_H

#include <QJsonArray>

class AbstractGraphic
{
public:
    AbstractGraphic();

    virtual ~AbstractGraphic();

    virtual QJsonObject toJson() = 0;
    virtual void loadFromJson(QJsonObject obj) = 0;
    virtual void loadFromCoord(QVector2D st, QVector2D ed) = 0;
    virtual bool isInnerSpace(qreal x, qreal y) = 0;
    virtual void updatePosition(QVector2D relPos) = 0;

    QVariantMap info; // 包含图形的所有属性，包括 "z" 层级
};

#endif // ABSTRACTGRAPHIC_H
