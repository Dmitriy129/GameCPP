#include "GameRoomMemento.hpp"

GameRoomMemento::GameRoomMemento(std::string filename, v8::Local<v8::Object> data)
{
    this->file.open(filename);
    file << JSONStringified(data);
}
GameRoomMemento::~GameRoomMemento()
{
    file.close();
}
v8::Local<v8::Object> GameRoomMemento::getMemento()
{
    std::string jsonStr;
    file >> jsonStr;
    return JSONParse(jsonStr);
}