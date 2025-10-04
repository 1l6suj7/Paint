#ifndef GLINE_H
#define GLINE_H

#include "abstractgraphic.h"
#include <QJsonObject>
#include <QVector2D>

class GLine : public AbstractGraphic
{
public:
    GLine();
    GLine(QVariantMap mp);

    QJsonObject toJson() override;
    void loadFromJson(QJsonObject obj) override;
    void loadFromCoord(QVector2D st, QVector2D ed) override;
    bool isInnerSpace(qreal x, qreal y) override;
    void updatePosition(QVector2D relPos) override;
};

#endif // GLINE_H
