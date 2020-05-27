#ifndef ArcherDPS_hpp
#define ArcherDPS_hpp

#include <stdio.h>
#include "../../../UnitDPS.hpp"
#include "ArcherClass.hpp"

class ArcherDPS : public UnitDPS, public ArcherClass
{
private:
    // std::string objectType = "ArcherDPS";

public:
    ArcherDPS(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    //  std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* ArcherDPS_hpp */
