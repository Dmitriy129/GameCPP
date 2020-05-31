#include "CavalryTank.hpp"

CavalryTank::CavalryTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 175;
    // type = new CombatObjectType(175, 30, 3);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.15;
    critAbsorption = 0.5;
    objectType = CAV_TANK;
}

// std::string CavalryTank::getObjectType() { return "CavalryTank"; }

// v8::Local<v8::Object> CavalryTank::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjProperty(info, "objectType", getObjectType());
//     GetObjProperty(info, "stats", stats);
//     SetObjProperty(stats, "critInfo", UnitTank::getCritInfo());
//     SetObjProperty(info, "stats", stats);
// }