// node firstExcel.js --source=teams.json --dest=teams.xls

let minimist = require("minimist");
let fs = require("fs");
let excel = require("excel4node");

let args = minimist(process.argv);

let teamsJSON = fs.readFileSync(args.source , "utf-8");

let teams = JSON.parse(teamsJSON);


let match = {
     // waheguru jji ka khalsa waheguru ji ki fateh
}
 