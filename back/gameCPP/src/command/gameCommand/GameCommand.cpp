
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

    if (!GetObjProperty(objRequest, "task", task))
        return;
    if (!GetObjProperty(objRequest, "params", params))
        return;
    if (!GetObjProperty(params, "roomID", roomID))
        return;

    if (task == ADD_ROOM)
    {
        /* * * * * */
        std::string roomName;
        std::string editorID;
        v8::Local<v8::Object> fieldInfo;
        /*  */ unsigned int rowsQuantity;
        /*  */ unsigned int columnsQuantity;
        /*  */ unsigned int maximumObjectsQuantity;
        /* * * * * */

        if (!GetObjProperty(params, "editorID", editorID))
            return;
        if (!GetObjProperty(params, "roomName", roomName))
            return;
        if (!GetObjProperty(params, "fieldInfo", fieldInfo))
            return;
        if (!GetObjProperty(fieldInfo, "rowsQuantity", rowsQuantity))
            return;
        if (!GetObjProperty(fieldInfo, "columnsQuantity", columnsQuantity))
            return;
        if (!GetObjProperty(fieldInfo, "maximumObjectsQuantity", maximumObjectsQuantity))
            return;

        this->game->addGameRoom(editorID, roomID, roomName, rowsQuantity, columnsQuantity, maximumObjectsQuantity /* , isolate */);
    }
    else if (task == SAVE_ROOM || task == LOAD_ROOM)
    {
        std::string editorID;
        if (!GetObjProperty(params, "editorID", editorID))
            return;
        if (task == SAVE_ROOM)
        {
            game->saveRoom(editorID, roomID);
        }
        else if (task == LOAD_ROOM)
        {
            unsigned int saveID;
            if (!GetObjProperty(params, "saveID", saveID))
                return;
            game->loadRoom(editorID, roomID, saveID);
        }
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
