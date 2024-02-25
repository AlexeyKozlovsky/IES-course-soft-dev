cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include (env.cmake)

add_executable(${PROJECT_NAME} main.cpp)
