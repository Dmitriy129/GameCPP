#include "Rule2.hpp"

Rule2::Rule2()
{
    stepTime = 60;
}

template <class T>
bool Rule2::checkWin(GameRoom<T> *gameRoom)
{
    std::find_if(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) { return player->getBase()->getArmyQuantity() >= NEED_UNITS; });
}