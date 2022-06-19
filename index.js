
const {program_init, program_data} = require('./build/Release/program.node')

class Program{
  constructor() {}

  init() {
    return new Promise((resolve) => {
      program_init((err, result) => {
        const json = JSON.parse(result)
        resolve(json)
      })
    })
  }
  data(data) {
    const string = JSON.stringify(data)
    return new Promise((resolve) => {
      program_data(string, (err, result) => {
        const json = JSON.parse(result)
        resolve(json)
      })
    })
  }
}
module.exports = Program;
