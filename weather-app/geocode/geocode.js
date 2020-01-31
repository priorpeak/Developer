const request = require('request');

var geocodeAddress = (address, callback) => {
    var addr = encodeURIComponent(address);

    request({
        url: `http://www.mapquestapi.com/geocoding/v1/address?key=FQRr5kdSxJbf3WAxlxRaUaQE8EqnVBkw&location=${addr}`,
        json: true
    }, (error, response, body) => {
        if (error) {
            callback('Unable to connect to Mapquest servers.')
        } else if (body.results[0].locations[0].geocodeQualityCode === 'A1XAX') {
            callback('Unable to find that address.');
        } else if (body.results[0].locations[0].geocodeQualityCode != 'A1XAX') {
            callback(undefined, {
                address: body.results[0].locations[0].adminArea5,
                latitude: body.results[0].locations[0].latLng.lat,
                longitude: body.results[0].locations[0].latLng.lng
            });  
        }
    });
};

module.exports.geocodeAddress = geocodeAddress;