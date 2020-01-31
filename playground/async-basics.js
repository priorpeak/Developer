// console.log('Starting app');

// setTimeout(() => {
//   console.log('Inside of callback');
// }, 2000);

// setTimeout(() => {
//     console.log('Second callback works')
// }, 0);

// console.log('Finishing up');

// Break

const add = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(a + b)
    }, 2000)
  })
}

// add(1, 2).then((sum) => {
//   console.log(sum)
//   add(sum, 5).then((sum2) => {
//     console.log(sum2)
//   })
// }).catch((e) => {
//   console.log(e)
// })

// Promise Chaining

add(1, 1).then((sum) => {
  console.log(sum)
  return add(sum, 4)
}).then((sum2) => {
  console.log(sum2)
}).catch((e) => {
  console.log(e)
})