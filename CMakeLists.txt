cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/observers/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/models/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/models/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/views/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/mvc/device/controllers/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)
target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets)