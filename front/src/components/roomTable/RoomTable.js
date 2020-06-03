
import React, { Component } from 'react';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import { Link } from "react-router-dom";

import socket from "../../WebSocket.js"



// var ws = await WSPromise;


class RoomTable extends Component {
    _isMounted = false;

    constructor(props) {
        super(props);
        this.handleClick = this.handleClick.bind(this);
        this.updateData = this.updateData.bind(this)
        this.state = {
            rows: {}
        }

        socket.on("tableRoomToC", (data) => {
            console.log("on", "tableRoomToC")
            if (this._isMounted)
                this.setState({ rows: data.rows }, () => console.log("rows:", data.rows))
        })
    }



    componentDidMount() {
        this._isMounted = true;
        this.updateData()

    }
    componentWillUnmount() {
        this._isMounted = false;
    }
    updateData() {
        socket.emit("tableRoomToS", {})
    }

    handleClick(id, name) {
        socket.emit("joinTheRoom", {
            userName: localStorage.getItem("userName"),
            roomName: name,
            roomID: id,
        })

    }


    render() {
        debugger
        return (
            <div>
                <button onClick={this.updateData}>Update</button>

                <TableContainer component={Paper}>
                    <Table aria-label="simple table">
                        <TableHead>
                            <TableRow>
                                <TableCell>Name</TableCell>
                                <TableCell align="right">ID</TableCell>
                                <TableCell align="right">Players</TableCell>
                                <TableCell align="right">size</TableCell>
                                <TableCell align="right">connect</TableCell>
                            </TableRow>
                        </TableHead>
                        <TableBody>
                            {Object.keys(this.state.rows).map((id) => {
                                let row = this.state.rows[id]
                                return (
                                    <TableRow key={id}>
                                        <TableCell component="th" scope="row"> {row.roomName} </TableCell>
                                        <TableCell align="right">{id}</TableCell>
                                        <TableCell align="right">{Object.values(row.players).length}</TableCell>
                                        <TableCell align="right">{row.rows + "*" + row.columns}</TableCell>
                                        <TableCell align="right"><Link to={"/game/" + id} onClick={() => { this.handleClick(id, row.name) }}>CON</Link></TableCell>
                                    </TableRow>
                                )
                            })}
                        </TableBody>
                    </Table>
                </TableContainer>
            </div>
        );
    };
}


export default RoomTable;
