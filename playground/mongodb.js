// CRUD create read update delete

// const mongodb = require('mongodb')
// const MongoClient = mongodb.MongoClient
// const ObjectID = mongodb.ObjectID

const { MongoClient, ObjectID } = require('mongodb')

const connectionURL = 'mongodb://127.0.0.1:27017'
const databaseName = 'task-manager'

const id = new ObjectID()

MongoClient.connect(connectionURL, { useNewUrlParser: true }, (error, client) => {
    if (error) {
        return console.log('Unable to connect to the database.')
    }

    const db = client.db(databaseName)

    db.collection('users').deleteMany({
        age: 19
    }).then((result) => {
        console.log(result)
    }).catch((error => {
        console.log(error)
    }))

    db.collection('tasks').deleteOne({
        Description: "Get pussy"
    }).then((result) => {
        console.log(result)
    }).catch((error => {
        console.log(error)
    }))
})