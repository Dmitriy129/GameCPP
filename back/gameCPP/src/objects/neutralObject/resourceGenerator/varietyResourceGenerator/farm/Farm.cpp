#include "Farm.hpp"

Farm::Farm(std::string ID)
{
    this->ID = ID;
    objectType = GEN_FARM;
    resType = FOOD;
};
// void Farm::getResPerStepForUnit()
// {
//     // // std::cout << "You have earned " << resPerStep * useStrategy() << " food";
// }

// std::string Farm::getObjectType() { return "Farm"; }