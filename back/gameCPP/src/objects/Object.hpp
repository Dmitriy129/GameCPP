
#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <string>
// #include "combatObject"
#include "../eventProvider/EventProvider.hpp"

class Object : public EventProvider
{
protected:
    std::string objectType = "Object";
    std::string ID;
    std::string playerID;

public:
    std::string getObjectType();
    std::string getPlayerID();
    v8::Local<v8::Object> getInfo();
    virtual bool isMoveable() = 0;
    virtual void operator+(Object *object) = 0;
};

#endif /* Object_hpp */