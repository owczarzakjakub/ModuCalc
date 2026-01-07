cmake_minimum_required(VERSION 3.16)

project(ModuCalc VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE CORE_SOURCES "src/core/core_placeholder.cpp" "src/core/core_placeholder.h")
file(GLOB_RECURSE HISTORY_SOURCES "src/history//history_placeholder.cpp" "src/history//history_placeholder.h")
file(GLOB_RECURSE MODULES_SOURCES "src/modules/modules_placeholder.cpp" "src/modules/modules_placeholder.h")
file(GLOB_RECURSE TYPES_SOURCES "src/types/types_placeholder.cpp" "src/types/types_placeholder.h")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${CORE_SOURCES}
        ${HISTORY_SOURCES}
        ${TYPES_SOURCES}
        ${MODULES_SOURCES}

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ModuCalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/core/token.h src/core/token.cpp
        src/core/lexer.h src/core/lexer.cpp
        src/core/parser.h src/core/parser.cpp
        src/core/evaluator.h src/core/evaluator.cpp
        src/history/historymanager.h src/history/historymanager.cpp
        src/history/scriptengine.h src/history/scriptengine.cpp
        src/modules/trigonometry.h src/modules/trigonometry.cpp
        src/modules/statistics.h src/modules/statistics.cpp

        src/types/number.h src/types/number.cpp
        src/types/complex.h src/types/complex.cpp
        src/types/vector.h src/types/vector.cpp
        src/types/matrix.h src/types/matrix.cpp
        src/core/TokenType.h
        src/core/solver.h src/core/solver.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ModuCalc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ModuCalc SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ModuCalc
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ModuCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ModuCalc)
endif()
set_target_properties(ModuCalc PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ModuCalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ModuCalc)
endif()
