cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include (env.cmake)
include_directories(${CMAKE_SOURCE_DIR})


file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/services/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/dataproviders/*.cpp"
        "${CMAKE_SOURCE_DIR}/services/dataproviderfactories/*.cpp"
        )


add_executable(${PROJECT_NAME} ${SRC} main.cpp)