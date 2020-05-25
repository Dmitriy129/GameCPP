#include "Plain.hpp"

std::string Plain::getLandscapeType()
{
    return "Plain";
}
bool Plain::checkAccessMove(std::string objectType)
{
    return true;
}

bool Plain::checkAccessInteraction(std::string objectType)
{
    return true;
}