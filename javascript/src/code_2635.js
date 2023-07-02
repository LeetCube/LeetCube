/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// Preallocate memory: fast if we know the size
var map = function (arr, fn) {
    const answer = new Array(arr.length);
    for (let i = 0; i < arr.length; i++) {
        answer[i] = fn(arr[i], i);
    }
    return answer;
};

// Push values onto array: is like python
// var map = function (arr, fn) {
//     const answer = [];
//     for (let i = 0; i < arr.length; i++) {
//         answer.push(fn(arr[i], i));
//     }
//     return answer;
// };

module.exports = { map };
