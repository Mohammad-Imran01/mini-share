cmake_minimum_required(VERSION 3.16)

project(mini-share VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network)

qt_standard_project_setup()

qt_add_executable(appmini-share
    main.cpp
)

qt_add_qml_module(appmini-share
    URI mini-share
    VERSION 1.0
    QML_FILES

        SOURCES src/networkhandler.h src/networkhandler.cpp
        SOURCES src/receiverhandler.h src/receiverhandler.cpp
        SOURCES src/sendhandler.h src/sendhandler.cpp
        SOURCES src/gui/mainwindow.h src/gui/mainwindow.cpp
        SOURCES src/gui/mainwindow.cpp src/gui/mainwindow.h
        QML_FILES ui/common/CxHamburger.qml ui/main.qml
        QML_FILES ui/common/CxButton.qml
        QML_FILES ui/common/CxAboutNetwork.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appmini-share PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appmini-share
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appmini-share
    PRIVATE Qt6::Quick Qt6::Network
)

include(GNUInstallDirs)
install(TARGETS appmini-share
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
