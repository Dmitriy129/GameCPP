var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var path = require('path');


const PORT = 3030;


app.use(express.static(path.join(__dirname, '/front/build/')));
var bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/front/build/index.html');
});


http.listen(PORT, function () {
    console.log(`Serever started on PORT ${PORT}!`);
});

var clients = {}



io.on('connection', (socket) => {
    console.log("*User connected*")
    socket.emit("toStart", { error: "start there" })


    socket.on('save', (id) => {
        clients[id] = socket;
        console.log("*User saved: " + id + "*")
    })



    socket.on('newRoom', (data) => {
        let roomID = `ROOM${(+new Date).toString(16)}`
        
        
        
        
        
        
        
        console.log(gameTest.addGameRoom({
            roomID: roomID,
            roomName: data.room,
            rows: parseInt(data.row),
            columns: parseInt(data.column),
            maxObjects: parseInt(20),

        }))
        updateRoomsTable();
    })

    socket.on("tableRoomToS", (data) => {
        updateRoomsTable();
    })

    /* * * * * * * IN ROOM * * * * * * * */
    socket.on('joinTheRoom', (data) => {
        socket.join(data.roomID)
        
        
        
        
        
        
        
        
        
        
        console.log(gameTest.addPlayerToGameRoom(
            {
                roomID: data.roomID,
                player: {
                    playerID: (() => { for (const [key, value] of Object.entries(clients)) { if (value.id == socket.id) return key } })(),
                    playerName: data.userName
                }
            }
        ));
        updateRoomsTable();
        updateRoomData(socket, data)
        updateRoomDataPlayers(socket.to(data.roomID), data)
    })

    socket.on("checkRoom", (data) => {
        checkRoom(socket, data.roomID, (room) => console.log("event checkRoom"))
    })


    socket.on("gameRoomToSFull", (data) => {
        updateRoomData(socket, data)
        updateRoomDataPlayers(socket, data)
    })

    socket.on("gameRoomToSPlayers", (data) => {
        updateRoomDataPlayers(socket, data)
    })


    socket.on('leaveTheRoom', (data) => {
        
        
        
        
        
        
        
        
        
        
        
        

        updateRoomsTable();
        updateRoomDataPlayers(socket.to(data.roomID), data)
    })


    /* * * * * * * OUT ROOM * * * * * * * */



    /* * * * * * * * FIELD * * * * * * * */

    socket.on("firstFieldBuildToS", (data) => {
        checkRoom(socket, data.roomID, (room) =>
            socket.emit("firstFieldBuildToC", {
                rows: room.rows,
                columns: room.columns,
                landscapes: gameTest.getGameRoomFieldLandscapes({ roomID: data.roomID }),
                objects: gameTest.getGameRoomFieldObjects({ roomID: data.roomID }),
            }))
    })

    socket.on("CreateBase", (data) => {
        console.log(gameTest.addBase({
            roomID: data.roomID,
            playerID: getPlayerIDBySocket(socket),
            baseInfo: {
                x: parseInt(data.x),
                y: parseInt(data.y),
            }
        }))

        /*  */
        
        
        
        
        
        
        
        checkRoom(socket, data.roomID, (room) =>        
            socket.emit("cellUpdate", {
                x: data.x,
                y: data.y,
                content: gameTest.getGameRoomFieldCellInfo({
                    roomID: data.roomID,
                    x: parseInt(data.x),
                    y: parseInt(data.y)
                }),
            }))
        /*  */
    })
    socket.on("CreateUnit", (data) => {
        console.log(gameTest.getGameRoomsInfoList())
        console.log(gameTest.addUnit({
            roomID: data.roomID,
            playerID: getPlayerIDBySocket(socket),
            unitInfo: {
                x: parseInt(data.x),
                y: parseInt(data.y),
                unitType: data.unitType,
            }
        }))
        /*  */
        checkRoom(socket, data.roomID, (room) =>        
            socket.emit("cellUpdate", {
                x: data.x,
                y: data.y,
                content: gameTest.getGameRoomFieldCellInfo({
                    roomID: data.roomID,
                    x: parseInt(data.x),
                    y: parseInt(data.y)
                }),
            }))
        /*  */
    })
    /* * * * * * * * FIELD * * * * * * * */


    socket.on("roomSMTH", (data) => {
        io.to(data.roomID).emit('roomEVENT#1');
    })



    socket.on('disconnect', () => {                             
        console.log("*User disconnected*")
        let userID = getPlayerIDBySocket(socket)
        console.log("*User removed: " + userID + "*")
        
        
        
        delete clients[userID]
    })
})









/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

function getPlayerIDBySocket(socket) {
    for (const [key, value] of Object.entries(clients))
        if (value.id == socket.id)
            return key
}


function checkRoom(socket, id, checked) {
    let rooms = gameTest.getGameRoomsInfoList()
    if (!rooms[id]) {
        socket.emit("toStart", { error: "room not found" })
        return;
    }
    checked(rooms[id])
}


function updateRoomsTable() {
    io.emit("tableRoomToC", { rows: gameTest.getGameRoomsInfoList() });
}
function updateRoomData(socket, data) {
    
    
    
    
    

    checkRoom(socket, data.roomID, (room) =>
        socket.emit("gameRoomToCFull", {
            roomName: room.roomName,
            roomID: data.roomID,
        }))
    
}

function updateRoomDataPlayers(socket, data) {

    
    checkRoom(socket, data.roomID, (room) =>
        socket.emit("gameRoomToCPlayers", {
            players: Object.values(room.players)
        }))
}


function updateCell(x, y) 
{

}





const my_game = require('./back/gameCPP/build/Release/my_game_cpp.node');

const gameTest = new my_game.GameProxy();