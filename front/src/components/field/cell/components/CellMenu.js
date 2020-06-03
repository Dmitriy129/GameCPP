import React from 'react';
// import Button from '@material-ui/core/Button';
import Menu from '@material-ui/core/Menu';
import MenuItem from '@material-ui/core/MenuItem';
import socket from '../../../../WebSocket';


export default function CellMenu(props) {
    const [anchorEl, setAnchorEl] = React.useState(props.event);

    const handleClick = (event) => {
        setAnchorEl(event.currentTarget);
    };

    const handleClose = () => {
        props.close();
        // setAnchorEl(null);
    };

    const CreateBase = () => {

        socket.emit("CreateBase", {
            roomID: window.location.hash.replace(/#\/.*\//, ''),
            x: props.x,
            y: props.y,
        })

        handleClose()
    }
    const CreateUnit = () => {

        socket.emit("CreateUnit", {
            roomID: window.location.hash.replace(/#\/.*\//, ''),
            x: props.x,
            y: props.y,
            unitType: "archerDPS"
        })

        handleClose()
    }
    const MoveUnit = () => {

        handleClose()
    }




    return (
        <div>

            <Menu
                id="simple-menu"
                anchorEl={anchorEl}
                keepMounted
                open={Boolean(anchorEl)}
                onClose={handleClose}
            >
                <MenuItem onClick={CreateBase}>Create Base</MenuItem>
                <MenuItem onClick={CreateUnit}>Create Unit</MenuItem>
            </Menu>
        </div>
    );
}
