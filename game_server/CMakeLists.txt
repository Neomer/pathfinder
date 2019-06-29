cmake_minimum_required(VERSION 3.14)
project(game_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(game_server main.cpp core/string_functions.h
        Logger.h Logger.cpp
        network/Sockets.h network/TcpSocket.cpp network/TcpSocket.h network/IConnectionAcceptedListener.h network/IDataArrivedListener.h network/IConnectionClosedListener.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(game_server wsock32 ws2_32)
endif()