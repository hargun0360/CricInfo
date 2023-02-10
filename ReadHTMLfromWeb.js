// node ReadHTMLfromWeb.js --url="https://www.google.com/" --dest="download.html"

let axios = require("axios");
let minimist = require("minimist");
let fs = require("fs");

let args = minimist(process.argv);
console.log(args.url);

axios.get(args.url)
  .then(response => {
    let html = response.data;
    fs.writeFileSync(args.dest, html, "utf-8");
  })
  .catch(error => {
    console.error(`Error downloading HTML: ${error}`);
  });