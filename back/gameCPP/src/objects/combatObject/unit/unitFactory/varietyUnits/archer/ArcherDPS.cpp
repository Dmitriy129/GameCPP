
#include "ArcherDPS.hpp"

ArcherDPS::ArcherDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 80;
    // type = new CombatObjectType(80, 40, 1);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.2;
    critDamage = 2;
    objectType = ARCH_DPS;
}

// std::string ArcherDPS::getObjectType() { return "ArcherDPS"; }

// v8::Local<v8::Object> ArcherDPS::getFullInfo()
// {
//     v8::Local<v8::Object> info = UnitDPS::getFullInfo();

//     return info;
// }