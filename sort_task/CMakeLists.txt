cmake_minimum_required(VERSION 3.14)

project(sort_task LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)  # Require Core component

add_executable(sort_task
  main.cpp
)

target_link_libraries(sort_task PRIVATE Qt${QT_VERSION_MAJOR}::Core)  # Link against Qt Core

include(GNUInstallDirs)
install(TARGETS sort_task
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
