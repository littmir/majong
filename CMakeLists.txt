cmake_minimum_required(VERSION 3.16)

project(majong VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
  main.cpp
  src/common.h
  src/objects/border.cpp
  src/objects/border.h
  src/objects/card.cpp
  src/objects/card.h
  src/objects/gameobject.cpp
  src/objects/gameobject.h
  src/objects/line.cpp
  src/objects/line.h
  src/windows/mainwindow.cpp
  src/windows/mainwindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(majong MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
  add_executable(majong ${PROJECT_SOURCES})
endif()

target_include_directories(majong PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/windows
  ${CMAKE_CURRENT_SOURCE_DIR}/objects
)

target_link_libraries(majong PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(majong PROPERTIES
  ${BUNDLE_ID_OPTION}
  WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS majong
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(majong)
endif()
