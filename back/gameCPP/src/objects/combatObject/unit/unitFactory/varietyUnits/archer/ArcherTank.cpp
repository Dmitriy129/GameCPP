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
}

// std::string ArcherTank::getObjectType() { return "ArcherTank"; }

// v8::Local<v8::Object> ArcherTank::getInfo()
// {
//     v8::Local<v8::Object> info = Unit::getInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjField(info, "objectType", getObjectType());
//     GetObjField(info, "stats", stats);
//     SetObjField(stats, "critInfo", UnitTank::getCritInfo());
//     SetObjField(info, "stats", stats);
// }