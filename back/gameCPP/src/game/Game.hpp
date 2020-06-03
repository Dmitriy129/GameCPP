#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <map>

#include "../gameRoom/GameRoom.hpp"
#include "../field/Field.hpp"
#include "../uuid/UUID.hpp"
#include "../objects/neutralObject/NeutralObjectFactory.hpp"
#include "../player/Player.hpp"
#include "../eventProvider/EventProvider.hpp"
#include "../memento/GameRoomMemento.hpp"
#include "../rule/rule1/Rule1.hpp"
#include "../rule/rule2/Rule2.hpp"

class Game : public EventProvider
{
private:
    std::vector<GameRoom<Rule> *> gameRooms;
    std::map<std::string, std::vector<GameRoomMemento *>> historyGameRooms;

    UUID *uuidGen;
    NeutralObjectFactory *neutralObjectFactory;
    CombatObjectTypeFactory *combatObjectTypeFactory;
    // Mediator *mediator;

    Game();
    Game(const Game &);
    Game &operator=(Game &);
    ~Game();
    static Game *p_game;

public:
    static Game *getInstance();

    void addGameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, unsigned int rule);
    std::string removeGameRoom(std::string roomID);

    GameRoom<Rule> *getGameRoom(std::string roomID);

    //game->rooms
    // void addPlayerToGameRoom(std::string roomID, std::string playerID, std::string playerName); // add done
    // void removePlayerFromGameRoom(std::string roomID, std::string playerID); // add done
    // void removePlayerEveryWhere(std::string playerID);                                          // add
    // std::vector<std::vector<std::string>> getGameRoomsPlayersNamesList();
    // std::vector<std::vector<std::string>> getGameRoomsPlayersIDList();

    // std::vector<GameRoom *> getGameRoomsList();      // add
    // std::vector<std::string> getGameRoomsIDList();   // add
    // std::vector<std::string> getGameRoomsNameList(); // add
    // std::vector<unsigned int> getGameRoomPlayersQuantityList();
    // std::vector<unsigned int> getFieldRowsQuantityList();
    // std::vector<unsigned int> getFieldColumnsQuantityList();
    // unsigned int getFieldRowsQuantity(std::string roomID);
    // unsigned int getFieldColumnsQuantity(std::string roomID);

    //game->rooms(roomID)->{players or field}
    std::vector<std::string> getGameRoomPlayersIDList(std::string roomID); // add done
    // std::vector<std::string> getGameRoomFieldLandscapes(std::string roomID); // add done
    // std::vector<std::string> getGameRoomFieldObjects(std::string roomID);    // add

    std::string executeСommand(std::string playerID, std::string command);

    /* for room  */
    // void createBase(std::string roomID, std::string playerID, unsigned int rowNumber, unsigned int columnNumber);
    // void createUnit(std::string roomID, std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type);
    // void moveObject(std::string roomID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    // void interactionObject(std::string roomID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);
    /*  */

    v8::Local<v8::Object> getGameRoomsInfo();
    void eventHandler(Event *event) override;

    void saveRoom(std::string editorID, std::string roomID);
    void loadRoom(std::string editorID, std::string roomID, unsigned int saveID);
};

#endif /* Game_hpp */
