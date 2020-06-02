#ifndef Rule_hpp
#define Rule_hpp

// #include "../gameRoom/GameRoom.hpp"
#include <map>
#include "../player/Player.hpp"
#include "../TypeСonstants.hpp"

template <typename T>
class GameRoom;

class Rule
{
protected:
    // unsigned int playersQuantity;
    double stepTime;

    // unsigned int rowsQuantity;
    // unsigned int columnsQuantity;

public:
    // virtual bool checkWin(GameRoom<Rule> *gameRoom) = 0;
    std::function<bool(Player *&, Player *&)> sequenceOfMoves;
    virtual unsigned int getType() = 0;
    double getStepTime();
    template <class T>
    bool checkWin(GameRoom<T> *gameRoom);
};
#endif /* Rule_hpp */
