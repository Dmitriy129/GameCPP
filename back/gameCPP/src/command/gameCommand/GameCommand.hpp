#ifndef GameCommand_hpp
#define GameCommand_hpp

#include "../Command.hpp"
#include "../gameRoomCommand/GameRoomCommand.hpp"
#include "../../game/Game.hpp"

class GameCommand : public Command
{
private:
    Game *game;
    // GameRoomCommand *gameRoomCommand;

public:
    GameCommand(Game *game);
    // ~GameCommand();
    void execute(v8::Local<v8::Value> request) override;
};

#endif /* GameCommand_hpp */