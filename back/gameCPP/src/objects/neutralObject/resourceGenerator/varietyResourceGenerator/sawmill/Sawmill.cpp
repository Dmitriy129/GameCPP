#include "Sawmill.hpp"

Sawmill::Sawmill(std::string ID)
{
    this->ID = ID;
    objectType = GEN_SAWMILL;
    resType = WOOD;
};

// void Sawmill::getResPerStepForUnit()
// {
//     // // // std::cout << "You have earned " << resPerStep * useStrategy() << " wood";
// }

// std::string Sawmill::getObjectType() { return "Sawmill"; }

// v8::Local<v8::Object> Sawmill::getFullInfo()
// {
//     v8::Local<v8::Object> info = ResourceGenerator::getFullInfo();

//     SetObjProperty(info, "objectType", "Sawmill");

//     return info;
// }