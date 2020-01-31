const fs = require('fs'),
    request = require('request');
const FormData = require('form-data');
const csv = require('csvtojson');
// TODO: Edit the csv file for different categories
const csvFilePath = './electronics.csv';
const slugify = require('slugify');
const download = require('image-downloader');
const axios = require('axios');
const s3 = require('./awss3');
const md5 = require('md5');
const sleep = require('sleep');

// var download = function(uri, filename, callback){
//   request.head(uri, function(err, res, body){
//     // console.log('content-type:', res.headers['content-type']);
//     // console.log('content-length:', res.headers['content-length']);

//     request(uri).pipe(fs.createWriteStream(filename)).on('close', callback);
//   });
// };

async function uploadProducts() {
    try{
        let productArray = await csv().fromFile(csvFilePath); 
        for (var i = 0; i < productArray.length; i++){
        let filename = await download.image({
            url: productArray[i].img,
            dest: 'img/'+slugify(productArray[i].title)+'.jpg',
        })
        let imageFile = filename.filename;  
        // TODO: Edit the categories
        let category = 'Electronics';
        let token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6InBhYmxvZmVyQHZlcnRvc3RvcmUuY29tIiwidXNlcl9pZCI6IjViYzNkMGEyZGY5MTY4ZmYwMzAxMDZkYiIsInZlcnRvX2lkIjoiZWZkMDMwZDkwMGIwYTM4MWM2YzYxODk4MGVlMzMxYjgiLCJpYXQiOjE1Mzk1NTk1ODYsImV4cCI6MTUzOTY0NTk4Nn0.EJThLs9bfZu86nJxEWbMw-h14pEMqyKrOklK4MsoU_o';
        let imageData = fs.readFileSync(imageFile);
        var params = {
            Bucket: 'vertomediafiles-2',
            Key: md5(productArray[i].title),
            Body: imageData,
            ContentType: 'image/jpeg',
            ACL:'public-read'
        };
        let uploadImg = await s3.upload(params).promise();
        var settings = {
            "async": true,
            "crossDomain": true,
            "url": "http://localhost:5000/api/products/",
            "method": "POST",
            "dataType": "json",
            "headers": {
                "Content-Type": "application/json",
                "Authorization": `Bearer ` + token,
            },
            "processData": false,
            "data": {
                'image_link': uploadImg.Location,
                'minimum_price': productArray[i].price*100,
                'coordinates': {
                    'lat': 42.361145,
                    'lng': -71.057083,
                },
                'address': '736 Commonwealth Avenue, Boston, MA 02215',
            }
        };
        let productData = await axios(settings);
        let product = productData.data.product;
        var settings = {
            "async": true,
            "crossDomain": true,
            "url": "http://localhost:5000/api/products/" + product._id,
            "method": "PATCH",
            "headers": {
                "Content-Type": "application/json",
                "Authorization": `Bearer ` + token
            },
            "dataType": "json",
            "processData": false,
            "data": [
                {
                    'propName': 'title',
                    'value': productArray[i].title,
                },
                {
                    'propName': 'category',
                    'value': category,
                }
            ]
        }
        let success = await axios(settings);
        if (success){
            console.log('Finished uploading '+ productArray[i].title);
        }

    }
    } catch(e){
        console.log(e);
    }
};

uploadProducts();
// const productsArray = csv().fromFile(csvFilePath).then(productsArray => {
//     productsArray.map(product => {
//         let imageName = slugify(product.title);
//         let imageFileName = imageName + '.png'
//         download(product.img , imageFileName, function (response){
//             console.log('Downloaded ' + imageFileName);
//             let imageData = fs.readFileSync(imageFileName);
//             var params = {
//                 Bucket: 'vertomediafiles-2',
//                 Key: 'upload/'+ imageName,
//                 Body: imageData,
//                 ACL:'public-read'
//             };
//             let token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6InBhYmxvZmVyQHZlcnRvc3RvcmUuY29tIiwidXNlcl9pZCI6IjViYzNkMGEyZGY5MTY4ZmYwMzAxMDZkYiIsInZlcnRvX2lkIjoiZWZkMDMwZDkwMGIwYTM4MWM2YzYxODk4MGVlMzMxYjgiLCJpYXQiOjE1Mzk1NTk1ODYsImV4cCI6MTUzOTY0NTk4Nn0.EJThLs9bfZu86nJxEWbMw-h14pEMqyKrOklK4MsoU_o'
//             let imageLink = s3.upload(params, async function(err, response){
//                 if(err){
//                     return err;
//                 } else {
//                     try{
//                     var settings = {
//                         "async": true,
//                         "crossDomain": true,
//                         "url": "http://localhost:5000/api/products/",
//                         "method": "POST",
//                         "dataType": "json",
//                         "headers": {
//                             "Content-Type": "application/json",
//                             "Authorization": `Bearer ` + token,
//                         },
//                         "processData": false,
//                         "data": {
//                             'image_link': response.Location,
//                             'minimum_price': product.price,
//                             'coordinates': {
//                                 'lat': '42.361145',
//                                 'lng': '-71.057083',
//                             },
//                             'address': '736 Commonwealth Avenue, Boston, MA 02215',
//                         }
//                     };
//                     let productData = await axios(settings);
//                     console.log(productData);
//                     var settings = {
//                             "async": true,
//                             "crossDomain": true,
//                             "url": "http://localhost:5000/api/products/" + response.data.product._id,
//                             "method": "PATCH",
//                             "headers": {
//                                 "Content-Type": "application/json",
//                                 "Authorization": `Bearer ` + token
//                             },
//                             "dataType": "json",
//                             "processData": false,
//                             "data": [
//                                 {
//                                     'propName': 'title',
//                                     'value': productData.data.product.title,
//                                 },
//                                 {
//                                     'propName': 'category',
//                                     'value': 'Electronics'
//                                 }
//                             ]
//                         }
//                     let success = await axios(settings);
//                     if (success){
//                         console.log('Finished uploading');
//                     }
//                 }catch (err) {
//                     console.log(err);
//                 }
//                 }
//             });
//         });
//     })
// });



