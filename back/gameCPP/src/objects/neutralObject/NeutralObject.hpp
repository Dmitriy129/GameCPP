
#ifndef NeutralObject_hpp
#define NeutralObject_hpp

#include <stdio.h>
#include "../Object.hpp"
#include "../combatObject/CombatObject.hpp"

// class CombatObject;
class NeutralObject : public Object
{
public:
    // virtual void operator+(CombatObject *unit);
    void eventHandler(Event *event) override;
    virtual v8::Local<v8::Object> getFullInfo();
};

#endif /* NeutralObject_hpp */