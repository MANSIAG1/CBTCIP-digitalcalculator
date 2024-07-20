cmake_minimum_required(VERSION 3.5)

project(calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt modules
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qml Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Qml Core)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calculator
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(calculator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(calculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link the Qt libraries
target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Qml Qt${QT_VERSION_MAJOR}::Core)

# Set bundle properties for macOS or iOS
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_finalize_executable(calculator)
endif()

include(GNUInstallDirs)
install(TARGETS calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
