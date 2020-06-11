const fs = require("fs");
const pdf = require("pdf-parse");

let dataBuffer = fs.readFileSync("./covidInfo.pdf");

pdf(dataBuffer).then(function (data) {
  fs.writeFileSync("./data.txt", data.text);
});
