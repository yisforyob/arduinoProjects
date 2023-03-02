import AbstractView from "./AbstractView.js";

export default class extends AbstractView{
    constructor(){
        super();
        this.setTitle("Overview");
    }
    async getHtml(){
        return `
            <h1>Overview</h1>

            <h2>Welcome back</h2>
            <p>
            Here are the current environmental information of the data center. 
            </p>
            <h3> Current Temperature : 23 °C | 73.4 F </h3>
            <h3> Current Humidity : 62.05 % </h3>
            <h3> Current Air Quality : 49 </h3>
            
            <p>
                <a href="https://uottawa-my.sharepoint.com/personal/yngol051_uottawa_ca/Documents/Attachments/Graphique.xlsx?d=w8cec7c12b0c244baaadcf4ba34562b01&csf=1&web=1&e=CncQSF"> View your monthly data and the graphs of the past 7 days</a>
            </p>
            
        `;
        

    }
} 