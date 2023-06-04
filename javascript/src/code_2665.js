/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
// Closure with shortened syntax
// The 2 ways to code reset are equiv
var createCounter = function (init) {
  let curr = init;
  return {
    increment: () => ++curr,
    decrement: () => --curr,
    reset: function () {
      curr = init;
      return curr;
    },
  };
};
// var createCounter = function (init) {
//   let curr = init;
//   return {
//     increment: () => ++curr,
//     decrement: () => --curr,
//     reset: () => (curr = init),
//   };
// };
// Class: this is similar to other languages
// class Counter {
//   constructor(init) {
//     this.init = init;
//     this.curr = init;
//   }
//   increment() {
//     this.curr += 1;
//     return this.curr;
//   }
//   decrement() {
//     this.curr -= 1;
//     return this.curr;
//   }
//   reset() {
//     this.curr = this.init;
//     return this.curr;
//   }
// }
// var createCounter = function (init) {
//   return new Counter(init);
// };

module.exports = { createCounter };
