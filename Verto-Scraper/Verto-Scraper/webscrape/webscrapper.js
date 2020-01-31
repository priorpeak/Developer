// var rp = require('request-promise');
// var cheerio = require('cheerio');

// rp('https//news.ycombinator.com/').then((html)=>{
//     let $ = cheerio.load(html);
//     console.log(html);
//     $('span.comhead').each(function(i,element){
//         var a = $(this).prev();
//         console.log(a.text());
//     });
// }).catch(console.error.bind(console));

var Nightmare = require('nightmare');
var fs = require('fs');
let vo = require('vo');
var path = require('path');

var run = function * () {
    var nightmare = Nightmare({show:true});
    yield nightmare.goto('https://offerup.com/explore/k/electronics/').wait(10000);

    var previousHeight, currentHeight=0;
    while(previousHeight !== currentHeight) {
        previousHeight = currentHeight;
        var products = [];
        var item = {};
        var currentHeight = yield nightmare.inject('js','jquery-3.3.1.min.js').evaluate(function() {
            var container = document.querySelector('.row');
            var scrollHeight = container.scrollHeight;
            return scrollHeight;
        });
        if(currentHeight > 219637) {
            yield nightmare.wait(5000);
            yield nightmare.evaluate(() => {
                return document.querySelector('.row').innerHTML
            }).then(function (page) {
                const $ = cheerio.load(page);
                var product_lists = $('div#db-item-list div').html();
                console.log(product_lists)
                fs.writeFile('electronics-html.txt', product_lists, function (err) {
                    if (err) return console.log(err);
                    console.log('writing to file...');
                });
            }).done();
        }
        if(currentHeight < 2829742) {
            yield nightmare.scrollTo(currentHeight, 0)
                .wait(3000);
            console.log(currentHeight);
        } else {
            yield nightmare.scrollTo(currentHeight, 0)
                .wait(3000);
            console.log(currentHeight);
        }
    }
};

vo(run)(function(err) {
    console.dir(err);
    console.log('done');
});