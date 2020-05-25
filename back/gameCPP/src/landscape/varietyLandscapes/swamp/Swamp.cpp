#include "Swamp.hpp"

std::string Swamp::getLandscapeType()
{
    return "Swamp";
}
bool Swamp::checkAccessMove(std::string objectType)
{
    return true;
}

bool Swamp::checkAccessInteraction(std::string objectType)
{
    return true;
}