/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// for loop
var filter = function (arr, fn) {
  const answer = [];
  for (let i = 0; i < arr.length; i++) {
    const v = fn(arr[i], i);
    if (v) {
      answer.push(arr[i]);
    }
  }
  return answer;
};

module.exports = { filter };
