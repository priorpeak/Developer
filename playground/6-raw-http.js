const https = require('https')
const url = 'https://api.darksky.net/forecast/d131f3bf22faf3ec2d3f83cfa003d4b6/40,-75'

const request = https.request(url, (response) => {
    let data = ''

    response.on('data', (chunk) => {
        data = data + chunk.toString()
        console.log(chunk)
    })

    response.on('end', () => {
        const body = JSON.parse(data)
        console.log(body)
    })

})

request.on('error', (error) => {
    console.log('An error.', error)
})

request.end()