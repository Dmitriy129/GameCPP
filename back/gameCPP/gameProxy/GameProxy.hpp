#ifndef GameProxy_hpp
#define GameProxy_hpp

#include <node.h>
#include <nan.h>
#include <node_object_wrap.h>

#include "../src/game/Game.hpp"
#include "../src/simplifiedConverter/SimplifiedConverter.hpp"

namespace demo
{

// class CellListner
// {
//     v8::Local<v8::Function> cellUpdate;

// public:
//     void setCU(v8::Local<v8::Function> func1)
//     {
//         cellUpdate = v8::Local<v8::Function>::Cast(func1);
//         // cellUpdate->Call(context, Null(isolate), argc, argv).ToLocalChecked();
//     }
//     void runCU()
//     {
//         v8::Isolate *isolate;
//         v8::Local<v8::Context> context = isolate->GetCurrentContext();
//         const unsigned argc = 1;
//         v8::Local<v8::Value> argv[argc];

//         std::cout << "Command from: runCelllUpdate\n";

//         cellUpdate->Call(context, Null(isolate), argc, argv).ToLocalChecked();
//     }
// };

class GameProxy : public node::ObjectWrap, SimplifiedConverter
{
private:
    Game *game = new Game();
    // CellListner *cellListner = new CellListner();

    // v8::Local<v8::Function> cellUpdate;
    v8::Handle<v8::Function> cellUpdate;

    //methods
    explicit GameProxy();
    ~GameProxy();

    static void New(const v8::FunctionCallbackInfo<v8::Value> &args);
    //game->rooms
    static void addGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void removeGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void getGameRoomsInfoList(const v8::FunctionCallbackInfo<v8::Value> &args);     // add **
    static void getGameRoomsIDList(const v8::FunctionCallbackInfo<v8::Value> &args);       // add done
    static void getGameRoomFieldCellInfo(const v8::FunctionCallbackInfo<v8::Value> &args); // add

    //game->rooms(roomID)->{players or field}
    static void addPlayerToGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args);      // add done
    static void removePlayerFromGameRoom(const v8::FunctionCallbackInfo<v8::Value> &args); // add done
    static void removePlayerEveryWhere(const v8::FunctionCallbackInfo<v8::Value> &args);   // add done

    static void getGameRoomPlayersIDList(const v8::FunctionCallbackInfo<v8::Value> &args);   // add done
    static void getGameRoomFieldLandscapes(const v8::FunctionCallbackInfo<v8::Value> &args); // add done
    static void getGameRoomFieldObjects(const v8::FunctionCallbackInfo<v8::Value> &args);    // add done

    static void addBase(const v8::FunctionCallbackInfo<v8::Value> &args); // add
    static void addUnit(const v8::FunctionCallbackInfo<v8::Value> &args); // add

    //dop
    static void testExecuteСommand(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void executeСommand(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void setCellUpdate(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void runCellUpdate(const v8::FunctionCallbackInfo<v8::Value> &args);
    static void testRun(const v8::FunctionCallbackInfo<v8::Value> &args);

public:
    Game *getGame();
    static void Init(v8::Local<v8::Object> exports);
};

} //namespace demo

#endif /* GameProxy_hpp */
