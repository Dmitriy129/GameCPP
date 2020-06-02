#ifndef GameRoom_hpp
#define GameRoom_hpp

#include "../field/Field.hpp"
#include "../rule/rule1/Rule1.hpp"
#include "../rule/rule2/Rule2.hpp"
#include "../objects/combatObject/base/Base.hpp"
#include "../uuid/UUID.hpp"
#include "../objects/neutralObject/NeutralObjectFactory.hpp"
#include "../player/Player.hpp"
#include "../mediator/fieldMediator/FieldMediator.hpp"
#include "../eventProvider/EventProvider.hpp"
#include "../editor/Editor.hpp"
#include "gameRoomState/GameRoomState.hpp"

template <class T>
class GameRoom : public EventProvider, public GameRoomState
{
private:
    Field *field;
    UUID *uuidGen;
    NeutralObjectFactory *neutralObjectFactory;
    CombatObjectTypeFactory *combatObjectTypeFactory;
    Mediator *mediator;

    Editor *editor;
    std::vector<Player *> players;
    std::string roomID;
    std::string roomName;
    T *rule;

public:
    GameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, UUID *uuidGen, NeutralObjectFactory *NeutralObjectFactory, CombatObjectTypeFactory *combatObjectTypeFactory, unsigned int rule);
    ~GameRoom();

    friend class GameRoomMemento;
    friend class Rule;

    //about room
    std::string getRoomID();
    std::string getRoomName();
    //*
    //about Field
    FieldCell *getFieldCell(unsigned int x, unsigned int y);
    unsigned int getFieldRowsQuantity();
    unsigned int getFieldColumnsQuantity();
    // std::vector<std::string> getLandscapes();
    // std::vector<std::string> getObjects();

    //about players
    void addPlayer(std::string playerID, std::string PlayerName);
    void removePlayer(std::string playerID);
    // */

    /* for player  */
    // void createBase(std::string playerID, unsigned int rowNumber, unsigned int columnNumber);
    // void createUnit(std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type);
    // void moveObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    // void interactionObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    /*  */

    void nextPlayer() override;

    UUID *getUuidGen();
    NeutralObjectFactory *getNeutralObjectFactory();
    CombatObjectTypeFactory *getCombatObjectTypeFactory();
    Mediator *getMediator();

    Editor *getEditor();
    Player *getPlayer(std::string playerID);
    unsigned int getPlayersQuantity();
    std::vector<std::string> getPlayersID();
    std::vector<std::string> getPlayersNames();
    //
    v8::Local<v8::Object> getGameRoomFieldData();
    v8::Local<v8::Object> getGameRoomData();

    v8::Local<v8::Object> getFullInfo();
    void eventHandler(Event *event) override;
};

#endif /* GameRoom_hpp */
