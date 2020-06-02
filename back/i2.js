

const my_game = require('./gameCPP/build/Release/my_game_cpp.node');

const gameTest = new my_game.UIFacade();
var roomID = "ROOM" + Date.now();

console.log(gameTest.sendRequest({
    task: 0,
    params: {
        roomID: roomID,
        roomName: "KoKoKo33",
        editorID: "EDITOR1234567890",
        rule: 0,
        fieldInfo: {
            rowsQuantity: 8,
            columnsQuantity: 8,
            maximumObjectsQuantity: 100,
        }
    }
}))
console.log("----------------------------");


console.log(gameTest.sendRequest({
    task: 1,
    params: {
        roomID: roomID,
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
        roomID: roomID,
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
        roomID: roomID,
        playerID: "USER1234567890",
        objectType: 0,
        combatObjectInfo: {
            x: 2,
            y: 1,
            combatObjectType: 3,
        }
    }
}))

//create resGen

console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
        objectType: 1,
        neutralObjectInfo: {
            x: 1,
            y: 2,
            neutralObjectType: 7,
        }
    }
}))


//move
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: roomID,
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 1,
            },
            moveTo: {
                toX: 1,
                toY: 2,
            }
        }
    }
}))

console.log("----------------------------");



console.log("---------------SAVE-------------");

console.log(gameTest.sendRequest({
    task: 6,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
    }
}))


console.log("---------------ADDOBJ----------");

console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: roomID,
        playerID: "USER1234567890",
        objectType: 0,
        combatObjectInfo: {
            x: 2,
            y: 3,
            combatObjectType: 4,
        }
    }
}))

console.log("---------------ADDOBJ----------");

//create resGen
console.log(gameTest.sendRequest({
    task: 2,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
        objectType: 1,
        neutralObjectInfo: {
            x: 4,
            y: 3,
            neutralObjectType: 8,
        }
    }
}))

console.log("---------------MOVEOBJ---------");

//move
console.log(gameTest.sendRequest({
    task: 3,
    params: {
        roomID: roomID,
        playerID: "USER1234567890",
        moveInfo: {
            moveFrom: {
                fromX: 2,
                fromY: 3,
            },
            moveTo: {
                toX: 4,
                toY: 3,
            }
        }
    }
}))

console.log("---------------SAVE-------------");

console.log(gameTest.sendRequest({
    task: 6,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
    }
}))


console.log("---------------LOAD------------");


console.log(gameTest.sendRequest({
    task: 7,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
        saveID: 0,
    }
}))


console.log("---------------SAVE-------------");

console.log(gameTest.sendRequest({
    task: 6,
    params: {
        roomID: roomID,
        editorID: "EDITOR1234567890",
    }
}))

