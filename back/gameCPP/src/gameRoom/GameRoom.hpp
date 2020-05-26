#ifndef GameRoom_hpp
#define GameRoom_hpp

#include "../field/Field.hpp"
#include "../objects/combatObject/base/Base.hpp"
#include "../uuid/UUID.hpp"
#include "../objects/neutralObject/resourceGenerator/ResourceGeneratorFactory.hpp"
#include "../player/Player.hpp"
#include "../eventProvider/EventProvider.hpp"
#include "../memento/GameRoomMemento.hpp"

class GameRoom : public EventProvider
{
private:
    Field *field;
    UUID *uuidGen;
    ResourceGeneratorFactory *resourceGeneratorFactory;
    CombatObjectTypeFactory *combatObjectTypeFactory;

    std::vector<Player *> players;
    std::string roomID;
    std::string roomName;

    std::vector<GameRoomMemento *> mementos;

public:
    GameRoom(std::string roomID, std::string roomName, Field *field, UUID *uuidGen, ResourceGeneratorFactory *resourceGeneratorFactory, CombatObjectTypeFactory *combatObjectTypeFactory);
    GameRoom(std::string roomID, std::string roomName, Field *field);
    ~GameRoom();

    //about room
    std::string getRoomID();
    std::string getRoomName();
    //*
    //about Field
    FieldCell *getFieldCell(unsigned int x, unsigned int y);
    unsigned int getFieldRowsQuantity();
    unsigned int getFieldColumnsQuantity();
    std::vector<std::string> getLandscapes();
    std::vector<std::string> getObjects();

    //about players
    void addPlayer(std::string playerID, std::string PlayerName);
    std::string removePlayer(std::string playerID);
    // */

    /* for player  */
    void createBase(std::string playerID, unsigned int rowNumber, unsigned int columnNumber);
    // void createUnit(std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type);
    void moveObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    void interactionObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    /*  */

    Player *getPlayer(std::string playerID);
    unsigned int getPlayersQuantity();
    std::vector<std::string> getPlayersID();
    std::vector<std::string> getPlayersNames();
    //

    void createMemento();
    void setMemento(std::string ID);

    v8::Local<v8::Object> getGameRoomFieldData();
    v8::Local<v8::Object> getGameRoomData();

    v8::Local<v8::Object> getGameRoomInfo();
    void eventHandler(Event *event) override;
};

#endif /* GameRoom_hpp */
