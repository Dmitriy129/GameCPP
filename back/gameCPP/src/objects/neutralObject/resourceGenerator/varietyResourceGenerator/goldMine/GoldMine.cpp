#include "GoldMine.hpp"

GoldMine::GoldMine(std::string ID)
{
    this->ID = ID;
    objectType = GEN_GOLD;
    resType = GOLD;
};

// void GoldMine::getResPerStepForUnit()
// {
//     std::cout << "Team: " << this->playerID << " have earned " << resPerStep * useStrategy() << " gold\n\n";
// }

// std::string GoldMine::getObjectType() { return "GoldMine"; }
