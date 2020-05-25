#ifndef GameRoomCommand_hpp
#define GameRoomCommand_hpp

#include "../Command.hpp"
#include "../playerCommand/PlayerCommand.hpp"
#include "../../gameRoom/GameRoom.hpp"

class GameRoomCommand : public Command
{
private:
    GameRoom *gameRoom;
    // PlayerCommand *playerCommand;

public:
    GameRoomCommand(GameRoom *gameRoom);
    // ~GameRoomCommand();
    void execute(v8::Local<v8::Value> request) override; //TODO
};

#endif /* GameRoomCommand_hpp */