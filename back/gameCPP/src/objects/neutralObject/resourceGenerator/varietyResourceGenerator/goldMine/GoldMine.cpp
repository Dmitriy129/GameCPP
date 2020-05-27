#include "GoldMine.hpp"

GoldMine::GoldMine(std::string ID)
{
    this->ID = ID;
    objectType = "GoldMine";
};

// void GoldMine::getResPerStepForUnit()
// {
//     std::cout << "Team: " << this->playerID << " have earned " << resPerStep * useStrategy() << " gold\n\n";
// }

// std::string GoldMine::getObjectType() { return "GoldMine"; }
