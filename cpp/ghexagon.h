#ifndef GHEXAGON_H
#define GHEXAGON_H

#include "abstractgraphic.h"
#include <QJsonObject>
#include <QVector2D>

class GHexagon: public AbstractGraphic
{
public:
    GHexagon();
    GHexagon(QVariantMap mp);

    QJsonObject toJson() override;
    void loadFromJson(QJsonObject obj) override;
    void loadFromCoord(QVector2D st, QVector2D ed) override;
    bool isInnerSpace(qreal x, qreal y) override;
    void updatePosition(QVector2D relPos) override;
};

#endif // GHEXAGON_H
