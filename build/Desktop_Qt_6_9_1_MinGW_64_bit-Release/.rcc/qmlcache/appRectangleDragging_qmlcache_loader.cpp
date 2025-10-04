#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_RectangleDragging_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_MainPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_MyButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_PaintPage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_MyDialog_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_GCanvas_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_RightPanel_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_RectangleDragging_ToolsPanel_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/MainPage.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_MainPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/MyButton.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_MyButton_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/PaintPage.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_PaintPage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/MyDialog.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_MyDialog_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/GCanvas.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_GCanvas_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/RightPanel.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_RightPanel_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/RectangleDragging/ToolsPanel.qml"), &QmlCacheGeneratedCode::_qt_qml_RectangleDragging_ToolsPanel_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appRectangleDragging)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appRectangleDragging))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appRectangleDragging)() {
    return 1;
}
