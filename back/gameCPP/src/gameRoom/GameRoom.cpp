#include "GameRoom.hpp"

GameRoom::GameRoom(std::string editorID, std::string roomID, std::string roomName, Field *field, UUID *uuidGen, NeutralObjectFactory *NeutralObjectFactory, CombatObjectTypeFactory *combatObjectTypeFactory, Mediator *mediator)
{
    this->roomID = roomID;
    this->roomName = roomName;
    this->field = field;
    this->uuidGen = uuidGen;
    this->neutralObjectFactory = neutralObjectFactory;
    this->combatObjectTypeFactory = combatObjectTypeFactory;
    this->mediator = mediator;
    // this->field->SetIsolate(isolate);
    this->field->attachEvent("object updated", this);
    // this->field->attachEvent("log", this);
    editor = new Editor(editorID, field, uuidGen, neutralObjectFactory);
}
// GameRoom::GameRoom(std::string roomID, std::string roomName, Field *field)
// {
//     this->roomID = roomID;
//     this->roomName = roomName;
//     this->field = field;
//     this->uuidGen = new UUID;
//     this->neutralObjectFactory = new NeutralObjectFactory;
//     this->combatObjectTypeFactory = new CombatObjectTypeFactory;
//     this->field->attachEvent("object updated", this);
//     // this->field->attachEvent("log", this);
//     editor = new Editor(field, neutralObjectFactory);
// }

GameRoom::~GameRoom()
{
    delete this->field;

    delete this->uuidGen;
    delete this->neutralObjectFactory;
    delete this->combatObjectTypeFactory;
}

//about Field
FieldCell *GameRoom::getFieldCell(unsigned int x, unsigned int y)
{
    return &(this->field->getFieldCell(x, y));
}

unsigned int GameRoom::getFieldRowsQuantity()
{
    return this->field->getRowsQuantity();
}

unsigned int GameRoom::getFieldColumnsQuantity()
{
    return this->field->getColumnsQuantity();
}

// std::vector<std::string> GameRoom::getLandscapes()
// {
//     return this->field->getLandscapes();
// }

// std::vector<std::string> GameRoom::getObjects()
// {
//     return this->field->getObjects();
// }

UUID *GameRoom::getUuidGen() { return uuidGen; }

NeutralObjectFactory *GameRoom::getNeutralObjectFactory() { return neutralObjectFactory; }

CombatObjectTypeFactory *GameRoom::getCombatObjectTypeFactory() { return combatObjectTypeFactory; }

Mediator *GameRoom::getMediator() { return mediator; }

//about players
Editor *GameRoom::getEditor(std::string editorID)
{
    return editorID == editor->getEditorID() ? editor : nullptr;
}

Player *GameRoom::getPlayer(std::string playerID)
{
    Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
        return (player->getPlayerID() == playerID);
    }));
    if (player != *players.end())
        return player;
    return nullptr;
}

unsigned int GameRoom::getPlayersQuantity()
{
    return this->players.size();
}

std::string GameRoom::getRoomID()
{
    return this->roomID;
}

std::string GameRoom::getRoomName()
{
    return this->roomName;
}

std::vector<std::string> GameRoom::getPlayersID()
{
    std::vector<std::string> response;
    for (auto const &elem : this->players)
        response.push_back(elem->getPlayerID());
    return response;
}

std::vector<std::string> GameRoom::getPlayersNames()
{
    std::vector<std::string> response;
    std::for_each(this->players.begin(), this->players.end(), [&response](Player *player) { response.push_back(player->getPlayerName()); });
    return response;
}

void GameRoom::addPlayer(std::string playerID, std::string PlayerName)
{
    Player *player = new Player(playerID, PlayerName, field, uuidGen, combatObjectTypeFactory);
    player->attachEvent("log", this);

    this->players.push_back(player);
    std::cout << "GameRoom::addPlayer true\n";
    fireEvent("tabel of GameRooms update");

    // v8::Local<v8::Object> data = Nan::New<v8::Object>();
    // SetObjProperty(data, "roomID", getRoomID());
    // SetObjProperty(data, "msg", "new player added");
    // v8::Local<v8::Object> playerInfo = Nan::New<v8::Object>();
    // SetObjProperty(playerInfo, "playerID", player->getPlayerID());
    // SetObjProperty(playerInfo, "playerName", player->getPlayerName());
    // SetObjProperty(data, "playerInfo", playerInfo);
    // fireEvent("log", data);
}

// void GameRoom::createBase(std::string playerID, unsigned int rowNumber, unsigned int columnNumber)
// {

//     Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
//         return (player->getPlayerID() == playerID);
//     }));
//     if (player != *players.end())
//         player->createBase(rowNumber, columnNumber);
// }
// void GameRoom::createUnit(std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type)
// {
//     Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
//         return (player->getPlayerID() == playerID);
//     }));
//     if (player != *players.end())
//         player->createUnit(rowNumber, columnNumber, type);
// }
// void GameRoom::moveObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
// {
// }
// void GameRoom::interactionObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
// {
// }

void GameRoom::removePlayer(std::string playerID)
{
    // for (int i = 0; i < this->players.size(); i++)
    //     if (elem->getPlayerID() == playerID)

    this->players.erase((std::remove_if(this->players.begin(), this->players.end(), [playerID](Player *player) {
                            std::cout << (player->getPlayerID() == playerID) << "\n";
                            return (player->getPlayerID() == playerID ? true : false);
                        })),
                        this->players.end());
    // return "removed";
}

// void GameRoom::saveMemento(std::string roomID)
// {

// }
// void GameRoom::loadMemento(std::string saveID)
// {
// }

v8::Local<v8::Object> GameRoom::getGameRoomFieldData()
{
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    SetObjProperty(data, "landscapes", field->getLandscapesData());
    SetObjProperty(data, "objects", field->getObjectsData());
    SetObjProperty(data, "rowsQuantity", getFieldRowsQuantity());
    SetObjProperty(data, "columnsQuantity", getFieldColumnsQuantity());
    fireEvent("get full field", data);
    return data;
}

v8::Local<v8::Object> GameRoom::getGameRoomData()
{
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    SetObjProperty(data, "roomID", roomID);
    SetObjProperty(data, "roomName", roomName);
    SetObjProperty(data, "players", (unsigned int)players.size());
    SetObjProperty(data, "fieldSize", std::to_string(getFieldRowsQuantity()) + " * " + std::to_string(getFieldColumnsQuantity()));
    return data;
}

void GameRoom::eventHandler(Event *event)
{
    if (event->getSEventId() == "object updated")
    {
        v8::Local<v8::Object> data = Nan::New<v8::Object>();
        SetObjProperty(data, "objectInfo", event->getData());
        SetObjProperty(data, "roomID", getRoomID());

        fireEvent("object updated", data);
    }
};

v8::Local<v8::Object> GameRoom::getFullInfo()
{
    v8::Local<v8::Object> info = Nan::New<v8::Object>();
    v8::Local<v8::Array> playersInfo = Nan::New<v8::Array>();

    SetObjProperty(info, "field", field->getFullInfo());
    // for (unsigned int index = 0; index < players.size(); index++)
    // SetArrProperty(playersInfo, index, players);
    std::for_each(players.begin(), players.end(), [this, &playersInfo](Player *player) { SetArrProperty(playersInfo, playersInfo->Length(), player->getFullInfo()); });
    SetObjProperty(info, "playersInfo", playersInfo);
    return info;
}