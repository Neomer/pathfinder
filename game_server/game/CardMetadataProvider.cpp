//
// Created by vinokurov on 29.06.2019.
//


#include <algorithm>
#include <string>
#include "CardMetadataProvider.h"
#include "cards/Card.h"
#include "../Logger.h"

using namespace std::string_literals;

CardMetadataProvider &CardMetadataProvider::getInstance()
{
    static CardMetadataProvider instance;
    return instance;
}

const CardMetadata *CardMetadataProvider::getMetadata(int typeId) const
{
    auto it = std::find_if(_metadataVector.begin(), _metadataVector.end(),
                           [typeId](const CardMetadata *metadata) -> bool {
                               return metadata->TypeId() == typeId;
                           });
    return it == _metadataVector.end() ? nullptr : *it;
}

std::vector<const CardMetadata *> CardMetadataProvider::getMetadata(std::function<bool(const CardMetadata *metadata)> comparator) const
{
    std::vector<const CardMetadata *> result;
    for (auto metadata : _metadataVector) {
        if (comparator(metadata)) {
            result.push_back(metadata);
        }
    }
    return result;
}

CardMetadataProvider::CardMetadataProvider()
{

}

void CardMetadataProvider::registerMetadata(CardMetadata *metadata)
{
    if (getMetadata(metadata->TypeId()) != nullptr) {
        throw std::logic_error("Метаданные с идентификатором типа "s + std::to_string(metadata->TypeId()) + " уже зарегистрирован! Не удалось зарегистрировать тип: " + metadata->getTypeName());
    }
    _metadataVector.push_back(metadata);
}

#include "cards/spells/HealCard.h"
#include "cards/armors/MagicChainMail.h"
#include "cards/armors/MagicShield.h"
#include "cards/armors/ChainMail.h"
#include "cards/armors/ElvenChainMail.h"
#include "cards/armors/Breastplate.h"
#include "cards/armors/LeatherArmor.h"
#include "cards/armors/MagicBreastplate.h"
#include "cards/things/AmuletOfLife.h"
#include "cards/locations/ForestLocationCard.h"
#include "cards/scenario/Rubiih.h"
#include "cards/servants/ElderSkeleton.h"
#include "cards/servants/PoisonTrap.h"
#include "cards/servants/Rogue.h"
#include "cards/monsters/Bagbier.h"
#include "cards/monsters/Cultist.h"
#include "cards/monsters/Banip.h"
#include "cards/monsters/SpellCaster.h"
#include "cards/monsters/Ghost.h"
#include "cards/monsters/Ghoul.h"
#include "cards/monsters/GiantGecko.h"
#include "cards/monsters/GoblinSaboteur.h"
#include "cards/monsters/GoblinFighter.h"
#include "cards/monsters/Mercenary.h"
#include "cards/monsters/HillGiant.h"
#include "cards/monsters/Ogre.h"
#include "cards/monsters/PlagueZombie.h"
#include "cards/monsters/Scout.h"
#include "cards/monsters/Shadow.h"
#include "cards/monsters/Siren.h"
#include "cards/monsters/Skeleton.h"
#include "cards/monsters/Zombie.h"
#include "cards/weapons/SesquialteralSword.h"
#include "cards/weapons/BattleAxe.h"
#include "cards/weapons/Dagger.h"
#include "cards/weapons/Darts.h"
#include "cards/weapons/FlamingMace.h"
#include "cards/weapons/Glaive.h"
#include "cards/weapons/TwoHandAxe.h"
#include "cards/weapons/HeavyCrossbow.h"
#include "cards/weapons/LightCrossbow.h"
#include "cards/weapons/LongBow.h"
#include "cards/weapons/LongSpear.h"
#include "cards/weapons/LongSword.h"
#include "cards/weapons/Mace.h"
#include "cards/weapons/BattleStaff.h"
#include "cards/bosses/DjabralWiskey.h"
#include "cards/roles/Ezren.h"
#include "cards/roles/Harsk.h"
#include "cards/roles/Kaira.h"

void CardMetadataProvider::init()
{
    Logger::getInstace().log("Start cards metadata initialization");

    //region Spell metadata
    //registerMetadata(new HealCardMetadata());
    //endregion

    //region Armor metadata
    registerMetadata(new MagicChainMailMetadata());
    registerMetadata(new MagicShieldMetadata());
    registerMetadata(new ChainMailMetadata());
    registerMetadata(new ElvenChainMailMetadata());
    registerMetadata(new BreastplateMetadata());
    registerMetadata(new LeatherArmorMetadata());
    registerMetadata(new MagicBreastplateMetadata());
    //endregion

    //region Thing metadata
    //registerMetadata(new AmuletOfLifeMetadata());
    //endregion

    //region Location metadata
    registerMetadata(new ForestLocationCardMetadata());
    //endregion

    //region Scenario metadata
    registerMetadata(new RubiihMetadata());
    //endregion

    //region Servant metadata
    registerMetadata(new ElderSkeletonCardMetadata());
    registerMetadata(new PoisonTrapCardMetadata());
    registerMetadata(new RogueCardMetadata());
    //endregion

    //region Monster metadata
    registerMetadata(new BagbierCardMetadata());
    registerMetadata(new CultistCardMetadata());
    registerMetadata(new BanipMetadata());
    registerMetadata(new SpellCasterMetadata());
    registerMetadata(new GhostMetadata());
    registerMetadata(new GhoulMetadata());
    registerMetadata(new GiantGeckoMetadata());
    registerMetadata(new GoblinSaboteurMetadata());
    registerMetadata(new GoblinFighterMetadata());
    registerMetadata(new MercenaryMetadata());
    registerMetadata(new HillGiantMetadata());
    registerMetadata(new OgreMetadata());
    registerMetadata(new PlagueZombieMetadata());
    registerMetadata(new ScoutMetadata());
    registerMetadata(new ShadowMetadata());
    registerMetadata(new SirenMetadata());
    registerMetadata(new SkeletonMetadata());
    registerMetadata(new ZombieMetadata());
    //endregion

    //region Weapon metadata
    registerMetadata(new SesquialteralSwordMetadata());
    registerMetadata(new BattleAxeMetadata());
    registerMetadata(new DaggerMetadata());
    registerMetadata(new DartsMetadata());
    registerMetadata(new FlamingMaceMetadata());
    registerMetadata(new GlaiveMetadata());
    registerMetadata(new TwoHandAxeMetadata());
    registerMetadata(new HeavyCrossbowMetadata());
    registerMetadata(new LightCrossbowMetadata());
    registerMetadata(new LongBowMetadata());
    registerMetadata(new LongSpearMetadata());
    registerMetadata(new LongSwordMetadata());
    registerMetadata(new MaceMetadata());
    registerMetadata(new BattleStaffMetadata());
    //endregion

    //region Boss metadata
    registerMetadata(new DjabralWiskeyMetadata());
    //endregion

    //region Role metadata
    registerMetadata(new EzrenMetadata());
    registerMetadata(new HarskMetadata());
    registerMetadata(new KairaMetadata());
    //endregion

    for (auto metadata : _metadataVector) {
        metadata->load();
    }

    Logger::getInstace().log("Initialization finished. Total cards metadata count: "s + std::to_string(_metadataVector.size()));
}
