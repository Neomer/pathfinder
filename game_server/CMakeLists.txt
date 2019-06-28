cmake_minimum_required(VERSION 3.14)
project(game_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(game_server main.cpp core/string_functions.h
        Logger.h Logger.cpp)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(websockets wsock32 ws2_32)
endif()