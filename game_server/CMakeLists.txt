cmake_minimum_required(VERSION 3.8)
project(game_server)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp core/string_functions.h
        Logger.h Logger.cpp
        network/Sockets.h network/TcpSocket.cpp network/TcpSocket.h
        network/IConnectionAcceptedListener.h network/IDataArrivedListener.h
        network/IConnectionClosedListener.h
        network/TcpServer.cpp network/TcpServer.h
        network/WebSocketServer.cpp network/WebSocketServer.h
        network/WebSocket.cpp network/WebSocket.h
        game/cards/Metadata.cpp game/cards/Metadata.h
        game/cards/Card.cpp game/cards/Card.h
        game/cards/HandTakableCardMetadata.cpp game/cards/HandTakableCardMetadata.h
        game/CardMetadataProvider.cpp game/CardMetadataProvider.h
        game/cards/WeaponCard.cpp game/cards/WeaponCard.h
        game/cards/BlessingCard.cpp game/cards/BlessingCard.h
        game/cards/ArmorCard.cpp game/cards/ArmorCard.h
        game/cards/ThingCard.cpp game/cards/ThingCard.h
        game/cards/MonsterCard.cpp game/cards/MonsterCard.h
        game/cards/SpellCard.cpp game/cards/SpellCard.h
        game/cards/spells/HealCard.cpp game/cards/spells/HealCard.h
        game/cards/scenario/Rubiih.cpp game/cards/scenario/Rubiih.h
        game/cards/scenario/Scenario.cpp game/cards/scenario/Scenario.h
        game/cards/locations/LocationCard.cpp game/cards/locations/LocationCard.h
        game/cards/locations/ForestLocationCard.cpp game/cards/locations/ForestLocationCard.h
        game/cards/armors/MagicChainMail.cpp game/cards/armors/MagicChainMail.h
        game/cards/armors/MagicShield.cpp game/cards/armors/MagicShield.h
        game/cards/things/AmuletOfLife.cpp game/cards/things/AmuletOfLife.h
        game/Game.cpp game/Game.h
        network/packages/Package.cpp network/packages/Package.h
        network/packages/GetLocationsPackage.cpp network/packages/GetLocationsPackage.h
        game/Player.cpp game/Player.h
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
        game/cards/monsters/Ogre.cpp game/cards/monsters/Ogre.h
        game/cards/monsters/PlagueZombie.cpp game/cards/monsters/PlagueZombie.h
        game/cards/monsters/Scout.cpp game/cards/monsters/Scout.h
        game/cards/monsters/Shadow.cpp game/cards/monsters/Shadow.h
        game/cards/monsters/Siren.cpp game/cards/monsters/Siren.h
        game/cards/monsters/Skeleton.cpp game/cards/monsters/Skeleton.h
        game/cards/monsters/Zombie.cpp game/cards/monsters/Zombie.h
        game/cards/weapons/SesquialteralSword.cpp game/cards/weapons/SesquialteralSword.h
        game/cards/weapons/BattleAxe.cpp game/cards/weapons/BattleAxe.h
        game/cards/weapons/Dagger.cpp game/cards/weapons/Dagger.h
        game/cards/weapons/Darts.cpp game/cards/weapons/Darts.h
        game/cards/weapons/FlamingMace.cpp game/cards/weapons/FlamingMace.h
        game/cards/weapons/Glaive.cpp game/cards/weapons/Glaive.h
        game/cards/weapons/TwoHandAxe.cpp game/cards/weapons/TwoHandAxe.h
        game/cards/weapons/HeavyCrossbow.cpp game/cards/weapons/HeavyCrossbow.h
        game/cards/weapons/LightCrossbow.cpp game/cards/weapons/LightCrossbow.h
        game/cards/weapons/LongBow.cpp game/cards/weapons/LongBow.h
        game/cards/weapons/LongSpear.cpp game/cards/weapons/LongSpear.h
        game/cards/weapons/LongSword.cpp game/cards/weapons/LongSword.h
        game/cards/weapons/Mace.cpp game/cards/weapons/Mace.h
        game/cards/weapons/BattleStaff.cpp game/cards/weapons/BattleStaff.h
        game/cards/bosses/DjabralWiskey.cpp game/cards/bosses/DjabralWiskey.h
        game/cards/BossCard.cpp game/cards/BossCard.h
        game/Deck.cpp game/Deck.h
        game/cards/roles/Ezren.cpp game/cards/roles/Ezren.h
        game/cards/RoleCard.cpp game/cards/RoleCard.h
        game/cards/roles/Harsk.cpp game/cards/roles/Harsk.h game/cards/armors/ChainMail.cpp game/cards/armors/ChainMail.h game/cards/armors/ElvenChainMail.cpp game/cards/armors/ElvenChainMail.h game/cards/armors/Breastplate.cpp game/cards/armors/Breastplate.h game/cards/armors/LeatherArmor.cpp game/cards/armors/LeatherArmor.h game/cards/armors/MagicBreastplate.cpp game/cards/armors/MagicBreastplate.h game/cards/roles/Kaira.cpp game/cards/roles/Kaira.h game/cards/spells/AcidArrow.cpp game/cards/spells/AcidArrow.h game/cards/spells/Help.cpp game/cards/spells/Help.h game/cards/spells/MysticalArmor.cpp game/cards/spells/MysticalArmor.h game/cards/spells/Divination.cpp game/cards/spells/Divination.h game/cards/spells/Charm.cpp game/cards/spells/Charm.h game/cards/spells/EvilDetection.cpp game/cards/spells/EvilDetection.h game/cards/spells/MagicDetection.cpp game/cards/spells/MagicDetection.h game/cards/CompanionCard.cpp game/cards/CompanionCard.h game/cards/companions/Burglar.cpp game/cards/companions/Burglar.h network/RestServer.cpp network/RestServer.h network/RestSocket.cpp network/RestSocket.h)

add_executable(game_server ${SOURCES})

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(game_server wsock32 ws2_32)
endif()