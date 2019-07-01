cmake_minimum_required(VERSION 3.14)
project(game_server)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp core/string_functions.h
        Logger.h Logger.cpp
        network/Sockets.h network/TcpSocket.cpp network/TcpSocket.h network/IConnectionAcceptedListener.h network/IDataArrivedListener.h network/IConnectionClosedListener.h network/TcpServer.cpp network/TcpServer.h network/WebSocketServer.cpp network/WebSocketServer.h network/WebSocket.cpp network/WebSocket.h game/cards/Metadata.cpp game/cards/Metadata.h game/cards/Card.cpp game/cards/Card.h game/cards/HandTakableCardMetadata.cpp game/cards/HandTakableCardMetadata.h game/CardMetadataProvider.cpp game/CardMetadataProvider.h game/cards/WeaponCard.cpp game/cards/WeaponCard.h game/cards/BlessingCard.cpp game/cards/BlessingCard.h game/cards/ArmorCard.cpp game/cards/ArmorCard.h game/cards/ThingCard.cpp game/cards/ThingCard.h game/cards/MonsterCard.cpp game/cards/MonsterCard.h game/cards/SpellCard.cpp game/cards/SpellCard.h game/cards/spells/HealCard.cpp game/cards/spells/HealCard.h game/cards/scenario/Rubiih.cpp game/cards/scenario/Rubiih.h game/cards/scenario/Scenario.cpp game/cards/scenario/Scenario.h game/cards/locations/LocationCard.cpp game/cards/locations/LocationCard.h game/cards/locations/ForestLocationCard.cpp game/cards/locations/ForestLocationCard.h game/cards/armors/MagicChainMail.cpp game/cards/armors/MagicChainMail.h game/cards/armors/MagicShield.cpp game/cards/armors/MagicShield.h game/cards/things/AmuletOfLife.cpp game/cards/things/AmuletOfLife.h game/Game.cpp game/Game.h network/packages/Package.cpp network/packages/Package.h network/packages/GetLocationsPackage.cpp network/packages/GetLocationsPackage.h game/Player.cpp game/Player.h
        game/cards/monsters/Bagbier.cpp game/cards/monsters/Bagbier.h
        game/cards/monsters/Cultist.cpp game/cards/monsters/Cultist.h
        game/cards/servants/ElderSkeleton.cpp game/cards/servants/ElderSkeleton.h
        game/cards/servants/PoisonTrap.h game/cards/servants/PoisonTrap.cpp
        game/cards/servants/Rogue.cpp game/cards/servants/Rogue.h
        game/cards/MonsterCard.h game/cards/MonsterCard.cpp
        game/cards/ServantCard.h game/cards/ServantCard.cpp
        network/IWebSocketSessionInitListener.h
        game/cards/monsters/Banip.cpp game/cards/monsters/Banip.h
        game/cards/monsters/SpellCaster.cpp game/cards/monsters/SpellCaster.h
        game/cards/monsters/Ghost.cpp game/cards/monsters/Ghost.h
        game/cards/monsters/Ghoul.cpp game/cards/monsters/Ghoul.h
        game/cards/monsters/GiantGecko.cpp game/cards/monsters/GiantGecko.h
        game/cards/monsters/GoblinSaboteur.cpp game/cards/monsters/GoblinSaboteur.h
        game/cards/monsters/GoblinFighter.cpp game/cards/monsters/GoblinFighter.h
        game/cards/monsters/Mercenary.cpp game/cards/monsters/Mercenary.h
        game/cards/monsters/HillGiant.cpp game/cards/monsters/HillGiant.h
        game/cards/monsters/Ogre.cpp game/cards/monsters/Ogre.h)

add_executable(game_server ${SOURCES})

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(game_server wsock32 ws2_32)
endif()