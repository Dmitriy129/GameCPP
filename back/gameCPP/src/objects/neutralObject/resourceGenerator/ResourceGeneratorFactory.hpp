
#ifndef ResourceGeneratorFactory_hpp
#define ResourceGeneratorFactory_hpp

#include <stdio.h>
#include "ResourceGenerator.hpp"
#include "varietyResourceGenerator/farm/Farm.hpp"
#include "varietyResourceGenerator/goldMine/GoldMine.hpp"
#include "varietyResourceGenerator/sawmill/Sawmill.hpp"

class ResourceGeneratorFactory
{
public:
    // ResourceGeneratorFactory();
    ResourceGenerator *createResourceGenerator(std::string ResourceGeneratorType);
};

#endif /* ResourceGeneratorFactory_hpp */