#include "ArcherTank.hpp"

ArcherTank::ArcherTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 120;
    // type = new CombatObjectType(120, 20, 1);
    type = combatObjectTypeFactory->getCombatObjectType(120, 20, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.1;
    critAbsorption = 0.3;
    objectType = ARCH_TANK;
}

// std::string ArcherTank::getObjectType() { return "ArcherTank"; }

// v8::Local<v8::Object> ArcherTank::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjProperty(info, "objectType", getObjectType());
//     GetObjProperty(info, "stats", stats);
//     SetObjProperty(stats, "critInfo", UnitTank::getCritInfo());
//     SetObjProperty(info, "stats", stats);
// }