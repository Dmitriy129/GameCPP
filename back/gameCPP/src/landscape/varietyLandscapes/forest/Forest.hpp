
#ifndef Forest_hpp
#define Forest_hpp

#include <stdio.h>
#include "../../Landscape.hpp"

class Forest : public Landscape
{
public:
    std::string getLandscapeType() override;
    bool checkAccessMove(std::string objectType) override;
    bool checkAccessInteraction(std::string objectType) override;
};

#endif /* Forest_hpp */