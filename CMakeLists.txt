cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

include_directories(${CMAKE_SOURCE_DIR})

find_package(Boost REQUIRED)
find_package(utils REQUIRED)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/modbus/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)

if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()

if(WIN32)
    find_library(WSOCK32_LIBRARY wsock32)
    find_library(WS2_32_LIBRARY ws2_32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()

target_link_libraries(${PROJECT_NAME} utils::utils)