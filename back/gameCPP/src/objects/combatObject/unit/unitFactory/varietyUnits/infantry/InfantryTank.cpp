#include "InfantryTank.hpp"

InfantryTank::InfantryTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 175;
    // type = new CombatObjectType(175, 30, 3);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.15;
    critAbsorption = 0.5;
}

// std::string InfantryTank::getObjectType() { return "InfantryTank"; }

// v8::Local<v8::Object> InfantryTank::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjField(info, "objectType", getObjectType());
//     GetObjField(info, "stats", stats);
//     SetObjField(stats, "critInfo", UnitTank::getCritInfo());
//     SetObjField(info, "stats", stats);
// }