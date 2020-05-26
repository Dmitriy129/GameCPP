#ifndef InfantryDPS_hpp
#define InfantryDPS_hpp

#include <stdio.h>
#include "../../../UnitDPS.hpp"
#include "InfantryClass.hpp"

class InfantryDPS : public UnitDPS, public InfantryClass
{
private:
    std::string objectType = "InfantryDPS";

public:
    InfantryDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    //  std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* InfantryDPS_hpp */
