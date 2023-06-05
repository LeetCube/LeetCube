/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
// We only want to call resolve when last function finishes
// To do this correctly we have to:
// wrap our code in helper, call helper recursively in loop, finally call helper once outside
var promisePool = async function (functions, n) {
  return new Promise((resolve, reject) => {
    let count_started = 0;
    let count_running = 0;
    function helper() {
      if (count_started == functions.length) {
        if (count_running == 0) resolve();
        return;
      }
      while (count_started < functions.length && count_running < n) {
        count_running++;
        functions[count_started++]().then(() => {
          count_running--;
          helper();
        });
      }
    }
    helper();
  });
};

module.exports = { promisePool };

// Wrong cases: resolves before we are done
// var promisePool = async function (functions, n) {
//   return new Promise((resolve, reject) => {
//     let count_started = 0;
//     let count_running = 0;
//     while (count_started < functions.length && count_running < n) {
//       count_running++;
//       functions[count_started++]().then(() => count_running--);
//     }
//     resolve(); // immediately
//   });
// };
// var promisePool = async function (functions, n) {
//   return new Promise((resolve, reject) => {
//     let count_started = 0;
//     let count_running = 0;
//     while (count_started < functions.length && count_running < n) {
//       count_running++;
//       functions[count_started++]().then(() => {
//         count_running--;
//         resolve(); // as soon as 1st function done
//       });
//     }
//   });
// };
