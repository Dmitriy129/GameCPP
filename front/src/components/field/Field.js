import React, { Component } from 'react';
import CellContainer from './cell/CellContainer.js';
// import PinchZoomPan from '../pinchZoomPan/PinchZoomPan.js';
import socket from "../../WebSocket.js"
import "./field.css";
import { array } from 'prop-types';

const BASE_WIDTH = window.innerWidth / 20;


class Field extends Component {
    _isMounted = false;
    scale = 1
    cells = Array()

    constructor(props) {

        super(props);
        this.cells = Array()
        // this.updateCell = this.updateCell.bind(this)
        this.state = {
            cells: [],
            roomID: props.id,
            form: {
                size: /* props.step || */ BASE_WIDTH,
                rows: props.rows || 0,
                columns: props.columns || 0,
            },
            content: {
                landscapes: props.landscape || [[]],//[][]
                objects: props.objects || [[]]//[][]
            }
        }

        socket.on("firstFieldBuildToC", (data) => {
            if (this._isMounted) {


                this.refs.mainField.style.height = (BASE_WIDTH * data.rows) + "px"
                this.refs.mainField.style.width = (BASE_WIDTH * data.columns) + "px"
                this.setState({
                    form: {
                        rows: data.rows,
                        columns: data.columns,
                    }
                })
                let cells = [];
                for (let i = 0; i < data.rows; i++)
                    for (let j = 0; j < data.columns; j++) {

                        cells[i * data.columns + j] = (<CellContainer
                            size={BASE_WIDTH}
                            key={"CellContainer" + i + "_" + j}
                            id={i + "_" + j}
                            x={i}
                            y={j}
                            landscape={data.landscapes[i][j]}
                            object={data.objects[i][j]}
                        />);
                    }
                this.setState({ cells: cells })
            }
            // this.render();

        })
        socket.on("cellUpdate", (data) => {
            if (this._isMounted) {


                this.refs.mainField.style.height = (BASE_WIDTH * data.rows) + "px"
                this.refs.mainField.style.width = (BASE_WIDTH * data.columns) + "px"
                // this.setState(prevState => {

                //     return {
                //         content: {
                //             landscapes: [[]],
                //             objects: [[]],

                //         }
                //     }
                // })
                // delete this.cells[data.x * this.state.form.columns + data.y]
                // this.cells[data.x * this.state.form.columns + data.y] = <CellContainer
                //     size={BASE_WIDTH}
                //     key={"CellContainer" + data.x + "_" + data.y}
                //     id={data.x + "_" + data.y}
                //     x={data.x}
                //     y={data.y}
                //     landscape={data.content.landscape}
                //     object={data.content.object}
                // />

                this.setState(prevState => {
                    let cells = prevState.cells

                    // delete cells[data.x * this.state.form.columns + data.y];
                    cells[data.x * this.state.form.columns + data.y] = <CellContainer
                        size={BASE_WIDTH}
                        key={"CellContainer" + data.x + "_" + data.y + (+Date.now().toString(16))}
                        id={data.x + "_" + data.y}
                        x={data.x}
                        y={data.y}
                        landscape={data.content.landscape}
                        object={data.content.object}
                    />
                    return { cells }
                })

            }
            // this.render();

        })

        socket.emit("firstFieldBuildToS", { roomID: this.state.roomID })

    }

    componentDidMount() {


        this._isMounted = true;
        // socket.emit("firstFieldBuildToS", { roomID: this.state.roomID })
    }
    componentWillUnmount() {


        this._isMounted = false;
    }

    updateCell(data, f1) {
        // delete this.cells[data.x * this.state.form.columns + data.y]
        this.setState(prevState => {

            prevState.cells[data.x * this.state.form.columns + data.y] = <CellContainer
                size={BASE_WIDTH}
                key={"CellContainer" + data.x + "_" + data.y + (+Date.now().toString(16))}
                id={data.x + "_" + data.y}
                x={data.x}
                y={data.y}
                landscape={data.content.landscape}
                object={data.content.object}
            />
            return prevState
        })

        // this.cells = [
        //     <CellContainer
        //         size={BASE_WIDTH}
        //         key={"CellContainer" + data.x + "_" + data.y}
        //         id={data.x + "_" + data.y}
        //         x={data.x}
        //         y={data.y}
        //         landscape={data.content.landscape}
        //         object={data.content.object}
        //     />
        // ]
        f1();
    }


    render() {

        // // this.cells = [];


        // if (this.cells.length != 0)

        // //     if (this.state.form.rows > 0 && this.state.form.columns > 0) {
        // //         // for (let i = 0; i < this.state.form.rows; i++)
        // //         //     for (let j = 0; j < this.state.form.columns; j++) {

        // //         //         this.cells[i * this.state.form.columns + j] = (<CellContainer
        // //         //             size={BASE_WIDTH}
        // //         //             key={"CellContainer" + i + "_" + j}
        // //         //             id={i + "_" + j}
        // //         //             x={i}
        // //         //             y={j}
        // //         //             landscape={this.state.content.landscapes[i][j]}
        // //         //             object={this.state.content.objects[i][j]}
        // //         //         />);
        // //         //     }
        // //     }
        // // const res = this.cells
        debugger

        return (

            <div key="fieldBoxKey" className="fieldBox unselectable" >
                <div key="fieldKey" className="field" ref="mainField" >
                    {/* {this.state.cells.map(elem => elem)} */}
                    {this.state.cells}

                </div>
            </div>
        )
    };
}


export default Field;

