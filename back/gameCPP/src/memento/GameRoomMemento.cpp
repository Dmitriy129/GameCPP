#include "GameRoomMemento.hpp"

// GameRoomMemento::GameRoomMemento(std::string filename, v8::Local<v8::Object> data)
// {
//     this->file.open(filename);
//     file << JSONStringified(data);
// }
GameRoomMemento::GameRoomMemento(std::string filename, GameRoom *gameRoom) : gameRoom(gameRoom)
{
    std::string dir = "saves/" + gameRoom->getRoomName() + "#" + gameRoom->getRoomID();
    // mkdir(dir);
    if (!std::__fs::filesystem::exists(dir))
        std::__fs::filesystem::create_directory(dir);

    // this->gameRoom = gameRoom;
    {
        std::ofstream ofile;
        ofile.open(dir + "/" + filename + ".json");
        ofile << JSONStringified(gameRoom->getFullInfo());
        ofile.close();
    }
    this->ifile.open(dir + "/" + filename + ".json");
}

GameRoomMemento::~GameRoomMemento()
{
    ifile.close();
}

std::string GameRoomMemento::getSaveID() { return saveID; }

// v8::Local<v8::Object> GameRoomMemento::getMemento()
// {
//     std::string jsonStr;
//     file >> jsonStr;
//     return JSONParse(jsonStr);
// }

void GameRoomMemento::getMemento()
{
    std::string jsonStr;
    ifile >> jsonStr;
    v8::Local<v8::Object> info = JSONParse(jsonStr);

    //todo
}