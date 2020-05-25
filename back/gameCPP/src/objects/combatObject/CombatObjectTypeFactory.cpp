#include "CombatObjectTypeFactory.hpp"

CombatObjectTypeFactory::CombatObjectTypeFactory()
{

    quantityOfTypes = 0;
    // combatObjectTypes = nullptr;
}

CombatObjectType *CombatObjectTypeFactory::getCombatObjectType(double health, double damage, double armor)
{
    for (int i = 0; i < quantityOfTypes; i++)
        if (combatObjectTypes[i]->dataСomparison(health, damage, armor))
            return combatObjectTypes[i];
    //  addType(health, damage, armor);
    quantityOfTypes++;
    combatObjectTypes.push_back(new CombatObjectType(health, damage, armor));
    return combatObjectTypes[quantityOfTypes - 1];
}
