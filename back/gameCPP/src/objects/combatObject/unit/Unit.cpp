
#include "Unit.hpp"

Unit::~Unit()
{
    delete type;
}
void Unit::operator+(Object *object) {}

bool Unit::isMoveable() { return true; }
// std::string Unit::getPlayerID() { return playerID; }
// std::string Unit::getObjectType() { return "Unit"; }

/*
void Unit::setHealth(double health)
{
    if (health < 0)
        death();
    else
    {
        // // // std::cout << "#unit ev updd#\n";
        fireEvent("object updated");
    }

    this->health = health;
}

double Unit::getHealth() const { return health; }
double Unit::getMaxHealth() const { return type->getMaxHealth(); }
double Unit::getDamage() const { return type->getDamage(); }
double Unit::getArmor() const { return type->getArmor(); } */

void Unit::death() { fireEvent("object death"); }

// void UnitDPS::underAttack(double damage, double armor)
// {
//     damage = damage * (1 + (armor - this->type->getArmor()) / 10);
//     this->setHealth(this->getHealth() - damage);
// }

v8::Local<v8::Object> Unit::getFullInfo()
{
    v8::Local<v8::Object> info = CombatObject::getFullInfo();

    return info;
}
void Unit::eventHandler(Event *event){};