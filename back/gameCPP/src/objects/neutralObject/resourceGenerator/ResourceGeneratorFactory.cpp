#include "ResourceGeneratorFactory.hpp"

ResourceGenerator *ResourceGeneratorFactory::createResourceGenerator(std::string ResourceGeneratorType)
{
    if (ResourceGeneratorType == "GoldMine")
        return new GoldMine;
    if (ResourceGeneratorType == "Farm")
        return new Farm;
    if (ResourceGeneratorType == "Sawmill")
        return new Sawmill;
}

