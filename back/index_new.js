

const my_game = require('./gameCPP/build/Release/my_game_cpp.node');
const game = new my_game.UIFacade();
var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var path = require('path');

<<<<<<< HEAD

=======
>>>>>>> 16fac3fcf786cc7fc4a266269a528f6ab854c7db
const PORT = 3030;


app.use(express.static(path.join(__dirname, '../front/build/')));
var bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.sendFile(__dirname + '../front/build/index.html');
});


http.listen(PORT, function () {
    console.log(`Serever started on PORT ${PORT}!`);
});

var clients = {}
<<<<<<< HEAD
=======
var rooms = {}

>>>>>>> 16fac3fcf786cc7fc4a266269a528f6ab854c7db


io.on('connection', (socket) => {
    console.log("*User connected*")
<<<<<<< HEAD
=======

>>>>>>> 16fac3fcf786cc7fc4a266269a528f6ab854c7db
    socket.emit("toStart", { error: "start there" })


    socket.on('save', (id) => {
        clients[id] = socket;
        console.log("*User saved: " + id + "*")
<<<<<<< HEAD
    });


    socket.on('command', (data) => {
        if (data.task == 1)
            socket.join(data.params.roomID);

        gameTest.sendRequest(data).map(elem => {
            emitManager(socket, elem);
        })
    });




    socket.on('disconnect', () => {                             //add delete frome rooms
        console.log("*User disconnected*")
        let userID = getPlayerIDBySocket(socket)
        console.log("*User removed: " + userID + "*")
        delete clients[userID]
=======
    })
    

    socket.on('disconnect', () => {
        console.log("*User disconnected*")
>>>>>>> 16fac3fcf786cc7fc4a266269a528f6ab854c7db
    })
})





<<<<<<< HEAD




/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

function getPlayerIDBySocket(socket) {
    for (const [key, value] of Object.entries(clients))
        if (value.id == socket.id)
            return key
}

function emitManager(socket, data) {
    if (data.eventType == "object updated" || data.eventType == "tabel of GameRooms update")
        io.to(data.data.roomID).emit("object updated", data.data);
}

function getFullRoomInfo(socket, roomID) {
    game.sendRequest({
        task: 5,
        params: {
            roomID: roomID,
        }
    })
}
=======
>>>>>>> 16fac3fcf786cc7fc4a266269a528f6ab854c7db
