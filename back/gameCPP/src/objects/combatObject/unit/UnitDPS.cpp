#include "UnitDPS.hpp"

double UnitDPS::getDamageAttack()
{
    std::srand((unsigned int)time(nullptr));
    if ((std::rand() % 10) * 0.1 < critChance)
        return this->getDamage() * critDamage;
    return this->getDamage();
}

v8::Local<v8::Object> UnitDPS::getFullInfo()
{
    v8::Local<v8::Object> info = Unit::getFullInfo();
    v8::Local<v8::Object> stats;

    GetObjField(info, "stats", stats);
    SetObjField(stats, "critChance", critChance);
    SetObjField(stats, "critDamage", critDamage);
    SetObjField(info, "stats", stats);
    return info;
}
