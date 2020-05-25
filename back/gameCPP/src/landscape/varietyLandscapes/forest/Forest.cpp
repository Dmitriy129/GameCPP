#include "Forest.hpp"

std::string Forest::getLandscapeType()
{
    return "Forest";
}
bool Forest::checkAccessMove(std::string objectType)
{
    return true;
}
bool Forest::checkAccessInteraction(std::string objectType)
{
    return true;
}