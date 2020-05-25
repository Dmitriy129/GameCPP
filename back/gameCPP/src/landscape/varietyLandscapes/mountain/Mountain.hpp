#ifndef Mountain_hpp
#define Mountain_hpp

#include <stdio.h>
#include "../../Landscape.hpp"

class Mountain : public Landscape
{
public:
    std::string getLandscapeType() override;
    bool checkAccessMove(std::string objectType) override;
    bool checkAccessInteraction(std::string objectType) override;
};

#endif /* Mountain_hpp */