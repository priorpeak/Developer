const rp = require("request-promise");
const $ = require("cheerio");
const download = require("download-pdf");

const url =
  "https://www.who.int/emergencies/diseases/novel-coronavirus-2019/situation-reports/";

rp(url)
  .then(function (html) {
    const pdf = $("strong > a", html).first().attr("href");
    const web = "https://www.who.int";
    const src = web.concat("", pdf);

    var options = {
      filename: "covidInfo.pdf",
    };
    download(src, options, function (err) {
      if (err) throw err;
    });
  })

  .catch(function (err) {
    console.log("You fucked up bitch");
  });
