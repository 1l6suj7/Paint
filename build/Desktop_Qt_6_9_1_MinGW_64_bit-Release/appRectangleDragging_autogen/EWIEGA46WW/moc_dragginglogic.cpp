/****************************************************************************
** Meta object code from reading C++ file 'dragginglogic.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../dragginglogic.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dragginglogic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13DraggingLogicE_t {};
} // unnamed namespace

template <> constexpr inline auto DraggingLogic::qt_create_metaobjectdata<qt_meta_tag_ZN13DraggingLogicE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DraggingLogic",
        "saveSucceeded",
        "",
        "saveFailed",
        "loadSucceeded",
        "loadFailed",
        "getInfo",
        "QVariantMap",
        "index",
        "newGraphic",
        "info",
        "modifyGraphic",
        "saveAsFile",
        "url",
        "loadFromFile",
        "getIsSave",
        "getGraphicsCount",
        "isPointInGraphic",
        "x",
        "y",
        "deleteGraphic",
        "clearAllGraphics",
        "getMaxZLevel",
        "moveGraphicToTop",
        "moveGraphicToBottom",
        "moveGraphicUp",
        "moveGraphicDown",
        "getGraphicsOrderByZ",
        "QList<int>",
        "getPreviewGraphicInfo",
        "type",
        "startX",
        "startY",
        "endX",
        "endY",
        "getLayersList",
        "QVariantList",
        "setGraphicVisibility",
        "visible",
        "getGraphicVisibility"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'saveSucceeded'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'saveFailed'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadSucceeded'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadFailed'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'getInfo'
        QtMocHelpers::SlotData<QVariantMap(int)>(6, 2, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'newGraphic'
        QtMocHelpers::SlotData<void(QVariantMap)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 10 },
        }}),
        // Slot 'modifyGraphic'
        QtMocHelpers::SlotData<void(int, QVariantMap)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { 0x80000000 | 7, 10 },
        }}),
        // Slot 'saveAsFile'
        QtMocHelpers::SlotData<void(QUrl)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 13 },
        }}),
        // Slot 'loadFromFile'
        QtMocHelpers::SlotData<void(QUrl)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 13 },
        }}),
        // Slot 'getIsSave'
        QtMocHelpers::SlotData<bool()>(15, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'getGraphicsCount'
        QtMocHelpers::SlotData<int()>(16, 2, QMC::AccessPublic, QMetaType::Int),
        // Slot 'isPointInGraphic'
        QtMocHelpers::SlotData<bool(int, qreal, qreal)>(17, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 8 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 },
        }}),
        // Slot 'deleteGraphic'
        QtMocHelpers::SlotData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'clearAllGraphics'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'getMaxZLevel'
        QtMocHelpers::SlotData<int()>(22, 2, QMC::AccessPublic, QMetaType::Int),
        // Slot 'moveGraphicToTop'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'moveGraphicToBottom'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'moveGraphicUp'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'moveGraphicDown'
        QtMocHelpers::SlotData<void(int)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'getGraphicsOrderByZ'
        QtMocHelpers::SlotData<QList<int>()>(27, 2, QMC::AccessPublic, 0x80000000 | 28),
        // Slot 'getPreviewGraphicInfo'
        QtMocHelpers::SlotData<QVariantMap(QString, qreal, qreal, qreal, qreal)>(29, 2, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::QString, 30 }, { QMetaType::QReal, 31 }, { QMetaType::QReal, 32 }, { QMetaType::QReal, 33 },
            { QMetaType::QReal, 34 },
        }}),
        // Slot 'getLayersList'
        QtMocHelpers::SlotData<QVariantList()>(35, 2, QMC::AccessPublic, 0x80000000 | 36),
        // Slot 'setGraphicVisibility'
        QtMocHelpers::SlotData<void(int, bool)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { QMetaType::Bool, 38 },
        }}),
        // Slot 'getGraphicVisibility'
        QtMocHelpers::SlotData<bool(int)>(39, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DraggingLogic, qt_meta_tag_ZN13DraggingLogicE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DraggingLogic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DraggingLogicE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DraggingLogicE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13DraggingLogicE_t>.metaTypes,
    nullptr
} };

void DraggingLogic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DraggingLogic *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->saveSucceeded(); break;
        case 1: _t->saveFailed(); break;
        case 2: _t->loadSucceeded(); break;
        case 3: _t->loadFailed(); break;
        case 4: { QVariantMap _r = _t->getInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->newGraphic((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 6: _t->modifyGraphic((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 7: _t->saveAsFile((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 8: _t->loadFromFile((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 9: { bool _r = _t->getIsSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->getGraphicsCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->isPointInGraphic((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->deleteGraphic((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->clearAllGraphics(); break;
        case 14: { int _r = _t->getMaxZLevel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->moveGraphicToTop((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->moveGraphicToBottom((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->moveGraphicUp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->moveGraphicDown((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: { QList<int> _r = _t->getGraphicsOrderByZ();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 20: { QVariantMap _r = _t->getPreviewGraphicInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 21: { QVariantList _r = _t->getLayersList();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->setGraphicVisibility((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 23: { bool _r = _t->getGraphicVisibility((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DraggingLogic::*)()>(_a, &DraggingLogic::saveSucceeded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggingLogic::*)()>(_a, &DraggingLogic::saveFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggingLogic::*)()>(_a, &DraggingLogic::loadSucceeded, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggingLogic::*)()>(_a, &DraggingLogic::loadFailed, 3))
            return;
    }
}

const QMetaObject *DraggingLogic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DraggingLogic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DraggingLogicE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DraggingLogic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void DraggingLogic::saveSucceeded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DraggingLogic::saveFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DraggingLogic::loadSucceeded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DraggingLogic::loadFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
