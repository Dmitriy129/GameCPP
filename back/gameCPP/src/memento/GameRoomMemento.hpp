#ifndef GameRoomMemento_hpp
#define GameRoomMemento_hpp
#include <fstream>

#include "../simplifiedConverter/SimplifiedConverter.hpp"

class GameRoomMemento : SimplifiedConverter
{
private:
    std::string ID;
    std::ofstream file;

public:
    GameRoomMemento(std::string filename, v8::Local<v8::Object> data);
    ~GameRoomMemento();
    v8::Local<v8::Object> getMemento();
};
#endif /* GameRoomMemento_hpp */
