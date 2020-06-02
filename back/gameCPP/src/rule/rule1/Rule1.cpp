#include "Rule1.hpp"

Rule1::Rule1()
{
    stepTime = 30;
}

unsigned int Rule1::getType()
{
    return RULE1;
    sequenceOfMoves = [](Player *p1, Player *p2) { return p1->getPlayerName() > p2->getPlayerName(); };
}

// std::function<bool(Player *, Player *)> Rule1::sequenceOfMoves = [](Player *p1, Player *p2) { return p1->getPlayerName() > p2->getPlayerName(); }

template <class T>
bool Rule1::checkWin(GameRoom<T> *gameRoom)
{
    Player *winner = std::find_if(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) {
        return player->getResourceBag()->checkQuantity({std::make_pair(GOLD, NEED_RES),
                                                        std::make_pair(WOOD, NEED_RES),
                                                        std::make_pair(FOOD, NEED_RES)});
    });
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