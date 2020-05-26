#ifndef GameRoomMemento_hpp
#define GameRoomMemento_hpp
#include <fstream>

#include "../simplifiedConverter/SimplifiedConverter.hpp"
// #include "../gameRoom/GameRoom.hpp"

class GameRoom;
class GameRoomMemento : SimplifiedConverter
{
private:
    std::string ID;
    std::ofstream file;

public:
    // GameRoomMemento(std::string filename, v8::Local<v8::Object> data);
    GameRoomMemento(std::string filename, GameRoom *gameRoom);
    ~GameRoomMemento();
    // v8::Local<v8::Object> getMemento();
    void getMemento();
};
#endif /* GameRoomMemento_hpp */
