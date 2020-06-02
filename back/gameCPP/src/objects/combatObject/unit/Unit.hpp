
#ifndef Unit_hpp
#define Unit_hpp

#include <stdio.h>
#include "../CombatObject.hpp"
// #include "../base/Base.hpp"
// #include "../../../eventProvider/EventProvider.hpp"

class Unit : public CombatObject
{
protected:
    void death() override;

public:
    ~Unit();
    // void setHealth(double health) override;
    // double getHealth() const override;
    // double getMaxHealth() const override;
    // double getDamage() const override;
    // double getArmor() const override;
    // std::string getPlayerID() override;
    // void underAttack(double damage, double armor) override{};
    bool isMoveable() override;
    void operator+(Object *object) override;

    //  std::string getObjectType() override;
    v8::Local<v8::Object> getFullInfo() override;

    void eventHandler(Event *event) override;
};

#endif /* Unit_hpp */
