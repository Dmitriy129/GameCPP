#ifndef InfantryTank_hpp
#define InfantryTank_hpp

#include <stdio.h>
#include "../../../UnitTank.hpp"
#include "InfantryClass.hpp"

class InfantryTank : public UnitTank, public InfantryClass
{
private:
    // std::string objectType = "InfantryTank";

public:
    InfantryTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    // std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* InfantryTank_hpp */
