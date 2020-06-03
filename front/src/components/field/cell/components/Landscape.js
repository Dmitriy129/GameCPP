import React, { Component } from 'react';
import "../../field.css"

class Landscape extends Component {
    constructor(props) {
        super(props);
        this.state = {
            type: props.type,
            id: props.id
        }
        this.handleClick = this.handleClick.bind(this);
    }

    handleClick() {
    }




    render() {
        return (
            // <div >
            // <img key={this.state.id} src={"/components/field/cell/components/landscapes/" + this.state.type + ".png"} onClick={this.handleClick} alt={"landscape *" + this.state.type + "*"} className="landscape"></img>
            <div key={this.state.id} style={{ background: "url(/components/field/cell/components/landscapes/land" + this.state.type + ".png)" }} onClick={this.handleClick} alt={"landscape *" + this.state.type + "*"} className="landscape" >
                {this.props.children}
            </div>

            // </div>
        )
    }
}

export default Landscape;