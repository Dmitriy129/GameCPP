
#ifndef Sawmill_hpp
#define Sawmill_hpp

#include <stdio.h>
#include "../../ResourceGenerator.hpp"

class Sawmill : public ResourceGenerator
{
private:
    std::string objectType = "Sawmill";
    std::string resType = "Wood";

public:
    // void getResPerStepForUnit() override;
    // std::string getObjectType();
    // v8::Local<v8::Object> getInfo();
};

#endif /* Sawmill_hpp */