
#ifndef Landscape_hpp
#define Landscape_hpp

#include <stdio.h>
#include <string>

class Landscape
{
public:
    // Landscape() = default;
    virtual std::string getLandscapeType() = 0;
    virtual bool checkAccessMove(std::string objectType) = 0;
    virtual bool checkAccessInteraction(std::string objectType) = 0;
};

#endif /* Landscape_hpp */