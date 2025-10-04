#ifndef GRAPHICLOGIC_H
#define GRAPHICLOGIC_H

#include <QObject>
#include <QVariantMap>
#include <QUrl>
#include "abstractgraphic.h"

class GraphicLogic: public QObject
{
    Q_OBJECT
public:
    GraphicLogic(QObject * parent = nullptr);

    static GraphicLogic* getInstance();

signals:
    void saveSucceeded();
    void saveFailed();
    void loadSucceeded();
    void loadFailed();

public slots:
    QVariantMap getInfo(int index);
    void newGraphic(QVariantMap info);
    void modifyGraphic(int index, QVariantMap info);
    void saveAsFile(QUrl url);
    void loadFromFile(QUrl url);
    bool getIsSave();
    
    // Canvas 相关方法
    int getGraphicsCount();
    bool isPointInGraphic(int index, qreal x, qreal y);
    void deleteGraphic(int index);
    void clearAllGraphics();
    
    // 图层管理方法
    int getMaxZLevel();
    void moveGraphicToTop(int index);
    void moveGraphicToBottom(int index);
    void moveGraphicUp(int index);
    void moveGraphicDown(int index);
    QList<int> getGraphicsOrderByZ(); // 返回按z层级排序的索引列表
    void setGraphicName(int index, QString name);
    
    // 预览辅助方法
    QVariantMap getPreviewGraphicInfo(QString type, qreal startX, qreal startY, qreal endX, qreal endY);
    
    // 图层列表管理
    QVariantList getLayerList(); // 获取图层列表信息
    void setGraphicVisibility(int index, bool visible);
    bool getGraphicVisibility(int index);
    int getNo(int index);
    int getMaxNo();

    // 拖动支持方法
    void updateGraphicPosition(int index, qreal deltaX, qreal deltaY);

private:
    QList<AbstractGraphic*> list;
    bool isSave;
    int maxNo;
};

#endif // GRAPHICLOGIC_H
