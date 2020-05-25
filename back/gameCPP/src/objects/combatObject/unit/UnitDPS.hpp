#ifndef UnitDPS_hpp
#define UnitDPS_hpp

#include <stdio.h>
#include "Unit.hpp"
// #include "../CombatObject.hpp"

class UnitDPS : public virtual Unit /*, CombatObject */
{
protected:
    double critChance;
    double critDamage;

public:
    double getDamageAttack();
    v8::Local<v8::Object> getInfo();
};

#endif /* UnitDPS_hpp */
