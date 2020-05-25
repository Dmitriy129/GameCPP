
#ifndef LandscapeProxy_hpp
#define LandscapeProxy_hpp

#include <stdio.h>
#include <iostream>
#include "../Landscape.hpp"
#include "../varietyLandscapes/forest/Forest.hpp"
#include "../varietyLandscapes/mountain/Mountain.hpp"
#include "../varietyLandscapes/plain/Plain.hpp"
#include "../varietyLandscapes/swamp/Swamp.hpp"

class LandscapeProxy : public Landscape
{
private:
    Landscape *landscape;

public:
    LandscapeProxy();
    LandscapeProxy(std::string landscapeType);
    ~LandscapeProxy();
    std::string getLandscapeType() override;
    bool checkAccessMove(std::string objectType) override;
    bool checkAccessInteraction(std::string objectType) override;
};

#endif /* LandscapeProxy_hpp */