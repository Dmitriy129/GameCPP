
#ifndef GoldMine_hpp
#define GoldMine_hpp

#include <stdio.h>
#include "../../ResourceGenerator.hpp"

class GoldMine : public ResourceGenerator
{
private:
    std::string resType = "Gold";

public:
    GoldMine(std::string ID);
    // void getResPerStepForUnit() override;
    // //  std::string getObjectType();
};

#endif /* GoldMine_hpp */