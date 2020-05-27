#include "Farm.hpp"

Farm::Farm(std::string ID)
{
    this->ID = ID;
    objectType = "Farm";
};
// void Farm::getResPerStepForUnit()
// {
//     std::cout << "You have earned " << resPerStep * useStrategy() << " food";
// }

// std::string Farm::getObjectType() { return "Farm"; }