#include "GameRoom.hpp"

// GameRoom<Rule>::GameRoom(std::string editorID, std::string roomID, std::string roomName, Field *field, UUID *uuidGen, NeutralObjectFactory *NeutralObjectFactory, CombatObjectTypeFactory *combatObjectTypeFactory, Mediator *mediator)
// {
//     this->roomID = roomID;
//     this->roomName = roomName;
//     this->field = field;
//     this->uuidGen = uuidGen;
//     this->neutralObjectFactory = neutralObjectFactory;
//     this->combatObjectTypeFactory = combatObjectTypeFactory;
//     this->mediator = mediator;
//     // this->field->SetIsolate(isolate);
//     this->field->attachEvent("object updated", this);
//     // this->field->attachEvent("log", this);
//     editor = new Editor(editorID, field, uuidGen, neutralObjectFactory);
// }
template <class T>
GameRoom<T>::GameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, UUID *uuidGen, NeutralObjectFactory *NeutralObjectFactory, CombatObjectTypeFactory *combatObjectTypeFactory, unsigned int rule)
{
    std::cout << "#5#\n";

    this->roomID = roomID;
    this->roomName = roomName;
    this->mediator = new FieldMediator;
    this->field = new Field(rowsQuantity, columnsQuantity, this->mediator);
    this->uuidGen = uuidGen;
    this->neutralObjectFactory = neutralObjectFactory;
    this->combatObjectTypeFactory = combatObjectTypeFactory;
    this->field->attachEvent("object updated", this);
    editor = new Editor(editorID, field, uuidGen, neutralObjectFactory);
    std::cout << "#6#\n";

    this->rule = new T();
    std::cout << "#7#\n";
}

template <>
GameRoom<Rule>::GameRoom(std::string editorID, std::string roomID, std::string roomName, unsigned int rowsQuantity, unsigned int columnsQuantity, UUID *uuidGen, NeutralObjectFactory *NeutralObjectFactory, CombatObjectTypeFactory *combatObjectTypeFactory, unsigned int rule)
{
    std::cout << "#5#\n";

    this->roomID = roomID;
    this->roomName = roomName;
    this->mediator = new FieldMediator;
    this->field = new Field(rowsQuantity, columnsQuantity, this->mediator);
    this->uuidGen = uuidGen;
    this->neutralObjectFactory = neutralObjectFactory;
    this->combatObjectTypeFactory = combatObjectTypeFactory;
    this->field->attachEvent("object updated", this);
    editor = new Editor(editorID, field, uuidGen, neutralObjectFactory);
    std::cout << "#6#\n";
    if (rule == 0)
        this->rule = new Rule1();
    if (rule == 1)
        this->rule = new Rule2();
    std::cout << "#7#\n";
}
// GameRoom<Rule>::GameRoom(std::string roomID, std::string roomName, Field *field)
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

template </* class T */>
GameRoom<Rule>::~GameRoom()
{
    delete this->field;

    delete this->uuidGen;
    delete this->neutralObjectFactory;
    delete this->combatObjectTypeFactory;
}

//about Field
template </* class T */>
FieldCell *GameRoom<Rule>::getFieldCell(unsigned int x, unsigned int y)
{
    return &(this->field->getFieldCell(x, y));
}

template </* class T */>
unsigned int GameRoom<Rule>::getFieldRowsQuantity()
{
    return this->field->getRowsQuantity();
}

template </* class T */>
unsigned int GameRoom<Rule>::getFieldColumnsQuantity()
{
    return this->field->getColumnsQuantity();
}

template <class T>
std::vector<std::string> GameRoom<T>::getLandscapes()
{
    return this->field->getLandscapes();
}

// template </* class T */>
// std::vector<std::string> GameRoom<Rule>::getObjects()
// {
//     return this->field->getObjects();
// }

template </* class T */>
UUID *GameRoom<Rule>::getUuidGen() { return uuidGen; }

template </* class T */>
NeutralObjectFactory *GameRoom<Rule>::getNeutralObjectFactory() { return neutralObjectFactory; }

template </* class T */>
CombatObjectTypeFactory *GameRoom<Rule>::getCombatObjectTypeFactory() { return combatObjectTypeFactory; }

template </* class T */>
Mediator *GameRoom<Rule>::getMediator() { return mediator; }

//about players
template </* class T */>
Editor *GameRoom<Rule>::getEditor()
{
    // return editorID == editor->getEditorID() ? editor : nullptr;
    return editor;
}

template </* class T */>
Player *GameRoom<Rule>::getPlayer(std::string playerID)
{
    Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
        return (player->getPlayerID() == playerID);
    }));
    if (player != *players.end())
        return player;
    return nullptr;
}

template </* class T */>
unsigned int GameRoom<Rule>::getPlayersQuantity()
{
    return this->players.size();
}

template </* class T */>
std::string GameRoom<Rule>::getRoomID()
{
    return this->roomID;
}

template </* class T */>
std::string GameRoom<Rule>::getRoomName()
{
    return this->roomName;
}

template </* class T */>
std::vector<std::string> GameRoom<Rule>::getPlayersID()
{
    std::vector<std::string> response;
    for (auto const &elem : this->players)
        response.push_back(elem->getPlayerID());
    return response;
}

template </* class T */>
std::vector<std::string> GameRoom<Rule>::getPlayersNames()
{
    std::vector<std::string> response;
    std::for_each(this->players.begin(), this->players.end(), [&response](Player *player) { response.push_back(player->getPlayerName()); });
    return response;
}

template </* class T */>
void GameRoom<Rule>::addPlayer(std::string playerID, std::string PlayerName)
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

// void GameRoom<Rule>::createBase(std::string playerID, unsigned int rowNumber, unsigned int columnNumber)
// {

//     Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
//         return (player->getPlayerID() == playerID);
//     }));
//     if (player != *players.end())
//         player->createBase(rowNumber, columnNumber);
// }
// void GameRoom<Rule>::createUnit(std::string playerID, unsigned int rowNumber, unsigned int columnNumber, std::string type)
// {
//     Player *player = (*std::find_if(players.begin(), players.end(), [playerID](Player *player) {
//         return (player->getPlayerID() == playerID);
//     }));
//     if (player != *players.end())
//         player->createUnit(rowNumber, columnNumber, type);
// }
// void GameRoom<Rule>::moveObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
// {
// }
// void GameRoom<Rule>::interactionObject(std::string playerID, unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
// {
// }

template </* class T */>
void GameRoom<Rule>::removePlayer(std::string playerID)
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

// void GameRoom<Rule>::saveMemento(std::string roomID)
// {

// }
// void GameRoom<Rule>::loadMemento(std::string saveID)
// {
// }

template </* class T */>
v8::Local<v8::Object> GameRoom<Rule>::getGameRoomFieldData()
{
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    SetObjProperty(data, "landscapes", field->getLandscapesData());
    SetObjProperty(data, "objects", field->getObjectsData());
    SetObjProperty(data, "rowsQuantity", getFieldRowsQuantity());
    SetObjProperty(data, "columnsQuantity", getFieldColumnsQuantity());
    fireEvent("get full field", data);
    return data;
}

// template </* class T */>
template <>
v8::Local<v8::Object> GameRoom<Rule>::getGameRoomData()
{
    std::cout << "#13#\n";
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    SetObjProperty(data, "roomID", roomID);
    SetObjProperty(data, "roomName", roomName);
    SetObjProperty(data, "players", static_cast<unsigned int>(players.size()));
    SetObjProperty(data, "fieldSize", std::to_string(getFieldRowsQuantity()) + " * " + std::to_string(getFieldColumnsQuantity()));
    return data;
}

template </* class T */>
void GameRoom<Rule>::eventHandler(Event *event)
{
    if (event->getSEventId() == "object updated")
    {
        v8::Local<v8::Object> data = Nan::New<v8::Object>();
        SetObjProperty(data, "objectInfo", event->getData());
        SetObjProperty(data, "roomID", getRoomID());

        fireEvent("object updated", data);
    }
};

template </* class T */>
v8::Local<v8::Object> GameRoom<Rule>::getFullInfo()
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