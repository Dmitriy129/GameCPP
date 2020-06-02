#include "Rule1.hpp"

Rule1::Rule1()
{
    stepTime = 30;
}

template <class T>
bool Rule1::checkWin(GameRoom<T> *gameRoom)
{
    std::find_if(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) {
        return player->getResourceBag()->checkQuantity({std::make_pair(GOLD, NEED_RES),
                                                        std::make_pair(WOOD, NEED_RES),
                                                        std::make_pair(FOOD, NEED_RES)});
    });
}