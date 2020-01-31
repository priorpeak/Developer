require('../src/db/mongoose')
const Task = require('../src/models/task')

Task.findByIdAndDelete('5d24ccce49150a1920eaef58').then((task) => {
    console.log(task)
    return Task.countDocuments({ completed: false })
}).then((result) => {
    console.log(result)
}).catch((e) => {
    console.log(e)
})

const deleteTaskAndCount = async (id) => {
    const task = await Task.findByIdAndDelete(id)
    const count = await Task.countDocuments({ completed: false })
    return count
}

deleteTaskAndCount('5d25fa9cf94bfa32a4dde285').then((count) => {
    console.log(count)
}).catch((e) => {
    console.log(e)
})