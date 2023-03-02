import AbstractView from "./AbstractView.js";

export default class extends AbstractView{
    constructor(){
        super();
        this.setTitle("Temperature");
    }
    async getHtml(){
        return `
            <h1> Temperature </h1>
            <p>
            Here is the current temperature of the room. The temperature around the servers have been pretty steady in the past hours.
            </p>
            <h1> Current Temperature : 23 °C | 73.4 F </h1>
            <p>
               <a href="https://uottawa-my.sharepoint.com/personal/yngol051_uottawa_ca/Documents/Attachments/Graphique.xlsx?d=w8cec7c12b0c244baaadcf4ba34562b01&csf=1&web=1&e=CncQSF" target = "blank"> View your monthly data and the graphs of the past 7 days</a>
            </p>
            
        `;
        

    }
} 