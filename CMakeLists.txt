cmake_minimum_required(VERSION 3.24)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)
include(env.cmake)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

find_package(Boost REQUIRED)
find_package(utils REQUIRED)
find_package(modbus REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB SRC
        "${CMAKE_SOURCE_DIR}/command/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC} main.cpp)
target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
        utils::utils
        modbus::modbus
        )

if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()