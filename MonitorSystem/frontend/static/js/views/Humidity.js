import AbstractView from "./AbstractView.js";

export default class extends AbstractView{
    constructor(){
        super();
        this.setTitle("Humidity");
    }
    async getHtml(){
        return `
            <h1>Humidity</h1>
            <p>
            Here is the current humidity of the room. The humidity around the servers have been variating  in the past hours. You may need to take actions to stabilize it.
            </p>
            <h1> Current Humidity : 62.05 % </h1>
            <p>
                <a href="https://www.airthings.com/en/contaminants/what-is-humidity" target = "blank"> Understand the humidity of the environment</a>.
            </p>
            <p>
                <a href="https://uottawa-my.sharepoint.com/personal/yngol051_uottawa_ca/Documents/Attachments/Graphique.xlsx?d=w8cec7c12b0c244baaadcf4ba34562b01&csf=1&web=1&e=CncQSF" target = "blank"> View your monthly data and the graphs of the past 7 days</a>
            </p>
            
        `;
        

    }
} 