import AbstractView from "./AbstractView.js";

export default class extends AbstractView{
    constructor(){
        super();
        this.setTitle("Air Quality");
    }
    async getHtml(){
        return `
            <h1>Air Quality</h1>
            <p>
            Here is the current air quality of the room. The air quality around the servers has improved since last week.
            </p>
            <h1> Current Air Quality : 49 </h1>
            <p>
                <a href="https://www.airnow.gov/aqi/aqi-basics/" target = "blank" > Understand the air quality of the environment</a>.
            </p>
            <p>
                <a href="https://uottawa-my.sharepoint.com/personal/yngol051_uottawa_ca/Documents/Attachments/Graphique.xlsx?d=w8cec7c12b0c244baaadcf4ba34562b01&csf=1&web=1&e=CncQSF" target = "blank"> View your monthly data and the graphs of the past 7 days</a>
            </p>
            
        `;
        

    }
} 