#ifndef Rule_hpp
#define Rule_hpp

// #include "../gameRoom/GameRoom.hpp"
#include <map>
#include "../player/Player.hpp"
#include "../TypeСonstants.hpp"

template <class T>
class GameRoom;

class Rule
{
protected:
    // unsigned int playersQuantity;
    double stepTime;
    // unsigned int rowsQuantity;
    // unsigned int columnsQuantity;

public:
    double getStepTime();
    // template <>
    template <class T>
    bool checkWin(GameRoom<T> *gameRoom);
};
#endif /* Rule_hpp */
