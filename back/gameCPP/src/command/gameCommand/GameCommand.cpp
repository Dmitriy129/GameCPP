
#include "GameCommand.hpp"
GameCommand::GameCommand(Game *game) /* , v8::Isolate *isolate) : Command(isolate) */
{
    // std::cout << "#2#\n";
    this->game = game;

    // game->SetIsolate(isolate);
}

void GameCommand::execute(v8::Local<v8::Value> request)
{

    // std::cout << "#3#\n";

    v8::Local<v8::Object> objRequest;

    if (request->IsObject())
        objRequest = request->ToObject();
    else
        return;

    /* * * * * */
    unsigned int task;
    v8::Local<v8::Object> params;
    /*  */ std::string roomID;
    /* * * * * */

    if (!GetObjField(objRequest, "task", task))
        return;
    if (!GetObjField(objRequest, "params", params))
        return;
    if (!GetObjField(params, "roomID", roomID))
        return;

    if (task == ADD_ROOM)
    {
        /* * * * * */
        std::string roomName;
        v8::Local<v8::Object> fieldInfo;
        /*  */ unsigned int rowsQuantity;
        /*  */ unsigned int columnsQuantity;
        /*  */ unsigned int maximumObjectsQuantity;
        /* * * * * */

        if (!GetObjField(params, "roomName", roomName))
            return;
        if (!GetObjField(params, "fieldInfo", fieldInfo))
            return;
        if (!GetObjField(fieldInfo, "rowsQuantity", rowsQuantity))
            return;
        if (!GetObjField(fieldInfo, "columnsQuantity", columnsQuantity))
            return;
        if (!GetObjField(fieldInfo, "maximumObjectsQuantity", maximumObjectsQuantity))
            return;

        this->game->addGameRoom(roomID, roomName, rowsQuantity, columnsQuantity, maximumObjectsQuantity /* , isolate */);
    }
    else if (task == GET_FIELD || task == ADD_OBJ || task == ADD_PLAYER || task == MOVE)
    {
        GameRoomCommand *gameRoomCommand = new GameRoomCommand(game->getGameRoom(roomID) /* , isolate */);
        gameRoomCommand->execute(request);
        // std::cout << "#4#\n";

        delete gameRoomCommand;
        // std::cout << "#5#\n";
    }
    // std::cout << "#gcee#\n";
}
