cmake_minimum_required(VERSION 3.16)

project(practica_proye LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(practica_proye
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Client.cpp
    Client.h
    Medicine.cpp
    Medicine.h
)

target_link_libraries(practica_proye PRIVATE Qt6::Widgets)