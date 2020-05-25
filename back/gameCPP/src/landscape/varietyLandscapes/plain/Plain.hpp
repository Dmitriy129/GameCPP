
#ifndef Plain_hpp
#define Plain_hpp

#include <stdio.h>
#include "../../Landscape.hpp"

class Plain : public Landscape
{
public:
    std::string getLandscapeType() override;
    bool checkAccessMove(std::string objectType) override;
    bool checkAccessInteraction(std::string objectType) override;
};

#endif /* Plain_hpp */