#include "Player.hpp"

Player::Player(std::string playerID, std::string playerName, Field *field, UUID *uuidGen, ResourceGeneratorFactory *resourceGeneratorFactory, CombatObjectTypeFactory *combatObjectTypeFactory)
{
    this->playerID = playerID;
    this->playerName = playerName;
    this->field = field;

    this->uuidGen = uuidGen;
    this->resourceGeneratorFactory = resourceGeneratorFactory;
    this->combatObjectTypeFactory = combatObjectTypeFactory;
}

Player ::~Player()
{
    delete this->field;
    delete this->base;
    delete this->uuidGen;
    delete this->resourceGeneratorFactory;
    delete this->combatObjectTypeFactory;
}

std::string Player::getPlayerID()
{
    return this->playerID;
}
std::string Player::getPlayerName()
{
    return this->playerName;
}

void Player::createBase(unsigned int rowNumber, unsigned int columnNumber)
{

    this->base = new Base(playerID, /* maxQuantityOfUnits */ 100, 1000, 4, combatObjectTypeFactory);
    this->field->addObject(rowNumber, columnNumber, base);
}

void Player::createUnit(unsigned int rowNumber, unsigned int columnNumber, unsigned int type)
{
    if (base == nullptr)
    {
        std::cout << "error# in file *Player*\n\tCerate the base first.\n";
        return;
    }

    // std::string classUnit;
    // std::string typeUnit;

    // if (type == ARCH_TANK || type == ARCH_DPS)
    //     classUnit = "archer";
    // else if (type == CAV_TANK || type == CAV_DPS)
    //     classUnit = "cavalry";
    // else if (type == INF_TANK || type == INF_DPS)
    //     classUnit = "infantry";
    // else
    // {
    //     std::cout << "error1# in file *Player*\n";
    //     return;
    // }

    // if (type == ARCH_DPS || type == INF_DPS || type == CAV_DPS)
    //     typeUnit = "DPS";
    // else if (type == ARCH_TANK || type == INF_TANK || type == CAV_TANK)
    //     typeUnit = "TANK";
    // else
    // {
    //     std::cout << "error2# in file *Player*\n";
    //     return;
    // }
    // if (type.find("archer") != std::string::npos)
    //     classUnit = "archer";
    // else if (type.find("cavalry") != std::string::npos)
    //     classUnit = "cavalry";
    // else if (type.find("infantry") != std::string::npos)
    //     classUnit = "infantry";
    // else
    // {
    //     std::cout << "error# in file *Player*\n";
    //     return;
    // }

    // if (type.find("DPS") != std::string::npos)
    //     typeUnit = "DPS";
    // else if (type.find("TANK") != std::string::npos)
    //     typeUnit = "TANK";
    // else
    // {
    //     std::cout << "error# in file *Player*\n";
    //     return;
    // }
    // Unit *unit = base->createUnit(classUnit, typeUnit, uuidGen->generateUUID(), combatObjectTypeFactory);
    Unit *unit = base->createUnit(type, uuidGen->generateUUID(), combatObjectTypeFactory);

    unit->attachEvent("object death", field);

    field->addObject(rowNumber, columnNumber, unit);
}
void Player::moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
{
    field->moveObject(fromRowNumber, fromColumnNumber, toRowNumber, toColumnNumber);
}
void Player::interactionObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
{
    field->getMediator()->interactionObjObj(field, fromRowNumber, fromColumnNumber, toRowNumber, toColumnNumber);
}

void Player::eventHandler(Event *event)
{
}
