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
    objectType = INF_TANK;
}

// std::string InfantryTank::getObjectType() { return "InfantryTank"; }

// v8::Local<v8::Object> InfantryTank::getFullInfo()
// {
//     v8::Local<v8::Object> info = UnitTank::getFullInfo();

//     return info;
// }