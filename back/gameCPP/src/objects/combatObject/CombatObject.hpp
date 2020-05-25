
#ifndef CombatObject_hpp
#define CombatObject_hpp

#include <stdio.h>
#include "../Object.hpp"
#include "CombatObjectTypeFactory.hpp"

class CombatObject : public Object
{
protected:
    double health;
    CombatObjectType *type;

    //func if die
    virtual void death() = 0;

public:
    ~CombatObject();
    void setHealth(double health);
    double getHealth() const;
    double getMaxHealth() const;
    double getDamage() const;
    double getArmor() const;

    void underAttack(double damage, double armor);
    double getDamageAttack();
    v8::Local<v8::Object> getInfo();
};

#endif /* CombatObject_hpp */