
#include "InfantryDPS.hpp"

InfantryDPS::InfantryDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 150;
    // type = new CombatObjectType(150, 60, 2);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.2;
    critDamage = 2.3;
}
// std::string InfantryDPS::getObjectType() { return "InfantryDPS"; }

// v8::Local<v8::Object> InfantryDPS::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjField(info, "objectType", getObjectType());
//     GetObjField(info, "stats", stats);
//     SetObjField(stats, "critInfo", UnitDPS::getCritInfo());
//     SetObjField(info, "stats", stats);
// }