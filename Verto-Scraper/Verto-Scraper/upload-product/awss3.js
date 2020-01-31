const AWS = require('aws-sdk');

//config for AWS
AWS.config.update({region:'us-east-1'});
//AWS.config.credentials = credentials;
AWS.config.loadFromPath('config.json');

// s3 bucket
const s3 = new AWS.S3({apiVersion: "latest"});
const bucketParams = {Bucket: 'vertomediafiles-2'};

// call S3 to retrieve CORS configuration for selected bucket
s3.getBucketCors(bucketParams, function(err, data){
    if (err){
        console.log(err);
    } else if (data){
        console.log(JSON.stringify(data.CORSRules));
    }
});

module.exports = s3;