#ifndef CavalryTank_hpp
#define CavalryTank_hpp

#include <stdio.h>
#include "../../../UnitTank.hpp"
#include "CavalryClass.hpp"

class CavalryTank : public UnitTank, public CavalryClass
{
private:
    std::string objectType = "CavalryTank";

public:
    CavalryTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    //  std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* CavalryTank_hpp */
