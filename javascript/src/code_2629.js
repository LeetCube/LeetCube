/**
 * @param {Function[]} functions
 * @return {Function}
 */
// for loop
var compose = function (functions) {
  return function (x) {
    let answer = x;
    let N = functions.length;
    for (let i = N - 1; i > -1; i--) {
      answer = functions[i](answer);
    }
    return answer;
  };
};
// one liner
// var compose = function (functions) {
//   return (x) => functions.reduceRight((acc, f) => f(acc), x);
// };

module.exports = { compose };
