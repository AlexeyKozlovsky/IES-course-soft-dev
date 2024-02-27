cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp cars/car.h cars/carbuilder.h cars/carimpls/kamaz.cpp cars/carimpls/kamaz.h cars/carimpls/honda.cpp cars/carimpls/honda.h cars/carbuilderimpls/carbuilderkamazimpl.cpp cars/carbuilderimpls/carbuilderkamazimpl.h)
