#include "GameProxy.hpp"

namespace demo
{

GameProxy::GameProxy()
{
    this->game = new Game();
}
GameProxy::~GameProxy()
{
    delete this->game;
}

Game *GameProxy::getGame()
{
    return this->game;
}

void GameProxy::Init(v8::Local<v8::Object> exports)
{

    v8::Isolate *isolate = exports->GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::ObjectTemplate> addon_data_tpl = v8::ObjectTemplate::New(isolate);
    addon_data_tpl->SetInternalFieldCount(1);
    v8::Local<v8::Object> addon_data = addon_data_tpl->NewInstance(context).ToLocalChecked();

    v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New, addon_data);
    tpl->SetClassName(v8::String::NewFromUtf8(isolate, "GameProxy", v8::NewStringType::kNormal).ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NODE_SET_PROTOTYPE_METHOD(tpl, "addGameRoom", addGameRoom);
    NODE_SET_PROTOTYPE_METHOD(tpl, "removeGameRoom", removeGameRoom);

    NODE_SET_PROTOTYPE_METHOD(tpl, "executeСommand", executeСommand);
    NODE_SET_PROTOTYPE_METHOD(tpl, "testExecuteСommand", testExecuteСommand);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setCellUpdate", setCellUpdate);
    NODE_SET_PROTOTYPE_METHOD(tpl, "runCellUpdate", runCellUpdate);
    NODE_SET_PROTOTYPE_METHOD(tpl, "testRun", testRun);

    NODE_SET_PROTOTYPE_METHOD(tpl, "addPlayerToGameRoom", addPlayerToGameRoom);
    NODE_SET_PROTOTYPE_METHOD(tpl, "removePlayerFromGameRoom", removePlayerFromGameRoom);
    NODE_SET_PROTOTYPE_METHOD(tpl, "removePlayerEveryWhere", removePlayerEveryWhere);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomPlayersIDList", getGameRoomPlayersIDList);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomsInfoList", getGameRoomsInfoList);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomsIDList", getGameRoomsIDList);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomFieldLandscapes", getGameRoomFieldLandscapes);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomFieldObjects", getGameRoomFieldObjects);
    NODE_SET_PROTOTYPE_METHOD(tpl, "getGameRoomFieldCellInfo", getGameRoomFieldCellInfo);
    NODE_SET_PROTOTYPE_METHOD(tpl, "addBase", addBase);
    NODE_SET_PROTOTYPE_METHOD(tpl, "addUnit", addUnit);

    v8::Local<v8::Function> constructor = tpl->GetFunction(context).ToLocalChecked();
    addon_data->SetInternalField(0, constructor);
    exports->Set(context, v8::String::NewFromUtf8(isolate, "GameProxy", v8::NewStringType::kNormal).ToLocalChecked(), constructor).FromJust();
}

void GameProxy::New(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (args.IsConstructCall())
    {
        GameProxy *obj = new GameProxy();
        obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = {args[0]};
        v8::Local<v8::Function> cons =
            args.Data().As<v8::Object>()->GetInternalField(0).As<v8::Function>();
        v8::Local<v8::Object> result =
            cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

void GameProxy::addGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    std::string roomName;
    unsigned int rowsQuantity = 0;
    unsigned int columnsQuantity = 0;
    unsigned int maxObjectsQuantity = 0;

    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "roomName", roomName, isolate))
        return;

    if (!GetObjField(obj, "rows", rowsQuantity, isolate))
        return;

    if (!GetObjField(obj, "columns", columnsQuantity, isolate))
        return;

    if (!GetObjField(obj, "maxObjects", maxObjectsQuantity, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->addGameRoom(roomID, roomName, rowsQuantity, columnsQuantity, maxObjectsQuantity);

    std::string ret("Room was created.");
    ret += "\n\tRoom ID: " + roomID + "\n\troomName: " + roomName + "\n\tRows: " + std::to_string(rowsQuantity) + "\n\tColumns: " + std::to_string(columnsQuantity) + "\n\tMax Objects: " + std::to_string(maxObjectsQuantity) + "\n";

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}
void GameProxy::removeGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    std::string ret("function 'removeGameRoom' called");
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::addPlayerToGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    v8::Local<v8::Object> player;
    std::string playerID;
    std::string playerName;

    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "player", player, isolate))
        return;
    if (!GetObjField(player, "playerID", playerID, isolate))
        return;
    if (!GetObjField(player, "playerName", playerName, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->addPlayerToGameRoom(roomID, playerID, playerName);

    std::string ret("Player was added.");
    ret += "\n\troomID: " + roomID + "\n\tplayerID: " + (playerID) + "\n\tplayerName: " + (playerName) + "\n";

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::removePlayerFromGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    v8::Local<v8::Object> player;
    std::string playerID;

    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "player", player, isolate))
        return;
    if (!GetObjField(player, "playerID", playerID, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->removePlayerFromGameRoom(roomID, playerID);

    std::string ret("Player was removed.");
    ret += "\n\troomID: " + roomID + "\n\tplayerID: " + (playerID) + "\n";

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::removePlayerEveryWhere(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string playerID;
    /*  */

    if (!GetObjField(obj, "playerID", playerID, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->removePlayerEveryWhere(playerID);

    std::string ret("Player was removed. (EveryWhere)");
    ret += "\n\tPlayerID: " + (playerID) + "\n";

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::getGameRoomsInfoList(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    std::vector<std::string> roomsIDList = gameProxy->game->getGameRoomsIDList();     //room id
    std::vector<std::string> roomsNameList = gameProxy->game->getGameRoomsNameList(); //room name
    // std::vector<unsigned int> playersQuantityList = gameProxy->game->getGameRoomPlayersQuantityList(); //room players q
    std::vector<std::vector<std::string>> playersIDList = gameProxy->game->getGameRoomsPlayersIDList();      //room players
    std::vector<std::vector<std::string>> playersNameList = gameProxy->game->getGameRoomsPlayersNamesList(); //room players
    std::vector<unsigned int> rowsQuantityList = gameProxy->game->getFieldRowsQuantityList();                //room field rows q
    std::vector<unsigned int> columnsQuantityList = gameProxy->game->getFieldColumnsQuantityList();          //room field column q

    /*  */

    v8::Local<v8::Object> response = v8::Object::New(isolate);
    for (unsigned int i = 0; i < roomsIDList.size(); ++i)
    {
        v8::Local<v8::Object> node_obj = v8::Object::New(isolate);
        node_obj->Set(v8::String::NewFromUtf8(isolate, "roomName"), v8::String::NewFromUtf8(isolate, roomsNameList[i].c_str()));
        v8::Local<v8::Object> players = v8::Object::New(isolate);
        for (unsigned int j = 0; j < playersIDList[i].size(); j++)
            players->Set(v8::String::NewFromUtf8(isolate, playersIDList[i][j].c_str()), v8::String::NewFromUtf8(isolate, playersNameList[i][j].c_str()));
        node_obj->Set(v8::String::NewFromUtf8(isolate, "players"), players);
        node_obj->Set(v8::String::NewFromUtf8(isolate, "rows"), v8::Uint32::New(isolate, rowsQuantityList[i]));
        node_obj->Set(v8::String::NewFromUtf8(isolate, "columns"), v8::Uint32::New(isolate, columnsQuantityList[i]));
        node_obj->Set(v8::String::NewFromUtf8(isolate, "acceess"), v8::Boolean::New(isolate, true));
        response->Set(v8::String::NewFromUtf8(isolate, roomsIDList[i].c_str()), node_obj);
    }

    args.GetReturnValue().Set(response);
} // namespace demo

void GameProxy::getGameRoomsIDList(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    std::vector<std::string> roomsIDList = gameProxy->game->getGameRoomsIDList();
    /* 
    std::string ret("Rooms ID List.");
    for (std::string roomID : roomsIDList)
    ret += "\n\troomID: " + roomID;
    */

    v8::Local<v8::Array> roomsIDArray = v8::Array::New(isolate);
    for (unsigned int i = 0; i < roomsIDList.size(); i++)
        roomsIDArray->Set(v8::String::NewFromUtf8(isolate, roomsIDList[i].c_str()), v8::String::NewFromUtf8(isolate, roomsIDList[i].c_str()));
    args.GetReturnValue().Set(roomsIDArray);
    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::getGameRoomFieldCellInfo(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    unsigned int x;
    unsigned int y;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "x", x, isolate))
        return;
    if (!GetObjField(obj, "y", y, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    FieldCell *fieldCell = gameProxy->game->getGameRoom(roomID)->getFieldCell(x, y);

    v8::Local<v8::Object> cellInfo = v8::Object::New(isolate);
    cellInfo->Set(v8::String::NewFromUtf8(isolate, "object"), v8::String::NewFromUtf8(isolate, fieldCell->getObject()->getObjectType().c_str()));
    cellInfo->Set(v8::String::NewFromUtf8(isolate, "landscape"), v8::String::NewFromUtf8(isolate, fieldCell->getLandscape()->getLandscapeType().c_str()));

    /* 
    std::string ret("Players ID List.");
    for (std::string playerID : playersIDList)
    ret += "\n\tplayerID: " + playerID;
    */

    args.GetReturnValue().Set(cellInfo);

    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::getGameRoomPlayersIDList(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    std::vector<std::string> playersIDList = gameProxy->game->getGameRoomPlayersIDList(roomID);
    /* 
    std::string ret("Players ID List.");
    for (std::string playerID : playersIDList)
    ret += "\n\tplayerID: " + playerID;
    */

    v8::Local<v8::Array> playersIDArray = v8::Array::New(isolate);
    for (unsigned int i = 0; i < playersIDList.size(); i++)
        playersIDArray->Set(i, v8::String::NewFromUtf8(isolate, playersIDList[i].c_str()));
    args.GetReturnValue().Set(playersIDArray);

    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::getGameRoomFieldLandscapes(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    std::vector<std::string> landscapesList = gameProxy->game->getGameRoomFieldLandscapes(roomID);
    unsigned int rowsQuantity = gameProxy->game->getFieldRowsQuantity(roomID);
    unsigned int columnsQuantity = gameProxy->game->getFieldColumnsQuantity(roomID);

    /* 
    std::string ret("Landscapes List.");
    for (std::string Landscape : landscapesList)
        ret += "\n\tLandscape: " + Landscape;
    */

    v8::Local<v8::Array> landscapesRow = v8::Array::New(isolate);
    for (unsigned int i = 0; i < rowsQuantity; i++)
    {
        v8::Local<v8::Array> landscapesColumn = v8::Array::New(isolate);
        for (unsigned int j = 0; j < columnsQuantity; j++)
        {
            landscapesColumn->Set(j, v8::String::NewFromUtf8(isolate, landscapesList[i * /* rowsQuantity */ columnsQuantity + j].c_str()));
        }
        landscapesRow->Set(i, landscapesColumn);
    }
    args.GetReturnValue().Set(landscapesRow);

    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::getGameRoomFieldObjects(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    std::vector<std::string> objectsList = gameProxy->game->getGameRoomFieldObjects(roomID);
    unsigned int rowsQuantity = gameProxy->game->getFieldRowsQuantity(roomID);
    unsigned int columnsQuantity = gameProxy->game->getFieldColumnsQuantity(roomID);

    /* 
    std::string ret("objects List.");
    for (std::string object : objectsList)
        ret += "\n\tobject: " + object;
    */

    v8::Local<v8::Array> objectsRow = v8::Array::New(isolate);
    for (unsigned int i = 0; i < rowsQuantity; i++)
    {
        v8::Local<v8::Array> objectsColumn = v8::Array::New(isolate);
        for (unsigned int j = 0; j < columnsQuantity; j++)
        {
            objectsColumn->Set(j, v8::String::NewFromUtf8(isolate, objectsList[i * /* rowsQuantity */ columnsQuantity + j].c_str()));
        }
        objectsRow->Set(i, objectsColumn);
    }
    args.GetReturnValue().Set(objectsRow);
    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::addUnit(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    std::string playerID;
    v8::Local<v8::Object> unitInfo;
    unsigned int x;
    unsigned int y;
    std::string unitType;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "playerID", playerID, isolate))
        return;

    if (!GetObjField(obj, "unitInfo", unitInfo, isolate))
        return;

    if (!GetObjField(unitInfo, "x", x, isolate))
        return;

    if (!GetObjField(unitInfo, "y", y, isolate))
        return;

    if (!GetObjField(unitInfo, "unitType", unitType, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->createUnit(roomID, playerID, x, y, unitType);

    /* 
    std::string ret("objects List.");
    for (std::string object : objectsList)
        ret += "\n\tobject: " + object;
    */
    std::string ret("Unit was created: ");

    ret += unitType + "\n";

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

void GameProxy::addBase(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> arg0 = v8::Local<v8::Value>::Cast(args[0]);
    v8::Local<v8::Object> obj;
    if (arg0->IsObject())
        obj = arg0->ToObject();
    else
        return;

    /*  */
    std::string roomID;
    std::string playerID;
    v8::Local<v8::Object> baseInfo;
    unsigned int x;
    unsigned int y;
    /*  */

    if (!GetObjField(obj, "roomID", roomID, isolate))
        return;
    if (!GetObjField(obj, "playerID", playerID, isolate))
        return;
    if (!GetObjField(obj, "baseInfo", baseInfo, isolate))
        return;
    if (!GetObjField(baseInfo, "x", x, isolate))
        return;
    if (!GetObjField(baseInfo, "y", y, isolate))
        return;

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());

    gameProxy->game->createBase(roomID, playerID, x, y);

    /* 
    std::string ret("objects List.");
    for (std::string object : objectsList)
        ret += "\n\tobject: " + object;
    */
    std::string ret("Base was created: \n");

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, ret.c_str()));
}

/* * * * * * * * * * * * DOP * * * * * * * * * * * * */

void GameProxy::testExecuteСommand(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    executeСommand(args);
}

void GameProxy::executeСommand(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    std::cout << "Command from: cpp\n";
}
void GameProxy::setCellUpdate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    std::cout << "Command from: setCellUpdate\n";
    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());
    gameProxy->cellUpdate = v8::Handle<v8::Function>::Cast(args[0]);

    // gameProxy->cellUpdate = v8::Local<v8::Function>::Cast(args[0]);
    args.GetReturnValue().Set(gameProxy->cellUpdate);

    // GameProxy->cellListner->setCU(v8::Local<v8::Function>::Cast(args[0]));
}

void GameProxy::runCellUpdate(const v8::FunctionCallbackInfo<v8::Value> &args)
{

    v8::Isolate *isolate = args.GetIsolate();
    v8::Handle<v8::Context> context = isolate->GetCurrentContext();
    // v8::Local<v8::Function> cb = v8::Local<v8::Function>::Cast(args[0]);
    // v8::Handle<v8::Function> func = v8::Handle<v8::Function>::Cast(args[0]);
    const unsigned argc = 1;
    v8::Local<v8::Value> argv[argc] = {
        v8::String::NewFromUtf8(isolate,
                                "hello world",
                                v8::NewStringType::kNormal)
            .ToLocalChecked()};

    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());
    // v8::Handle<v8::Function> func1 = v8::Handle<v8::Function>::Cast(gameProxy->cellUpdate);

    // func1->Call(context, argc, argv);

    // v8::Isolate *isolate = args.GetIsolate();
    // v8::Local<v8::Context> context = isolate->GetCurrentContext();

    // const unsigned argc = 1;
    // v8::Local<v8::Value> argv[argc] = {
    //     v8::String::NewFromUtf8(isolate,
    //                             "hello world",
    //                             v8::NewStringType::kNormal)
    //         .ToLocalChecked()};

    // std::cout << "Command from: runCelllUpdate\n";

    // GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args.Holder());
    // // gameProxy->cellUpdate->Call(context, Null(isolate), argc, argv).ToLocalChecked();
    // v8::Local<v8::Function> func1 = v8::Local<v8::Function>::Cast(gameProxy->cellUpdate);
    // std::cout << "Command from: runCelllUpdate\n";

    // func1->Call(context, Null(isolate), argc, argv).ToLocalChecked();
    // std::cout << "Command from: runCelllUpdate\n";
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "true"));
}

void GameProxy::testRun(const v8::FunctionCallbackInfo<v8::Value> &args_)
{
    v8::Isolate *isolate = args_.GetIsolate();
    v8::Handle<v8::Context> context = isolate->GetCurrentContext();
    v8::Handle<v8::Object> global = context->Global();
    GameProxy *gameProxy = ObjectWrap::Unwrap<GameProxy>(args_.Holder());
    v8::Handle<v8::Function> value = v8::Handle<v8::Function>::Cast(gameProxy->cellUpdate);
    // v8::Handle<v8::Value> value = global->Get(v8::String::NewFromUtf8(isolate, "test_function"));

    // if (value->IsFunction())
    if (true)
    {
        // v8::Handle<v8::Function> func = v8::Handle<v8::Function>::Cast(value);
        v8::Handle<v8::Value> args[2];
        args[0] = v8::String::NewFromUtf8(isolate, "value1");
        args[1] = v8::String::NewFromUtf8(isolate, "value2");

        v8::Handle<v8::Value> js_result = value->Call(global, 2, args);

        if (js_result->IsInt32())
        {
            int32_t result = js_result->ToInt32(isolate)->Value();
            std::cout << result << "\n";
            // do something with the result
        }
        args_.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "testRun *true"));
    }
    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "testRun"));
}

////////////////

} // namespace demo
