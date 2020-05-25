#ifndef Swamp_hpp
#define Swamp_hpp

#include <stdio.h>
#include "../../Landscape.hpp"

class Swamp : public Landscape
{
public:
    std::string getLandscapeType() override;
    bool checkAccessMove(std::string objectType) override;
    bool checkAccessInteraction(std::string objectType) override;
};

#endif /* Swamp_hpp */