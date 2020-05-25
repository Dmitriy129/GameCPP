#include "UnitTank.hpp"

void UnitTank::underAttack(double damage, double armor)
{
    std::srand((unsigned int)time(nullptr));
    if ((std::rand() % 10) * 0.1 < critChance)
        damage = damage / critAbsorption;
    damage = damage * (1 + (armor - this->type->getArmor()) / 10);
    this->setHealth(this->getHealth() - damage);
}

v8::Local<v8::Object> UnitTank::getInfo()
{
    v8::Local<v8::Object> info = Unit::getInfo();
    v8::Local<v8::Object> stats;

    GetObjField(info, "stats", stats);
    SetObjField(stats, "critChance", critChance);
    SetObjField(stats, "critAbsorption", critAbsorption);
    SetObjField(info, "stats", stats);
    return info;
}
