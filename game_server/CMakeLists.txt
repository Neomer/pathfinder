cmake_minimum_required(VERSION 3.14)
project(game_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(game_server main.cpp core/string_functions.h
        Logger.h Logger.cpp
        network/Sockets.h network/TcpSocket.cpp network/TcpSocket.h network/IConnectionAcceptedListener.h network/IDataArrivedListener.h network/IConnectionClosedListener.h network/TcpServer.cpp network/TcpServer.h network/WebSocketServer.cpp network/WebSocketServer.h network/WebSocket.cpp network/WebSocket.h game/cards/Metadata.cpp game/cards/Metadata.h game/cards/Card.cpp game/cards/Card.h game/cards/HandTakableCardMetadata.cpp game/cards/HandTakableCardMetadata.h game/CardMetadataProvider.cpp game/CardMetadataProvider.h game/cards/WeaponCard.cpp game/cards/WeaponCard.h game/cards/BlessingCard.cpp game/cards/BlessingCard.h game/cards/ArmorCard.cpp game/cards/ArmorCard.h game/cards/ThingCard.cpp game/cards/ThingCard.h game/cards/MonsterCard.cpp game/cards/MonsterCard.h game/cards/SpellCard.cpp game/cards/SpellCard.h game/cards/spells/HealCard.cpp game/cards/spells/HealCard.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(game_server wsock32 ws2_32)
endif()