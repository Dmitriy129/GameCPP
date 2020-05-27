
#ifndef Farm_hpp
#define Farm_hpp

#include <stdio.h>
#include "../../ResourceGenerator.hpp"

class Farm : public ResourceGenerator
{
private:
    std::string resType = "Food";

public:
    Farm(std::string ID);
    // void getResPerStepForUnit() override;
    // //  std::string getObjectType();
};
#endif /* Farm_hpp */