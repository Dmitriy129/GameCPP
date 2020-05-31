#include "GameRoomMemento.hpp"

// GameRoomMemento::GameRoomMemento(std::string filename, v8::Local<v8::Object> data)
// {
//     this->file.open(filename);
//     file << JSONStringified(data);
// }
GameRoomMemento::GameRoomMemento(std::string filename, GameRoom *&gameRoom) : gameRoom(gameRoom)
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

void GameRoomMemento::restoreMemento()
{
    std::string jsonStr;
    ifile >> jsonStr;
    v8::Local<v8::Object> info = JSONParse(jsonStr);
    unsigned int rowsQuantity;
    unsigned int columnsQuantity;
    unsigned int maximumObjectsQuantity;

    if (GetObjProperty(info, "rowsQuantity", rowsQuantity))
        return;
    if (GetObjProperty(info, "columnsQuantity", columnsQuantity))
        return;
    if (GetObjProperty(info, "maximumObjectsQuantity", maximumObjectsQuantity))
        return;

    Field *restoredField = new Field(rowsQuantity, columnsQuantity, maximumObjectsQuantity, gameRoom->getMediator());

    for (unsigned int row = 0; row < rowsQuantity; row++)
        for (unsigned int column = 0; column < rowsQuantity; column++)
        {
            unsigned int landscapeType;
        }

    // GameRoom *restoredGameRoom = new GameRoom(gameRoom->getEditor(), gameRoom->getRoomID(), gameRoom->getRoomName(), )
    //todo
}