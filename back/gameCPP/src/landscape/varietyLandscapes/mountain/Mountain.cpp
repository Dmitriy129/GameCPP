#include "Mountain.hpp"

std::string Mountain::getLandscapeType()
{
    return "Mountain";
}
bool Mountain::checkAccessMove(std::string objectType)
{
    return false;
}

bool Mountain::checkAccessInteraction(std::string objectType)
{
    return false;
}