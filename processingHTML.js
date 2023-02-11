// node processingHTML.js --source=download.html

// JSDOM library makes the DOM tree for programmers to customize the html data

let minimist = require("minimist");
let jsdom = require("jsdom");
let fs = require("fs");

let args = minimist(process.argv);

fs.readFile(args.source , "utf-8" , function(err,html){
    let dom = new jsdom.JSDOM(html);
    let document = dom.window.document;
    let discription = document.querySelectorAll("#SIvCob > a");
    for(let i=0 ; i<discription.length ; i++){
        console.log(discription[i].textContent);
    }
});