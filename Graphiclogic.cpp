#include "Graphiclogic.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <algorithm>
#include <climits>

#include "grectangle.h"
#include "gcircle.h"
#include "gtriangle.h"
#include "ghexagon.h"
#include "gline.h"

GraphicLogic::GraphicLogic(QObject * parent): QObject(parent) {}

GraphicLogic *GraphicLogic::getInstance()
{
    static GraphicLogic ins;
    return &ins;
}

QVariantMap GraphicLogic::getInfo(int index)
{
    if (index >= list.size()) return QVariantMap {};
    return list[index]->info;
}

void GraphicLogic::newGraphic(QVariantMap info)
{
    AbstractGraphic* gra = nullptr;
    QString type = info["type"].toString();
    if (type == "rectangle") {
        gra = new GRectangle(info);
    } else if (type == "circle") {
        gra = new GCircle(info);
    } else if (type == "triangle") {
        gra = new GTriangle(info);
    } else if (type == "hexagon") {
        gra = new GHexagon(info);
    } else if (type == "line") {
        gra = new GLine(info);
    }
    if (gra) {
        maxNo = qMax(maxNo, gra->info["no"].toInt());
        gra->info = info;
        list.append(gra);
        isSave = false;
    }
}

void GraphicLogic::modifyGraphic(int index, QVariantMap info)
{
    list[index]->info = info;
}

void GraphicLogic::saveAsFile(QUrl url)
{
    try {
        QString path = url.toLocalFile();
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        QJsonArray arr;
        for (int i = 0; i < list.size(); ++i) {
            arr.append(list[i]->toJson());
        }
        QJsonObject obj;
        obj["maxNo"] = maxNo;
        obj["graphicInfo"] = arr;
        file.write(QJsonDocument{obj}.toJson());
        file.close();
        isSave = true;
        emit saveSucceeded();
    } catch(...) {
        emit saveFailed();
    }
}

void GraphicLogic::loadFromFile(QUrl url)
{
    try {
        QString path = url.toLocalFile();
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QJsonDocument doc;
        doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        maxNo = obj["maxNo"].toInt();
        QJsonArray arr = obj["graphicInfo"].toArray();
        if (list.size() > 0) list.clear();
        for (int i = 0; i < arr.size(); ++i) {
            QJsonObject obj = arr[i].toObject();
            newGraphic(obj.toVariantMap());
        }
        file.close();
        emit loadSucceeded();
    } catch(...) {
        emit loadFailed();
    }
}

bool GraphicLogic::getIsSave()
{
    return isSave;
}

int GraphicLogic::getGraphicsCount()
{
    return list.size();
}

bool GraphicLogic::isPointInGraphic(int index, qreal x, qreal y)
{
    if (index < 0 || index >= list.size()) return false;
    return list[index]->isInnerSpace(x, y);
}

void GraphicLogic::deleteGraphic(int index)
{
    if (index >= 0 && index < list.size()) {
        int z = list[index]->info["z"].toInt();
        for (int i = 0; i < list.size(); ++i) {
            if (i == index) continue;
            int tz = list[i]->info["z"].toInt();
            if (tz > z) list[i]->info["z"] = tz - 1;
        }
        delete list[index];
        list.removeAt(index);
        isSave = false;
    }
}

void GraphicLogic::clearAllGraphics()
{
    for (auto* graphic : list) {
        delete graphic;
    }
    maxNo = 0;
    list.clear();
    isSave = false;
}

int GraphicLogic::getMaxZLevel()
{
    return list.size();
}

void GraphicLogic::moveGraphicToTop(int index)
{
    if (index >= 0 && index < list.size()) {
        for (int i = 0; i < list.size(); ++i) {
            if (i == index) continue;
            if (list[i]->info["z"].toInt() > list[index]->info["z"].toInt()) {
                list[i]->info["z"] = list[i]->info["z"].toInt() - 1;
            }
        }
        list[index]->info["z"] = list.size();
    }
}

void GraphicLogic::moveGraphicToBottom(int index)
{
    if (index >= 0 && index < list.size()) {
        for (int i = 0; i < list.size(); ++i) {
            if (i == index) continue;
            if (list[i]->info["z"].toInt() < list[index]->info["z"].toInt()) {
                list[i]->info["z"] = list[i]->info["z"].toInt() + 1;
            }
        }
        list[index]->info["z"] = 1;
    }
}

void GraphicLogic::moveGraphicUp(int index)
{
    if (index >= 0 && index < list.size()) {
        int currentZ = list[index]->info.value("z", 0).toInt();
        
        // 找到比当前层级高一级的最小z值
        int nextZ = INT_MAX;
        for (const auto* graphic : list) {
            int z = graphic->info.value("z", 0).toInt();
            if (z > currentZ && z < nextZ) {
                nextZ = z;
            }
        }
        
        if (nextZ != INT_MAX) {
            // 交换z值
            for (auto* graphic : list) {
                if (graphic->info.value("z", 0).toInt() == nextZ) {
                    graphic->info["z"] = currentZ;
                    break;
                }
            }
            list[index]->info["z"] = nextZ;
            isSave = false;
        }
    }
}

void GraphicLogic::moveGraphicDown(int index)
{
    if (index >= 0 && index < list.size()) {
        int currentZ = list[index]->info.value("z", 0).toInt();
        
        // 找到比当前层级低一级的最大z值
        int prevZ = INT_MIN;
        for (const auto* graphic : list) {
            int z = graphic->info.value("z", 0).toInt();
            if (z < currentZ && z > prevZ) {
                prevZ = z;
            }
        }
        
        if (prevZ != INT_MIN) {
            // 交换z值
            for (auto* graphic : list) {
                if (graphic->info.value("z", 0).toInt() == prevZ) {
                    graphic->info["z"] = currentZ;
                    break;
                }
            }
            list[index]->info["z"] = prevZ;
            isSave = false;
        }
    }
}

QList<int> GraphicLogic::getGraphicsOrderByZ()
{
    QList<QPair<int, int>> zIndexPairs; // (z值, 原索引)
    
    for (int i = 0; i < list.size(); ++i) {
        int z = list[i]->info.value("z", 0).toInt();
        zIndexPairs.append(QPair<int, int>(z, i));
    }
    
    // 按z值排序（从小到大）
    std::sort(zIndexPairs.begin(), zIndexPairs.end(), 
              [](const QPair<int, int>& a, const QPair<int, int>& b) {
                  return a.first < b.first;
              });
    
    QList<int> result;
    for (const auto& pair : zIndexPairs) {
        result.append(pair.second);
    }
    
    return result;
}

void GraphicLogic::setGraphicName(int index, QString name)
{
    list[index]->info["name"] = name;
}

QVariantMap GraphicLogic::getPreviewGraphicInfo(QString type, qreal startX, qreal startY, qreal endX, qreal endY)
{
    // 创建临时图形对象来计算预览信息
    AbstractGraphic* tempGraphic = nullptr;
    
    if (type == "rectangle") {
        tempGraphic = new GRectangle();
    } else if (type == "circle") {
        tempGraphic = new GCircle();
    } else if (type == "triangle") {
        tempGraphic = new GTriangle();
    } else if (type == "hexagon") {
        tempGraphic = new GHexagon();
    } else if (type == "line") {
        tempGraphic = new GLine();
    }
    
    if (tempGraphic) {
        // 使用loadFromCoord方法计算图形信息
        tempGraphic->loadFromCoord(QVector2D(startX, startY), QVector2D(endX, endY));
        
        // GLine类会自动处理直线信息
        
        QVariantMap result = tempGraphic->info;
        delete tempGraphic;
        return result;
    }
    
    return QVariantMap();
}

QVariantList GraphicLogic::getLayerList()
{
    QVariantList layersList;
    
    // 获取按z层级排序的图形索引（从高到低显示）
    QList<int> orderedIndices = getGraphicsOrderByZ();
    
    // 反转列表，使高层级显示在顶部
    std::reverse(orderedIndices.begin(), orderedIndices.end());
    
    for (int i = 0; i < orderedIndices.size(); ++i) {
        int graphicIndex = orderedIndices[i];
        if (graphicIndex >= 0 && graphicIndex < list.size()) {
            QVariantMap layerInfo;
            QVariantMap graphicInfo = list[graphicIndex]->info;
            
            // 图层基本信息
            layerInfo["index"] = graphicIndex;
            layerInfo["zLevel"] = graphicInfo.value("z", 1).toInt();
            layerInfo["type"] = graphicInfo.value("type", "unknown").toString();
            layerInfo["visible"] = graphicInfo.value("visible", true).toBool();
            layerInfo["name"] = graphicInfo.value("name", "未命名").toString();

            layersList.append(layerInfo);
        }
    }
    
    return layersList;
}

void GraphicLogic::setGraphicVisibility(int index, bool visible)
{
    if (index >= 0 && index < list.size()) {
        list[index]->info["visible"] = visible;
        isSave = false;
    }
}

bool GraphicLogic::getGraphicVisibility(int index)
{
    if (index >= 0 && index < list.size()) {
        return list[index]->info.value("visible", true).toBool();
    }
    return false;
}

int GraphicLogic::getNo(int index)
{
    return list[index]->info["no"].toInt();
}

int GraphicLogic::getMaxNo()
{
    return maxNo;
}

void GraphicLogic::updateGraphicPosition(int index, qreal deltaX, qreal deltaY)
{
    if (index >= 0 && index < list.size()) {
        list[index]->updatePosition(QVector2D(deltaX, deltaY));
        isSave = false;
    }
}
