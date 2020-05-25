import React, { Component } from 'react';
import Field from '../field/Field.js';
import socket from "../../WebSocket.js"



class GameRoom extends Component {
    _isMounted = false;
    constructor(props) {
        super(props);
        this.state = {
            name: '',
            id: window.location.hash.replace(/#\/.*\//, ''),
            players: {}
        }
        socket.on("gameRoomToCFull", (data) => {
            if (this._isMounted)
                this.setState({
                    name: data.roomName,
                    id: data.roomID,
                    players: data.players,
                })

        })
        socket.emit("checkRoom", { roomID: window.location.hash.replace(/#\/.*\//, '') })

        socket.on("gameRoomToCPlayers", (data) => {
            debugger
            if (this._isMounted)
                this.setState({ players: data.players })
        })
    }

    componentDidMount() {
        this._isMounted = true;
        socket.emit("gameRoomToSFull", {
            roomName: this.state.name,
            roomID: this.state.id,
        })

    }

    componentWillUnmount() {
        this._isMounted = false;
        socket.emit("leaveTheRoom", { roomID: this.state.id })
    }

    render() {
        let playerList = []
        // debugger
        if (this.state.players)
            Object.values(this.state.players).forEach(elem =>
                playerList.push(
                    <li key={playerList.length}>
                        {elem}
                    </li>
                )
            )
        return (

            < div >
                <h1>Hello, {localStorage.getItem("userName")}</h1>
                <ul>

                    {playerList}
                </ul>
                <Field id={this.state.id} />
            </div >






        )
    };
}


export default GameRoom;

