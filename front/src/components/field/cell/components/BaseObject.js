import React, { Component } from 'react';
import "../../field.css"


class BaseObject extends Component {
    constructor(props) {
        super(props);
        this.state = {
            size: props.size,
            type: props.type,
            id: props.id
        }
        this.handleClick = this.handleClick.bind(this);
    }

    handleClick() {
    }
    componentDidMount() {
        // this.setState({
        //     size: this.props.size,
        //     type: this.props.type,
        //     id: this.props.id
        // })
    }

    componentDidUpdate() {
    }




    render() {

        return (

            <div key={this.state.id}
                style={{
                    background: "url(/components/field/cell/components/units/" + this.props.type + ".png)",
                    transform: `matrix(1, 0, 0, 1, ${this.state.size * 0.25}, ${this.state.size * 0.25})`
                }}
                onClick={this.handleClick} alt={"BaseObject *" + this.state.type + "*"}
                className="object" ></div>

        )
    }
}

export default BaseObject;