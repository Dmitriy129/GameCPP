#ifndef Rule1_hpp
#define Rule1_hpp

#include "../Rule.hpp"
#define NEED_RES 100

class Rule1 : public Rule
{
public:
    // bool checkWin(GameRoom<Rule> *gameRoom) override;
    Rule1();
    // std::function<bool(Player *, Player *)> sequenceOfMoves ;
    unsigned int getType() override;
    template <class T>
    bool checkWin(GameRoom<T> *gameRoom);
};
#endif /* Rule1_hpp */
