import AbstractView from "./AbstractView.js";

export default class extends AbstractView{
    constructor(){
        super();
        this.setTitle("Temperature");
    }
    async getHtml(){
        return 
            <> 
            <h1> Welcome back, Dear User</h1>
            <p>
            Here is the current temperature of the room.
            </p>
            <p>
                <a href="/humidity" data-link> View Humidity</a>.
            </p>
            </>
        ;
        

    }
} 