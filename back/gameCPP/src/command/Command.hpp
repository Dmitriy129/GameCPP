#ifndef Command_hpp
#define Command_hpp

#include <node.h>
#include "../simplifiedConverter/SimplifiedConverter.hpp"
#include "../TypeСonstants.hpp"

class Command : public SimplifiedConverter
{
protected:
    // v8::Local<v8::Value> response;

public:
    // Command(/* v8::Isolate *isolate */);
    // ~Command();
    // v8::Local<v8::Value> getResponse();
    virtual void execute(v8::Local<v8::Value> request);
};

#endif /* Command_hpp */

/* 

{
    task: "add Object", //1
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        objectType: COMB_OBJ or NEUT_OBJ
        CombatObjectInfo:{
          # or #
        NeutralObjectInfo:{
            x: 1,
            y: 2,
            CombatObjectType: "ArcherTANK",
                       # or #
            NeutralObjectType: "GEN_GOLD",
        }
    }
}

{ done*
    task: "add Room", //2
    params: {
        roomID: "ROOM1234567890",
        roomName: "KoKoKo33"
        fieldInfo:{
            rowsQuantity: 10,
            columnsQuantity: 20,
            maximumObjectsQuantity: 100,
        }
    }
}
{
    task: "add Player", //3
    params: {
        roomID: "ROOM1234567890",
        playerInfo: {
            playerID: "USER1234567890",
            playerName: "Banana12"
        }
    }
}

// {
//     task: "add Base", 
//     params: {
//         roomID: "ROOM1234567890",
//         playerID: "USER1234567890",
//         BaseInfo:{
//             x: 3,
//             y: 4,
//         }
//     }
// }

{
    task: "move",  //4
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo:{
            moveFrom: {
            x: 1,
            y: 2,
            }
            moveTo: {
            x: 3,
            y: 4,
            }
        }
    }
}

{
    task: "get field",
    params: {
        roomID: "ROOM1234567890"
    }
}

{
    task: "update Landscape",
    params: {
        roomID: "ROOM1234567890",
        landscapeInfo:{
            x: 3,
            y: 4,
            landscapeTtype: "Swamp",
        }
    }
}
 */