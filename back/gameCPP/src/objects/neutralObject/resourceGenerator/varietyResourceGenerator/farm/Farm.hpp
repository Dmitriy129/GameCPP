
#ifndef Farm_hpp
#define Farm_hpp

#include <stdio.h>
#include "../../ResourceGenerator.hpp"

class Farm : public ResourceGenerator
{
private:
    std::string objectType = "Farm";
    std::string resType = "Food";

public:
    // void getResPerStepForUnit() override;
    // //  std::string getObjectType();
};
#endif /* Farm_hpp */