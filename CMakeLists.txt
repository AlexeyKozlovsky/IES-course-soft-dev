cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

include_directories(${CMAKE_SOURCE_DIR})

find_package(Boost REQUIRED)
find_package(utils REQUIRED)
find_package(modbus REQUIRED)
find_package(threadpooling REQUIRED)

set(CMAKE_DEBUG_POSTFIX d CACHE INTERNAL "" FORCE)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/modbuswrappers/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/mocks/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/modbusclientwrapper/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/modbusclientidwrapper/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/modbusasyncclientwrapper/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/modbusdividableclientwrapper/*.cpp"
        "${CMAKE_SOURCE_DIR}/modbuswrappers/factories/*.cpp"
        "${CMAKE_SOURCE_DIR}/state/*.cpp"
        "${CMAKE_SOURCE_DIR}/state/states/*.cpp"
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

target_link_libraries(${PROJECT_NAME}
        utils::utils
        modbus::modbus
        threadpooling::threadpooling)