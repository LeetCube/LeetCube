/**
 * @param {number} n
 * @return {Function} counter
 */
// inner function can access param n in outer function
// Inc then return
var createCounter = function (n) {
  let n_curr = n - 1;
  return function () {
    n_curr += 1;
    return n_curr;
  };
};

// Postfix inc with arrow fn
// var createCounter = function (n) {
//   return () => n++;
// };

module.exports = { createCounter };
