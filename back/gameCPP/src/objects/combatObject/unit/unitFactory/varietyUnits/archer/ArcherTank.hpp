#ifndef ArcherTank_hpp
#define ArcherTank_hpp

#include <stdio.h>
#include "../../../UnitTank.hpp"
#include "ArcherClass.hpp"

class ArcherTank : public UnitTank, public ArcherClass
{
private:
        // std::string objectType = "ArcherTank";

public:
    ArcherTank(std::string playerID, std::string unitID, CombatObjectTypeFactory *combatObjectTypeFactory);
    //  std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* ArcherTank_hpp */
