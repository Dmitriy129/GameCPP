#include "CombatObject.hpp"

CombatObject::~CombatObject()
{
    type = nullptr;
}
// void CombatObject::setHealth(double health) { this->health = health; }
void CombatObject::setHealth(double health)
{
    if (health < 0)
        death();
    else
    {
        fireEvent("object updated");
    }
    this->health = health;
}
double CombatObject::getHealth() const { return health; }
double CombatObject::getMaxHealth() const { return type->getMaxHealth(); }
double CombatObject::getDamage() const { return type->getDamage(); }
double CombatObject::getArmor() const { return type->getArmor(); }

void CombatObject::underAttack(double damage, double armor)
{
    damage = damage * (1 + (armor - this->type->getArmor()) / 10);
    this->setHealth(this->getHealth() - damage);
}

double CombatObject::getDamageAttack() { return this->getDamage(); }

v8::Local<v8::Object> CombatObject::getInfo()
{
    v8::Local<v8::Object> info = Object::getInfo();

    SetObjField(info, "combatOrNeutral", "combat");

    v8::Local<v8::Object> stats = Nan::New<v8::Object>();

    SetObjField(stats, "health", health);
    SetObjField(stats, "maxHealth", getMaxHealth());
    SetObjField(stats, "damage", getDamage());
    SetObjField(stats, "armor", getArmor());

    SetObjField(info, "stats", stats);

    return info;
}