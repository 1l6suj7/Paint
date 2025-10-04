cmake_minimum_required(VERSION 3.16)

project(Paint VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appPaint
    main.cpp
)

qt_add_qml_module(appPaint
    URI Paint
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        SOURCES cpp/graphiclogic.h cpp/graphiclogic.cpp
        QML_FILES qml/MainPage.qml
        QML_FILES qml/MyButton.qml
        QML_FILES qml/PaintPage.qml
        QML_FILES qml/MyDialog.qml
        SOURCES cpp/abstractgraphic.h cpp/abstractgraphic.cpp
        SOURCES cpp/grectangle.h cpp/grectangle.cpp
        SOURCES cpp/gcircle.h cpp/gcircle.cpp
        SOURCES cpp/gtriangle.h cpp/gtriangle.cpp
        SOURCES cpp/ghexagon.h cpp/ghexagon.cpp
        SOURCES cpp/gline.h cpp/gline.cpp
        QML_FILES qml/GCanvas.qml
        QML_FILES qml/RightPanel.qml
        QML_FILES qml/ToolsPanel.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPaint PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPaint
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPaint
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPaint
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
