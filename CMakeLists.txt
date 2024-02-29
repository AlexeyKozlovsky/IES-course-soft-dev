cmake_minimum_required(VERSION 3.24)
project(device_entity_project)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

include_directories(${CMAKE_SOURCE_DIR})

find_package(Boost REQUIRED)
find_package(utils REQUIRED)
find_package(modbus REQUIRED)
find_package(threadpooling REQUIRED)
find_package(modbuswrappers REQUIRED)

set(CMAKE_DEBUG_POSTFIX d CACHE INTERNAL "" FORCE)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/device/entity/*.cpp"
        "${CMAKE_SOURCE_DIR}/device/entity/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/device/entity/impls/*.cpp"
        "${CMAKE_SOURCE_DIR}/device/entity/impls/standaloneimpl1/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)

target_link_libraries(${PROJECT_NAME}
        utils::utils
        modbus::modbus
        threadpooling::threadpooling
        modbuswrappers::modbuswrappers
        )

if(WIN32)
    find_library(WSOCK32_LIBRARY wsock32)
    find_library(WS2_32_LIBRARY ws2_32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()

if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()


