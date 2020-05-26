#include "GameRoomMemento.hpp"

// GameRoomMemento::GameRoomMemento(std::string filename, v8::Local<v8::Object> data)
// {
//     this->file.open(filename);
//     file << JSONStringified(data);
// }
GameRoomMemento::GameRoomMemento(std::string filename, GameRoom *gameRoom)
{
    this->file.open(filename);
    this->gameRoom = gameRoom;
    file << JSONStringified(gameRoom->getFullInfo());
}

GameRoomMemento::~GameRoomMemento()
{
    file.close();
}

// v8::Local<v8::Object> GameRoomMemento::getMemento()
// {
//     std::string jsonStr;
//     file >> jsonStr;
//     return JSONParse(jsonStr);
// }

void GameRoomMemento::getMemento()
{
    std::string jsonStr;
    file >> jsonStr;
    //todo
}