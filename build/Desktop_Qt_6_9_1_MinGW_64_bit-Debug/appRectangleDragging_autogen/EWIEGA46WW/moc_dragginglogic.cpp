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
        "setCoord",
        "newX",
        "newY",
        "setScale",
        "newWidth",
        "newHeight",
        "getInfo",
        "QVariantMap",
        "saveAsFile",
        "url",
        "loadFromFile",
        "getIsSave"
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
        // Slot 'setCoord'
        QtMocHelpers::SlotData<void(qreal, qreal)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 7 }, { QMetaType::QReal, 8 },
        }}),
        // Slot 'setScale'
        QtMocHelpers::SlotData<void(qreal, qreal)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 10 }, { QMetaType::QReal, 11 },
        }}),
        // Slot 'getInfo'
        QtMocHelpers::SlotData<QVariantMap()>(12, 2, QMC::AccessPublic, 0x80000000 | 13),
        // Slot 'saveAsFile'
        QtMocHelpers::SlotData<void(QUrl)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 15 },
        }}),
        // Slot 'loadFromFile'
        QtMocHelpers::SlotData<void(QUrl)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 15 },
        }}),
        // Slot 'getIsSave'
        QtMocHelpers::SlotData<bool()>(17, 2, QMC::AccessPublic, QMetaType::Bool),
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
        case 4: _t->setCoord((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 5: _t->setScale((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 6: { QVariantMap _r = _t->getInfo();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->saveAsFile((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 8: _t->loadFromFile((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 9: { bool _r = _t->getIsSave();
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
