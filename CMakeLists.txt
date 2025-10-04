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
        Main.qml
        SOURCES Graphiclogic.h Graphiclogic.cpp
        QML_FILES MainPage.qml
        QML_FILES MyButton.qml
        QML_FILES PaintPage.qml
        QML_FILES MyDialog.qml
        SOURCES abstractgraphic.h abstractgraphic.cpp
        SOURCES grectangle.h grectangle.cpp
        SOURCES gcircle.h gcircle.cpp
        SOURCES gtriangle.h gtriangle.cpp
        SOURCES
        SOURCES ghexagon.h ghexagon.cpp
        SOURCES gline.h gline.cpp
        QML_FILES GCanvas.qml
        QML_FILES RightPanel.qml
        QML_FILES ToolsPanel.qml
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
