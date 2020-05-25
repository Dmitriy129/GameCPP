#ifndef InfantryClass_hpp
#define InfantryClass_hpp

#include <stdio.h>
#include "../../../Unit.hpp"
// #include "../../../../base/Base.hpp"

class InfantryClass : public virtual Unit
{
    std::string objectType = "Infantry";
};

#endif /* InfantryClass_hpp */
