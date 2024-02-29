set (BOOST_ROOT "c:/local/boost_1_82_0/")
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

set(CMAKE_DEBUG_POSTFIX d)

set(utils_DIR "${CMAKE_SOURCE_DIR}/libs/utils/lib/cmake/utils")
set(modbus_DIR "${CMAKE_SOURCE_DIR}/libs/modbus/lib/cmake/modbus")
set(threadpooling_DIR "${CMAKE_SOURCE_DIR}/libs/threadpooling/lib/cmake/threadpooling")
set(modbuswrappers_DIR "${CMAKE_SOURCE_DIR}/libs/modbuswrappers/lib/cmake/modbuswrappers")