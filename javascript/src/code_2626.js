/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
// for loop
var reduce = function (nums, fn, init) {
  let accum = init;
  for (let i = 0; i < nums.length; i++) {
    accum = fn(accum, nums[i]);
  }
  return accum;
};
// foreach loop
// var reduce = function (nums, fn, init) {
//     let accum = init;
//     nums.forEach((n) => { accum = fn(accum, n); });
//     return accum;
// };

module.exports = { reduce };
