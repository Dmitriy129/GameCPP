
#include "Base.hpp"

Base::Base(std::string playerID, std::string ID, unsigned int maxQuantityOfUnits, double health, double armor, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    // // std::cout << "kek/n";
    // armyOfUnits.push_back(nullptr);
    this->health = health;
    this->maxQuantityOfUnits = maxQuantityOfUnits;
    this->quantityOfUnits = 0;
    this->playerID = playerID;
    this->ID = ID;
    // this->type = new CombatObjectType(health, 0, armor);
    type = combatObjectTypeFactory->getCombatObjectType(80, 40, 1);
    objectType = BASE;
}

Base::~Base()
{
    // for (int i = 0; i < quantityOfUnits; i++)
    // delete armyOfUnits[i];
    armyOfUnits.clear();
}

bool Base::isMoveable() { return false; }

// Unit *Base::createUnit(std::string classUnit, std::string typeUnit, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
Unit *Base::createUnit(unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    if (quantityOfUnits == maxQuantityOfUnits)
    {
        std::cout << "error# The maximum number of units in the Base(\"" << this->getPlayerID() << "\") has already been created"
                  << std::endl
                  << "*in file Base*\n";
        return nullptr;
    }
    Unit *newUnit = nullptr;

    quantityOfUnits++;
    if (type == ARCH_DPS || type == INF_DPS || type == CAV_DPS)
        newUnit = factoryUnit(new UnitDPSFactory, type, unitID, combatObjectTypeFactory);
    else if (type == ARCH_TANK || type == INF_TANK || type == CAV_TANK)
        newUnit = factoryUnit(new UnitTankFactory, type, unitID, combatObjectTypeFactory);
    else
    {

        std::cout << "error# Unknown unit type"
                  << std::endl
                  << "*in file Base*\n";
        return nullptr;
    }

    armyOfUnits.push_back(newUnit);
    newUnit->attachEvent("object death", this);
    return newUnit;
}

void Base::removeUnit(Unit *unit)
{
    std::__1::__wrap_iter<Unit **> index = std::find(armyOfUnits.begin(), armyOfUnits.end(), unit);
    if (index != armyOfUnits.end())
        armyOfUnits.erase(index);
}

void Base::unitDie(Unit *unit)
{
    removeUnit(unit);
    delete unit;
}

// std::string Base::getPlayerID()
// {
//     return playerID;
// }

Unit *Base::factoryUnit(UnitTankFactory *factory, unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{

    if (type == ARCH_TANK || type == ARCH_DPS)
        return factory->createArcher(playerID, unitID, combatObjectTypeFactory);
    if (type == INF_TANK || type == INF_DPS)
        return factory->createInfantry(playerID, unitID, combatObjectTypeFactory);
    if (type == CAV_TANK || type == CAV_DPS)
        return factory->createCavalry(playerID, unitID, combatObjectTypeFactory);
    std::cout << "error# unknown unit class\n *in file \"base\"\n";
    return nullptr;
}

Unit *Base::factoryUnit(UnitDPSFactory *factory, unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory)
{

    if (type == ARCH_TANK || type == ARCH_DPS)
        return factory->createArcher(playerID, unitID, combatObjectTypeFactory);
    if (type == INF_TANK || type == INF_DPS)
        return factory->createInfantry(playerID, unitID, combatObjectTypeFactory);
    if (type == CAV_TANK || type == CAV_DPS)
        return factory->createCavalry(playerID, unitID, combatObjectTypeFactory);
    std::cout << "error# unknown unit class\n *in file \"base\"\n";
    return nullptr;
}

/*
void Base::setHealth(double health)
{
    this->health = health;
}
 double Base::getHealth() const
{
    return this->health;
}
double Base::getMaxHealth() const
{
    return this->type->getMaxHealth();
}
double Base::getDamage() const
{
    return this->type->getDamage();
}
double Base::getArmor() const
{
    return this->type->getArmor();
} */
// double Base::getDamageAttack()
// {
//     return getDamage;
// }

void Base::operator+(Object *object) {}
void Base::death() { fireEvent("object death"); };

// std::string Base::getObjectType() { return BASE; }

void Base::eventHandler(Event *event)
{
    if (event->getSEventId() == "object death")
    {
        std::cout << "*Base* Event: \"" << event->getSEventId() << "\" started \n";
        removeUnit((Unit *)event->getSource());
    }
}

v8::Local<v8::Object> Base::getFullInfo()
{
    v8::Local<v8::Object> info = CombatObject::getFullInfo();
    SetObjProperty(info, "type", objectType);
    return info;
}