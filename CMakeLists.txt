cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/widgets/*.cpp")

add_executable(${PROJECT_NAME} ${SRC} main.cpp)
target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets)