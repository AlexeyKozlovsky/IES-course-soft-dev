cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/examples/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)
