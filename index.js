// const hello = require('./build/Release/hello.node');
const hello = require('bindings')('hello');

console.log(hello.greeting());