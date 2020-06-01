
#ifndef Sawmill_hpp
#define Sawmill_hpp

#include <stdio.h>
#include "../../ResourceGenerator.hpp"

class Sawmill : public ResourceGenerator
{
public:
    Sawmill(std::string ID);
    // void getResPerStepForUnit() override;
    // std::string getObjectType();
    // v8::Local<v8::Object> getFullInfo();
};

#endif /* Sawmill_hpp */