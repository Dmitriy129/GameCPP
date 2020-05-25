#include "LandscapeProxy.hpp"
LandscapeProxy::LandscapeProxy()
{
    landscape = nullptr;
}

LandscapeProxy::LandscapeProxy(std::string landscapeType)
{
    if (landscapeType == "Forest")
        landscape = new Forest;
    if (landscapeType == "Mountain")
        landscape = new Mountain;
    if (landscapeType == "Plain")
        landscape = new Plain;
    if (landscapeType == "Swamp")
        landscape = new Swamp;
}

LandscapeProxy ::~LandscapeProxy()
{
    delete landscape;
}

std::string LandscapeProxy::getLandscapeType()
{
    return landscape->getLandscapeType();
    // return "LandscapeProxy";
}
bool LandscapeProxy::checkAccessMove(std::string objectType)
{

    std::string landscapeType = landscape->getLandscapeType();
    if (!landscape->checkAccessMove(""))
        return false;
    if (objectType.find("Tank") != std::string::npos)
        if (landscapeType == "Forest")
            return false;
    if (objectType.find("DPS") != std::string::npos)
        if (landscapeType == "Swamp")
            return false;

    if (objectType.find("Archer") != std::string::npos)
        if (landscapeType == "Swamp")
            return false;
    if (objectType.find("Cavalry") != std::string::npos)
        if (landscapeType == "Forest")
            return false;

    return true;
}

bool LandscapeProxy::checkAccessInteraction(std::string objectType)
{
    std::string landscapeType = landscape->getLandscapeType();
    if (!landscape->checkAccessMove(""))
        return false;

    if (objectType.find("Archer") != std::string::npos)
        if (landscapeType == "Forest")
            return false;
    if (objectType.find("Infantry") != std::string::npos || objectType.find("Cavalry") != std::string::npos)
        if (landscapeType == "Swamp")
            return false;

    return true;
}