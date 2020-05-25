#ifndef Player_hpp
#define Player_hpp

#include "../field/Field.hpp"
#include "../objects/combatObject/base/Base.hpp"
#include "../uuid/UUID.hpp"
#include "../objects/neutralObject/resourceGenerator/ResourceGeneratorFactory.hpp"
#include "../TypeСonstants.hpp"
#include "../eventProvider/EventProvider.hpp"

class Player : public EventProvider
{
private:
    Field *field;
    Base *base;
    UUID *uuidGen;
    ResourceGeneratorFactory *resourceGeneratorFactory;
    CombatObjectTypeFactory *combatObjectTypeFactory;

    std::string playerID;
    std::string playerName;

public:
    Player(std::string playerID, std::string playerName, Field *field, UUID *uuidGen, ResourceGeneratorFactory *resourceGeneratorFactory, CombatObjectTypeFactory *combatObjectTypeFactory);
    ~Player();

    std::string getPlayerID();
    std::string getPlayerName();

    void createBase(unsigned int rowNumber, unsigned int columnNumber);
    void createUnit(unsigned int rowNumber, unsigned int columnNumber, unsigned int type);
    void moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    void interactionObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    void eventHandler(Event *event) override;

};

#endif /* Player_hpp */
