#include "Rule2.hpp"

Rule2::Rule2()
{
    stepTime = 60;
}

unsigned int Rule2::getType()
{
    return RULE2;
    sequenceOfMoves = [](Player *p1, Player *p2) { return true; };
}

// std::function<bool(Player *, Player *)> Rule2::

template <class T>
bool Rule2::checkWin(GameRoom<T> *gameRoom)
{

    Player *winner = std::find_if(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) { return player->getBase()->getArmyQuantity() >= NEED_UNITS; });
    if (winner != gameRoom->players.end())
    {
        v8::Local<v8::Object> info = Nan::New<v8::Object>();
        gameRoom->SetObjProperty(info, "playerID", winner->getPlayerID());
        gameRoom->SetObjProperty(info, "playerName", winner->getPlayerName());
        gameRoom->fireEvent("winned found", info);
        return true;
    }
    return false;
}
// bool Rule2::checkWin(GameRoom<Rule> *gameRoom)
// {
//     std::find_if(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) { return player->getBase()->getArmyQuantity() >= NEED_UNITS; });
// }