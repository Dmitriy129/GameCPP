
#include "CavalryDPS.hpp"

CavalryDPS::CavalryDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    health = 150;
    // type = new CombatObjectType(150, 60, 2);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    this->playerID = playerID;
    this->ID = unitID;

    critChance = 0.2;
    critDamage = 2.3;
    objectType = "CavalryDPS";
}
// std::string CavalryDPS::getObjectType() { return "CavalryDPS"; }

// v8::Local<v8::Object> CavalryDPS::getFullInfo()
// {
//     v8::Local<v8::Object> info = Unit::getFullInfo();
//     v8::Local<v8::Object> stats;

//     //SetObjProperty(info, "objectType", getObjectType());
//     GetObjProperty(info, "stats", stats);
//     SetObjProperty(stats, "critInfo", UnitDPS::getCritInfo());
//     SetObjProperty(info, "stats", stats);
// }