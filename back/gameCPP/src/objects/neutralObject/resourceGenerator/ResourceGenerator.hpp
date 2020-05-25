
#ifndef ResourceGenerator_hpp
#define ResourceGenerator_hpp

#include <stdio.h>
#include "../NeutralObject.hpp"
#include "../../combatObject/unit/Unit.hpp"
#include "../../../strategy/Strategy.hpp"
#include "../../../strategy/varietyStrategy/strategyResArcher/StrategyResArcher.hpp"
#include "../../../strategy/varietyStrategy/strategyResCavalry/StrategyResCavalry.hpp"
#include "../../../strategy/varietyStrategy/strategyResInfantry/StrategyResInfantry.hpp"
#include "../../../strategy/Context.hpp"

class ResourceGenerator : public NeutralObject, public Context
{
protected:
    std::string resType;
    double resPerStep;
    double coefficient;

    void useStrategy() override;
    void setStrategy(Strategy *strategy) override;

public:
    ResourceGenerator();
    void operator+(Object *object) override;
    std::string getResType();
    double getResPerStep();
    double getCoefficient();
    double getResPerStepForUnit();
    bool isMoveable() override;
    v8::Local<v8::Object> getInfo();
};

#endif /* ResourceGenerator_hpp */