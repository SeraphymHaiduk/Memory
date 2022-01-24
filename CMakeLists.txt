cmake_minimum_required(VERSION 3.10.0)

set(PROJECT Memory)

project(${PROJECT})

set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_INCLUDE_CURRENT_DIR on)

#set(QT_USE_QTGUI TRUE)
#set(QT_USE_QTXML TRUE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(Qt5 REQUIRED Qml Quick Gui)
find_package(Qt5QuickCompiler)


add_executable(${PROJECT}
    main.cpp
    logic.cpp
    dataprovider.cpp
    qml.qrc
    main.qml
    Card.qml
    Field.qml
    MyButton.qml
    ScoreMenu.qml
    NewGameMenu.qml
    SessionStatus.qml
    )
qtquick_compiler_add_resources(qml.qrc)

target_link_libraries (${PROJECT}
    Qt5::Core
    Qt5::Qml
    Qt5::Quick
    Qt5::Gui
    )
