

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "../CombatObject.hpp"
// #include "../unit/Unit.hpp"
#include "../unit/unitFactory/UnitTankFactory.hpp"
#include "../unit/unitFactory/UnitDPSFactory.hpp"
#include "../CombatObjectTypeFactory.hpp"
#include "../../../TypeСonstants.hpp"

class Unit;
// typedef void (Base::*BaseCB)(Event *);
class Base : public CombatObject
{
private:
    std::vector<Unit *> armyOfUnits;
    unsigned int maxQuantityOfUnits;
    unsigned int quantityOfUnits;

    Unit *factoryUnit(UnitTankFactory *factory, unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    Unit *factoryUnit(UnitDPSFactory *factory, unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);

    void removeUnit(Unit *unit);
    void death() override; //написать
    void unitDie(Unit *unit);

public:
    Base(std::string playerID, unsigned int maxQuantityOfUnits, double health, double armor, CombatObjectTypeFactory *combatObjectTypeFactory);
    ~Base();
    bool isMoveable() override;
    Unit *createUnit(unsigned int type, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);

    // void setHealth(double health) override;
    // double getHealth() const override;
    // double getMaxHealth() const override;
    // double getDamage() const override;
    // double getArmor() const override;
    // std::string getPlayerID() override;
    void operator+(Object *object) override;
    // double getDamageAttack() override;
    //  std::string getObjectType();
    v8::Local<v8::Object> getInfo();

    /*  */
    void eventHandler(Event *event) override;
    /*  */
};

#endif /* Base_hpp */
