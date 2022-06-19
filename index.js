
const {input, output} = require('./build/Release/program.node')

class Program{
  constructor() {}

  input(data) {
    const string = JSON.stringify(data)
    return new Promise((resolve) => {
      input(string, (err, result) => {
        const json = JSON.parse(result)
        resolve(json)
      })
    })
  }

  output(data) {
    const string = JSON.stringify(data)
    return new Promise((resolve) => {
      output(string, (err, result) => {
        const json = JSON.parse(result)
        resolve(json)
      })
    })
  }

}
module.exports = Program;
