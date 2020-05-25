#ifndef UnitTank_hpp
#define UnitTank_hpp

#include <stdio.h>
// #include "../CombatObject.hpp"
#include "Unit.hpp"

class UnitTank : public virtual Unit /*, CombatObject */
{
protected:
    double critChance;
    double critAbsorption;

public:
    void underAttack(double damage, double armor);
    v8::Local<v8::Object> getInfo();
};

#endif /* UnitTank_hpp */
