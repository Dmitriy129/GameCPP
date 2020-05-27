
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
    objectType = "ArcherDPS";
}

// std::string ArcherDPS::getObjectType() { return "ArcherDPS"; }

// v8::Local<v8::Object> ArcherDPS::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjProperty(info, "objectType", getObjectType());
//     GetObjProperty(info, "stats", stats);
//     SetObjProperty(stats, "critInfo", UnitDPS::getCritInfo());
//     SetObjProperty(info, "stats", stats);
// }