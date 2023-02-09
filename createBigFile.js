// node createBigFile.js --dest = f1.

let minimist = require("minimist");
let fs  = require("fs");

let args = minimist(process.argv);

let arr = [];
for(let i=0 ; i<50000000 ; i++){
    arr.push(i);
}

let dtext = arr.join("\n");


// Write create new file or rewrite the existing file from scratch
fs.writeFileSync(args.dest , dtext , "utf-8");
// append add the data after the content in existing file if file not exit then create new file .
fs.appendFileSync(args.dest , dtext , "utf-8")


