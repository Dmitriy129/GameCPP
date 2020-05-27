#ifndef GameRoomMemento_hpp
#define GameRoomMemento_hpp
#include <filesystem>
#include <fstream>
// std::filesystem

#include "../simplifiedConverter/SimplifiedConverter.hpp"
#include "../gameRoom/GameRoom.hpp"

// class GameRoom;
class GameRoomMemento : SimplifiedConverter
{
private:
    std::string saveID;
    std::ifstream ifile;
    GameRoom *gameRoom;

public:
    // GameRoomMemento(std::string filename, v8::Local<v8::Object> data);
    GameRoomMemento(std::string filename, GameRoom *gameRoom);
    ~GameRoomMemento();
    std::string getSaveID();

    // v8::Local<v8::Object> getMemento();
    void getMemento();
};
#endif /* GameRoomMemento_hpp */
