
#ifndef GameRoomState_hpp
#define GameRoomState_hpp

#include <map>
#include "../../player/Player.hpp"
#include "../../timer/Timer.hpp"

class GameRoomState
{
protected:
    utils::Timer *timer;
    Player *nowPlayer;

public:
    bool checkPermission(std::string playerID);
    virtual void nextPlayer() = 0;
};
#endif /* GameRoomState_hpp */
