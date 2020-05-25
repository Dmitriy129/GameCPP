
#include "GameRoomCommand.hpp"
GameRoomCommand::GameRoomCommand(GameRoom *gameRoom) /* , v8::Isolate *isolate) : Command(isolate) */
{
    // std::cout << "#grcc#\n";

    this->gameRoom = gameRoom;
    // gameRoom->SetIsolate(isolate);
}

void GameRoomCommand::execute(v8::Local<v8::Value> request)
{
    // std::cout << "#grces#\n";

    v8::Local<v8::Object> objRequest;

    if (request->IsObject())
        objRequest = request->ToObject();
    else
        return;

    /*  */
    unsigned int task;
    v8::Local<v8::Object> params;

    /*  */

    if (!GetObjField(objRequest, "task", task))
        return;
    if (!GetObjField(objRequest, "params", params))
        return;

    // std::cout << "#grce 1#\n";

    if (task == GET_FIELD)
    {
        //TODO add
        gameRoom->getGameRoomFieldData();
    }
    else if (task == ADD_PLAYER)
    {

        /* * * * * */
        v8::Local<v8::Object> playerInfo;
        /*  */ std::string playerID;
        /*  */ std::string playerName;
        /* * * * * */

        if (!GetObjField(params, "playerInfo", playerInfo))
            return;
        if (!GetObjField(playerInfo, "playerID", playerID))
            return;
        if (!GetObjField(playerInfo, "playerName", playerName))
            return;

        // std::cout << "#grce addpl#\n";

        gameRoom->addPlayer(playerID, playerName);
    }
    else
    {

        /* * * * * */
        std::string playerID;
        /* * * * * */

        if (!GetObjField(params, "playerID", playerID))
            return;
        PlayerCommand *playerCommand = new PlayerCommand(gameRoom->getPlayer(playerID) /* , isolate */);

        if (task == MOVE)
        {
            playerCommand->execute(request);
        }
        else if (task == ADD_OBJ)
        {
            // std::cout << "#grce add obj#\n";

            /* * * * * */
            unsigned int objectType;
            /* * * * * */

            if (!GetObjField(params, "objectType", objectType))
                return;
            if (objectType == NEUT_OBJ)
            {
                //ADD Editor( player - admin)
            }
            else if (objectType == COMB_OBJ)
            {
                // std::cout << "#grce add obj comb#\n";

                // PlayerCommand *playerCommand = new PlayerCommand(gameRoom->getPlayer(playerID) /* , isolate */);
                playerCommand->execute(request);
            }
        }
        delete playerCommand;
    }
    // std::cout << "#grcee#\n";
}
