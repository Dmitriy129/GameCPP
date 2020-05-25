#include "FieldMediator.hpp"

void FieldMediator::battle(CombatObject *object1, CombatObject *object2)
{
    double damage1 = object1->getDamage(),
           damage2 = object2->getDamage(),
           armor1 = object1->getArmor(),
           armor2 = object2->getArmor();

    object1->underAttack(damage2, armor2);
    object2->underAttack(damage1, armor1);
}
void FieldMediator::interactionObjObj(Object *object1, Object *object2)
{
    if (object1 == nullptr || object2 == nullptr)
        return;
    std::string resGenerators = "Farm GoldMine Sawmill";
    if (resGenerators.find(object2->getObjectType()) != std::string::npos)
    {
        *object2 + object1;
        return;
    }

    if (object1->getPlayerID() == object2->getPlayerID())
    {
        std::cout << "You can not attack allies."
                  << std::endl
                  << "*in file \"Field\"\n";
        return;
    }
    else
        battle((CombatObject *)object1, (CombatObject *)object2);
}
void FieldMediator::interactionObjObj(Field *field, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
{
    if (!field->getFieldCell(toRowNumber, toColumnNumber).getLandscape()->checkAccessInteraction(field->getFieldCell(fromRowNumber, fromColumnNumber).getObject()->getObjectType()))
    {
        std::cout << "The Object cannot interact with object in this cell .([" << fromRowNumber << "][" << fromColumnNumber << "]->[" << toRowNumber << "][" << toColumnNumber << "]) "
                  << std::endl
                  << "*in file \"Field\"\n";
        return;
    }
    std::cout << "Object Interaction .([" << fromRowNumber << "][" << fromColumnNumber << "] & [" << toRowNumber << "][" << toColumnNumber << "]) "
              << std::endl
              << "*in file \"Field\"\n";
    interactionObjObj(field->getFieldCell(fromRowNumber, fromColumnNumber).getObject(), field->getFieldCell(toRowNumber, toColumnNumber).getObject());
}
