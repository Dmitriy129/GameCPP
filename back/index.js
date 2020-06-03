

const my_game = require('./gameCPP/build/Release/my_game_cpp.node');
const game = new my_game.UIFacade();
var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var path = require('path');

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
var rooms = {}



io.on('connection', (socket) => {
    console.log("*User connected*")

    socket.emit("toStart", { error: "start there" })


    socket.on('save', (id) => {
        clients[id] = socket;
        console.log("*User saved: " + id + "*")
    })
    

    socket.on('disconnect', () => {
        console.log("*User disconnected*")
    })
})





