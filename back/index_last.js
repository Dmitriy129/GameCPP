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
var rooms = {}


io.on('connection', (socket) => {
    console.log("*User connected*")


    socket.on('save', (id) => {
        clients[id] = socket;
        console.log("*User saved: " + id + "*")
    })



    socket.on('newRoom', (data) => {
        rooms[`ROOM${(+new Date).toString(16)}`] = {
            name: data.room,
            rows: data.row,
            columns: data.column,
            acceess: true,
            players: []
        }
        updateRoomsTable();
    })

    socket.on("tableRoomToS", (data) => {
        updateRoomsTable();
    })

    /* * * * * * * IN ROOM * * * * * * * */
    socket.on('joinTheRoom', (data) => {
        socket.join(data.roomID)
        rooms[data.roomID].players.push({
            name: data.userName,
            clientID: (() => {
                for (const [key, value] of Object.entries(clients)) {
                    // console.log(value.id, socket.id)
                    if (value.id == socket.id)
                        return key
                }
            })()
        })
        updateRoomsTable();
        updateRoomData(socket, data)
        updateRoomDataPlayers(socket.to(data.roomID), data)
    })

    socket.on("checkRoom", (data) => {
        checkRoom(socket, data.roomID, () => console.log("event checkRoom"))
    })


    socket.on("gameRoomToSFull", (data) => {
        updateRoomData(socket, data)
        updateRoomDataPlayers(socket, data)
    })

    socket.on("gameRoomToSPlayers", (data) => {
        updateRoomDataPlayers(socket, data)
    })


    socket.on('leaveTheRoom', (data) => {
        checkRoom(socket, data.roomID, () => {
            socket.leave(data.roomID)
            rooms[data.roomID].players = rooms[data.roomID].players.filter(player => clients[player.clientID] != socket)
            console.log(rooms[data.roomID].players)
        })

        updateRoomsTable();
        updateRoomDataPlayers(socket.to(data.roomID), data)
    })


    /* * * * * * * OUT ROOM * * * * * * * */



    /* * * * * * * * FIELD * * * * * * * */

    socket.on("firstFieldBuildToS", (data) => {
        checkRoom(socket, data.roomID, () =>
            socket.emit("firstFieldBuildToC", {
                rows: rooms[data.roomID].rows,
                columns: rooms[data.roomID].columns,
                objects: Array(parseInt(rooms[data.roomID].rows)).fill(Array(parseInt(rooms[data.roomID].columns)).fill('o').map((e, i) => e + (i % 2 + 1))),
                landscape: Array(parseInt(rooms[data.roomID].rows)).fill(Array(parseInt(rooms[data.roomID].columns)).fill('l').map((e, i) => e + (i % 2 + 1))),
            }))
    })

    /* * * * * * * * FIELD * * * * * * * */


    socket.on("roomSMTH", (data) => {
        io.to(data.roomID).emit('roomEVENT#1');
    })



    socket.on('disconnect', () => {                             //add delete frome rooms
        console.log("*User disconnected*")
        for (const [key, value] of Object.entries(clients)) {
            if (value.id !== socket.id) continue;
            delete clients[key]
            console.log("*User removed: " + key + "*")

        }
    })
})









/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

function checkRoom(socket, id, checked) {
    if (!rooms[id]) {
        socket.emit("toStart", { error: "room not found" })
        return;
    }
    checked()
}


function updateRoomsTable() {
    io.emit("tableRoomToC", { rows: rooms });
}
function updateRoomData(socket, data) {
    checkRoom(socket, data.roomID, () =>
        socket.emit("gameRoomToCFull", {
            roomName: rooms[data.roomID].name,
            roomID: data.roomID,
        }))
    // updateRoomDataPlayers(socket)
}

function updateRoomDataPlayers(socket, data) {
    checkRoom(socket, data.roomID, () =>
        socket.emit("gameRoomToCPlayers", {
            players: Array.from(rooms[data.roomID].players, elem => elem.name)
        }))
}

