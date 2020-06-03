
#include "GameRoomCommand.hpp"

GameRoomCommand::GameRoomCommand(GameRoom<Rule> *gameRoom) /* , v8::Isolate *isolate) : Command(isolate) */
{
    // // // // std::cout << "#grcc#\n";

    this->gameRoom = gameRoom;
    // gameRoom->SetIsolate(isolate);
}

void GameRoomCommand::execute(v8::Local<v8::Value> request)
{
    // // // // std::cout << "#grces#\n";

    v8::Local<v8::Object> objRequest;

    if (request->IsObject())
        objRequest = request->ToObject();
    else
        return;

    /*  */
    unsigned int task;
    v8::Local<v8::Object> params;

    /*  */

    if (!GetObjProperty(objRequest, "task", task))
        return;
    if (!GetObjProperty(objRequest, "params", params))
        return;

    // // // // std::cout << "#grce 1#\n";

    if (task == GET_FULL)
    {
        //TODO add
        try
        {
            // gameRoom->getGameRoomFieldData(); //add except
            gameRoom->fireEvent("get full room", gameRoom->getFullInfo());
        }
        catch (Except &except)
        {
            fireEvent("except", except.getLog());
            // throw(Except("The object cannot be moved to this cell.(landscape)", "void Field::moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)", 0));
        }
    }
    else if (task == ADD_PLAYER)
    {

        /* * * * * */
        v8::Local<v8::Object> playerInfo;
        /*  */ std::string playerID;
        /*  */ std::string playerName;
        /* * * * * */

        if (!GetObjProperty(params, "playerInfo", playerInfo))
            return;
        if (!GetObjProperty(playerInfo, "playerID", playerID))
            return;
        if (!GetObjProperty(playerInfo, "playerName", playerName))
            return;

        // // std::cout << "#grce addpl#\n";

        try
        {
            gameRoom->addPlayer(playerID, playerName); //add except
        }
        catch (Except &except)
        {
            fireEvent("except", except.getLog());
            // throw(Except("The object cannot be moved to this cell.(landscape)", "void Field::moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)", 0));
        }
    }
    else
    {
        /* * * * * */
        std::string userID;
        /* * * * * */
        // std::cout << "#2#\n";

        Command *command;
        // command->attachEvent("except", this);

        if (GetObjProperty(params, "playerID", userID))
        {
            // std::cout << "######1####\n";
            if (gameRoom->checkPermission(userID))
            {
                Player *player = gameRoom->getPlayer(userID);
                if (player == nullptr)
                    return;
                // std::cout << "######2####\n";

                command = new PlayerCommand(player);
                command->attachEvent("except", this);

                gameRoom->nextPlayer();
            }
            else
            {

                v8::Local<v8::Object> res = Nan::New<v8::Object>();
                gameRoom->SetObjProperty(res, "playerID", userID);
                gameRoom->fireEvent("player does not have permission", res);
                // std::cout << "#player does not have permission#\n";
                return;
            }
            //     // std::cout << "######3####\n";
        }
        else if (GetObjProperty(params, "editorID", userID))
        {
            Editor *editor = gameRoom->getEditor();
            if (editor == nullptr)
                return;
            command = new EditorCommand(editor);
            command->attachEvent("except", this);
        }

        if (task == MOVE)
        {
            command->execute(request);
        }
        else if (task == ADD_OBJ)
        {
            // std::cout << "#3#\n";

            command->execute(request);

            // // // // std::cout << "#grce add obj#\n";

            /* * * * * */
            unsigned int objectType;
            /* * * * * */

            if (!GetObjProperty(params, "objectType", objectType))
                return;
            if (objectType == NEUT_OBJ)
            {
                //ADD Editor( player - admin)
            }
            else if (objectType == COMB_OBJ)
            {
                // // // // std::cout << "#grce add obj comb#\n";

                // command *command = new command(gameRoom->getPlayer(userID) /* , isolate */);
            }
        }

        delete command;
    }
    // // // // std::cout << "#grcee#\n";
}
