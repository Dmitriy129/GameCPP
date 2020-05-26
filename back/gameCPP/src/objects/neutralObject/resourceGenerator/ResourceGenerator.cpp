#include "ResourceGenerator.hpp"

// void ResourceGenerator::operator+(CombatObject *unit)
// {
//     this->playerID = unit->getPlayerID();
//     if (unit->getObjectType().find("Archer") != std::string::npos)
//         setStrategy(new StrategyResArcher);
//     if (unit->getObjectType().find("Cavalry") != std::string::npos)
//         setStrategy(new StrategyResCavalry);
//     if (unit->getObjectType().find("Infantry") != std::string::npos)
//         setStrategy(new StrategyResInfantry);
//     getResPerStepForUnit();
// }
ResourceGenerator::ResourceGenerator()
{
    resPerStep = 10;
    playerID = "empty";
}

bool ResourceGenerator::isMoveable() { return false; }

void ResourceGenerator::operator+(Object *object)
{
    this->playerID = object->getPlayerID();
    // std::cout << "Now " << this->getObjectType() << " is owned by playerID: " << this->getPlayerID() << "\n";
    if (object->getObjectType().find("Archer") != std::string::npos)
        setStrategy(new StrategyResArcher);
    if (object->getObjectType().find("Cavalry") != std::string::npos)
        setStrategy(new StrategyResCavalry);
    if (object->getObjectType().find("Infantry") != std::string::npos)
        setStrategy(new StrategyResInfantry);

    getResPerStepForUnit();
}

std::string ResourceGenerator::getResType() { return resType; }

double ResourceGenerator::getResPerStep() { return resPerStep; }

double ResourceGenerator::getCoefficient() { return coefficient; }

double ResourceGenerator::getResPerStepForUnit()
{
    double ret = resPerStep * coefficient;
    coefficient *= 1.1;
    return ret;
}

void ResourceGenerator::useStrategy() { coefficient = strategy->use(); }

void ResourceGenerator::setStrategy(Strategy *strategy) { this->strategy = strategy; }

v8::Local<v8::Object> ResourceGenerator::getFullInfo()
{
    v8::Local<v8::Object> info = NeutralObject::getFullInfo();

    SetObjField(info, "combatOrNeutral", "neutral");

    v8::Local<v8::Object> stats = Nan::New<v8::Object>();

    SetObjField(stats, "resType", resType);
    SetObjField(stats, "resPerStep", resPerStep);
    SetObjField(stats, "coefficient", coefficient);

    SetObjField(info, "stats", stats);

    return info;
}