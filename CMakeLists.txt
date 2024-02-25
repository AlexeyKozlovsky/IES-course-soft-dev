cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)

include(env.cmake)
include_directories(${CMAKE_SOURCE_DIR})

find_package(utils REQUIRED)

file(GLOB SRC

        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)
target_link_libraries(${PROJECT_NAME} utils::utils)
