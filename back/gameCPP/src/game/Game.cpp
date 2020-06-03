#include "Game.hpp"
Game::Game()
{
    this->uuidGen = new UUID;
    this->neutralObjectFactory = new NeutralObjectFactory;
    this->combatObjectTypeFactory = new CombatObjectTypeFactory;
    // this->mediator = new FieldMediator;
}
Game::~Game()
{
    this->gameRooms.clear();
    delete this->uuidGen;
    delete this->neutralObjectFactory;
    delete this->combatObjectTypeFactory;
    // delete this->mediator;
}
// void Game::addGameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, unsigned int maximumObjectsQuantity)
// {
//     Mediator *mediator = new FieldMediator;
//     GameRoom *room = new GameRoom(editorID, roomID, roomName, new Field(rowsQuantity, columnsQuantity, maximumObjectsQuantity, mediator), uuidGen, neutralObjectFactory, combatObjectTypeFactory, mediator /* , isolate */);
//     gameRooms.push_back(room);
//     // gameRooms.push_back(new GameRoom(roomID, roomName, new Field(rowsQuantity, columnsQuantity, maximumObjectsQuantity, mediator), uuidGen, NeutralObjectFactory, combatObjectTypeFactory));
//     room->attachEvent("object updated", this);
//     room->attachEvent("tabel of GameRooms update", this);
//     room->attachEvent("get full field", this);

//     fireEvent("tabel of GameRooms update", getGameRoomsInfo());
// }

Game *Game::p_game;

Game *Game::getInstance()
{
    if (p_game == nullptr)
        p_game = new Game();
    return p_game;
}

void Game::addGameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, unsigned int rule)
{
    // // std::cout << "#3#\n";

    GameRoom<Rule> *room = new GameRoom<Rule>(editorID, roomID, roomName, rowsQuantity, columnsQuantity, uuidGen, neutralObjectFactory, combatObjectTypeFactory, rule);
    // // std::cout << "#4#\n";

    gameRooms.push_back(room);
    // // std::cout << "#8#\n";

    // gameRooms.push_back(new GameRoom(roomID, roomName, new Field(rowsQuantity, columnsQuantity, maximumObjectsQuantity, mediator), uuidGen, NeutralObjectFactory, combatObjectTypeFactory));
    room->attachEvent("object updated", this);
    room->attachEvent("tabel of GameRooms update", this);
    room->attachEvent("get full field", this);
    room->attachEvent("winner found", this);

    // // std::cout << "#9#\n";
    fireEvent("tabel of GameRooms update", getGameRoomsInfo());
}

std::string Game::removeGameRoom(std::string roomID)
{
    std::remove_if(this->gameRooms.begin(), this->gameRooms.end(), [roomID](GameRoom<Rule> *room) {
        return ((room->getRoomID() == roomID) ? true : false);
    });
    return "removed";
}

// void Game::addPlayerToGameRoom(std::string roomID, std::string playerID, std::string playerName)
// {
//     GameRoom<Rule> *room = getGameRoom(roomID);
//     if (room)
//     {
//         room->addPlayer(playerID, playerName);
//         // // std::cout << "Game::addPlayerToGameRoom true\n";
//         return;
//     }
//     // // std::cout << "Game::addPlayerToGameRoom false\n";
// }

// void Game::removePlayerFromGameRoom(std::string roomID, std::string playerID)
// {
//     GameRoom<Rule> *room = getGameRoom(roomID);
//     if (room)
//     {
//         room->removePlayer(playerID);
//         // // std::cout << "Game::removePlayerFromGameRoom true\n";
//         return;
//     }
//     // // std::cout << "Game::removePlayerFromGameRoom false\n";
// }

// void Game::removePlayerEveryWhere(std::string playerID)
// {

//     std::for_each(gameRooms.begin(), gameRooms.end(), [playerID](GameRoom<Rule> *&gameRoom) { gameRoom->removePlayer(playerID); });
//     // // std::cout << "Game::removePlayerEveryWhere true\n";
// }

// std::vector<GameRoom *> Game::getGameRoomsList()
// {
//     return gameRooms;
// }

// std::vector<std::string> Game::getGameRoomsIDList()
// {
//     std::vector<std::string> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getRoomID());
//     });
//     return response;
// }

// std::vector<std::string> Game::getGameRoomsNameList()
// {
//     std::vector<std::string> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getRoomName());
//     });
//     return response;
// }

// std::vector<unsigned int> Game::getGameRoomPlayersQuantityList()
// {
//     std::vector<unsigned int> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getPlayersQuantity());
//     });
//     return response;
// }

// std::vector<std::vector<std::string>> Game::getGameRoomsPlayersNamesList()
// {
//     std::vector<std::vector<std::string>> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getPlayersNames());
//     });
//     return response;
// }

// std::vector<std::vector<std::string>> Game::getGameRoomsPlayersIDList()
// {
//     std::vector<std::vector<std::string>> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getPlayersID());
//     });
//     return response;
// }

// std::vector<unsigned int> Game::getFieldRowsQuantityList()
// {
//     std::vector<unsigned int> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getFieldRowsQuantity());
//     });
//     return response;
// }

// std::vector<unsigned int> Game::getFieldColumnsQuantityList()
// {
//     std::vector<unsigned int> response;
//     std::for_each(this->gameRooms.begin(), this->gameRooms.end(), [&response](GameRoom *room) {
//         response.push_back(room->getFieldColumnsQuantity());
//     });
//     return response;
// }

// std::vector<std::string> Game::getGameRoomPlayersIDList(std::string roomID)
// {
//     std::vector<std::string> response;
//     GameRoom *room = getGameRoom(roomID);
//     if (room)
//     {

//         // // std::cout << "Game::getGameRoomPlayersIDList true\n";
//         response = room->getPlayersID();
//     }
//     // // std::cout << "Game::getGameRoomPlayersIDList false\n";
//     return response;
// }

// std::vector<std::string> Game::getGameRoomFieldLandscapes(std::string roomID)
// {
//     std::vector<std::string> response;
//     GameRoom *room = getGameRoom(roomID);
//     if (room)
//     {

//         // // std::cout << "Game::getGameRoomFieldLandscapes true\n";
//         response = room->getLandscapes();
//     }
//     else
//         // // std::cout << "Game::getGameRoomFieldLandscapes false\n";
//     return response;
// }

// std::vector<std::string> Game::getGameRoomFieldObjects(std::string roomID)
// {
//     std::vector<std::string> response;
//     GameRoom *room = getGameRoom(roomID);
//     if (room)
//     {

//         // // std::cout << "Game::getGameRoomFieldObjects true\n";
//         response = room->getObjects();
//     }
//     else
//         // // std::cout << "Game::getGameRoomFieldObjects false\n";
//     return response;
// }

// unsigned int Game::getFieldRowsQuantity(std::string roomID)
// {
//     GameRoom<Rule> *room = getGameRoom(roomID);
//     if (room)
//     {
//         // // std::cout << "Game::getFieldRowsQuantity true\n";
//         return room->getFieldRowsQuantity();
//     }
//     else
//         // // std::cout << "Game::getFieldRowsQuantity true\n";
//     return 0;
// }
// unsigned int Game::getFieldColumnsQuantity(std::string roomID)
// {
//     GameRoom<Rule> *room = getGameRoom(roomID);
//     if (room)
//     {
//         // // std::cout << "Game::getFieldColumnsQuantity true\n";
//         return room->getFieldColumnsQuantity();
//     }
//     else
//         // // std::cout << "Game::getFieldColumnsQuantity true\n";
//     return 0;
// }

GameRoom<Rule> *Game::getGameRoom(std::string roomID)
{
    std::__1::__wrap_iter<GameRoom<Rule> **> response = std::find_if(gameRooms.begin(), gameRooms.end(), [roomID](GameRoom<Rule> *room) {
        return (room->getRoomID() == roomID);
    });
    if (response == gameRooms.end())
        return nullptr;
    return *response;
}

// void Game::createBase(std::string roomID, std::string playerID, unsigned int rowNumber, unsigned int columnNumber)
// {
//     getGameRoom(roomID)->createBase(playerID, rowNumber, columnNumber);
// }
// void Game::createUnit(std::string roomID, std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type)
// {
//     // // // std::cout << "#1\n";

//     getGameRoom(roomID)->createUnit(playerID, rowNumber, columnNumber, type);
//     // // // std::cout << "#1\n";
// }

std::string Game::executeСommand(std::string playerID, std::string command)
{
    // std::string resolve = "Command comleted: " + "\n\tFor player: " + playerID + "\n\tCommand: " + command;
    return (std::string("") + "Command comleted: " + "\n\tFor player: " + playerID + "\n\tCommand: " + command);
}

v8::Local<v8::Object> Game::getGameRoomsInfo()
{
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    // // std::cout << "#10#\n";

    unsigned int index = 0;
    std::for_each(gameRooms.begin(), gameRooms.end(), [&data, &index, this](GameRoom<Rule> *gameRoom) {
        // // std::cout << "#11#\n";
        SetObjProperty(data, index++, gameRoom->getGameRoomData());
        // // std::cout << "#12#\n";
    });
    // fireEvent("tabel of GameRooms update", data);

    return data;
}

void Game::eventHandler(Event *event)
{

    if (event->getSEventId() == "object updated")
    {
        fireEvent("object updated", event->getData());
    }
    else if (event->getSEventId() == "tabel of GameRooms update")
    {
        fireEvent("tabel of GameRooms update", getGameRoomsInfo());
    }
    else if (event->getSEventId() == "get full field")
    {
        fireEvent("get full field", event->getData());
    }
};

void Game::saveRoom(std::string editorID, std::string roomID)
{

    GameRoom<Rule> *gameRoom = getGameRoom(roomID);
    if (gameRoom->getEditor())
        historyGameRooms[roomID].push_back(new GameRoomMemento(std::string(roomID + "#" + std::to_string(historyGameRooms[roomID].size())), gameRoom));
}
void Game::loadRoom(std::string editorID, std::string roomID, unsigned int saveID)
{
    GameRoom<Rule> *gameRoom = getGameRoom(roomID);
    if (gameRoom->getEditor())
    {
        // // std::cout << "##########Game::loadRoom\n";
        // std::__1::__wrap_iter<GameRoomMemento **> gameRoomMemento = std::find_if(historyGameRooms[roomID].begin(), historyGameRooms[roomID].end(), [saveID](GameRoomMemento *gameRoomMemento) { return gameRoomMemento->getSaveID() == saveID; });
        historyGameRooms[roomID][saveID]->restoreMemento();
    }
}