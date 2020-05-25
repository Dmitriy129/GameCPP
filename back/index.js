

const my_game = require('./back/gameCPP/build/Release/my_game_cpp.node');

const gameTest = new my_game.UIFacade();

console.log(gameTest.sendRequest({
    task: 0,
    params: {
        roomID: "ROOM1234567890",
        roomName: "KoKoKo33",
        fieldInfo: {
            rowsQuantity: 5,
            columnsQuantity: 5,
            maximumObjectsQuantity: 100,
        }
    }
}))
console.log("----------------------------");


console.log(gameTest.sendRequest({
    task: 1,
    params: {
        roomID: "ROOM1234567890",
        playerInfo: {
            playerID: "USER1234567890",
            playerName: "Banana12"
        }
    }
}))

console.log("----------------------------");



console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        objectType: 0,
        combatObjectInfo: {
            x: 1,
            y: 1,
            combatObjectType: 0,
        }
    }
}))
console.log("----------------------------");


console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        objectType: 0,
        combatObjectInfo: {
            x: 2,
            y: 2,
            combatObjectType: 2,
        }
    }
}))


console.log("----------------------------");

console.log(gameTest.sendRequest({
    task: 1,
    params: {
        roomID: "ROOM1234567890",
        playerInfo: {
            playerID: "USER12345678901",
            playerName: "Banana121"
        }
    }
}))

console.log("----------------------------");

console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER12345678901",
        objectType: 0,
        combatObjectInfo: {
            x: 3,
            y: 3,
            combatObjectType: 0,
        }
    }
}))

console.log("----------------------------");

console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER12345678901",
        objectType: 0,
        combatObjectInfo: {
            x: 4,
            y: 4,
            combatObjectType: 5,
        }
    }
}))

console.log("----------------------------");

console.log(gameTest.sendRequest({
    task: 4,
    params: {
        roomID: "ROOM1234567890",
    }
}))



console.log("----------------------------");

console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 2,
            },
            moveTo: {
                toX: 4,
                toY: 4,
            }
        }
    }
}))
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 2,
            },
            moveTo: {
                toX: 4,
                toY: 4,
            }
        }
    }
}))
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 2,
            },
            moveTo: {
                toX: 4,
                toY: 4,
            }
        }
    }
}))
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 2,
            },
            moveTo: {
                toX: 4,
                toY: 4,
            }
        }
    }
}))
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 2,
            },
            moveTo: {
                toX: 4,
                toY: 4,
            }
        }
    }
}))



console.log()






/*

{
    task: "add Object", //1
    params: {
        roomID: "ROOM1234567890",
        playerID: "USER1234567890",
        objectType: COMB_OBJ or NEUT_OBJ
        combatObjectInfo:{
          # or #
        NeutralObjectInfo:{
            x: 1,
            y: 2,
            combatObjectType: "ArcherTANK",
                       # or #
            NeutralObjectType: "GEN_GOLD",
        }
    }
}

{
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
 */










// function test_function(test_arg1, test_arg2) {
//     var match = 0;
//     if (test_arg1 == test_arg2) {
//         match = 1;
//     } else {
//         match = 0;
//     }
//     return match;
// }

// console.log(gameTest.setCellUpdate(test_function))

// console.log(gameTest.runCellUpdate())


// console.log(gameTest.testRun())

// // gameTest.runCellUpdate()

// // gameTest.testExecuteСommand()
// // console.log(gameTest.executeСommand.executeСommand)
// // gameTest.executeСommand = () => {
// //     console.log("Command from: js")
// // }
// // gameTest.executeСommand()

// // gameTest.testExecuteСommand()


// // console.log(gameTest.addGameRoom({
// //     roomID: "ROOM7281626384",
// //     roomName: "lala1",
// //     rows: "1",
// //     columns: "3",
// //     maxObjects: "20",
// // }
// // ));
// // console.log(gameTest.addGameRoom({
// //     roomID: "ROOM1234567890",
// //     roomName: "blabla22",
// //     rows: 7,
// //     columns: 9,
// //     maxObjects: 20,
// // }));

// // console.log("----------1--------------");
// // /* 
// // console.log(gameTest.removeGameRoom());

// // console.log("----------2--------------");

// // console.log(gameTest.addPlayerToGameRoom(
// //     {
// //         roomID: "ROOM1234567890",
// //         player: {
// //             playerID: "USER2445565764",
// //             playerName: "ChocoPie05"
// //         }
// //     }
// // ));


// // // console.log(gameTest.addPlayerToGameRoom(
// // //     {
// // //         roomID: "ROOM7281626384",
// // //         player: {
// // //             playerID: "USER2445565764",
// // //             playerName: "ChocoPie05"
// // //         }
// // //     }
// // // ));


// // // console.log("------------3------------");



// // // console.log(gameTest.getGameRoomPlayersIDList(
// // //    {
// // //        roomID: "ROOM1234567890",
// // //    }
// // // ));


// // // console.log("------------4------------");

// // // console.log(gameTest.getGameRoomsIDList());
// // */
// // console.log("------------5------------");

// // console.log(gameTest.getGameRoomFieldLandscapes({
// //     roomID: "ROOM7281626384"
// // }));

// // console.log(gameTest.getGameRoomFieldObjects({
// //     roomID: "ROOM7281626384"
// // }));


// // /*
// // console.log("------------6------------");

// // console.log(gameTest.getGameRoomFieldObjects({
// //     roomID: "ROOM5r78478974874"
// // }));
// //  */
// // console.log("-----------7-------------");

// // console.log(gameTest.getGameRoomsInfoList());

// // console.log("-----------8-------------");


// // console.log(gameTest.executeСommand({
// //     command: "test command",
// // }));
// // console.log(gameTest.executeСommand({}));
// // console.log(gameTest.executeСommand());










