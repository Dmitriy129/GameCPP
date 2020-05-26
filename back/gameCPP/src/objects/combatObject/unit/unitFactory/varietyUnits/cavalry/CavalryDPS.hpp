#ifndef CavalryDPS_hpp
#define CavalryDPS_hpp

#include <stdio.h>
#include "../../../UnitDPS.hpp"
#include "CavalryClass.hpp"

class CavalryDPS : public UnitDPS, public CavalryClass
{
private:
    std::string objectType = "CavalryDPS";

public:
    CavalryDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    //  std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* CavalryDPS_hpp */
