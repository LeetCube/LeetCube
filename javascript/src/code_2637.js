/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
// It's a race between resolve and reject
// fn finishes before time limit, resolve
// fn TLE, catch reject
// Want to clear time regardless of outcome
var timeLimit = function (fn, t) {
  return async function (...args) {
    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => reject("Time Limit Exceeded"), t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timeout));
    });
  };
};
// Is .catch(reject) necessary? Yes!
// If you don't want to use catch, Promise.race works
// var timeLimit = function (fn, t) {
//     return async function (...args) {
//         const timeLimitPromise = new Promise((resolve, reject) => {
//             setTimeout(() => reject("Time Limit Exceeded"), t)
//         });
//         const returnedPromise = fn(...args);
//         return Promise.race([timeLimitPromise, returnedPromise]);
//     }
// };

module.exports = { timeLimit };
