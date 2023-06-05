/**
 * @param {Function} fn
 * @return {Function}
 */
// we only execute fn when we have enough arguments
// if curr args are not enough, we combine curr args with next args
// the pattern is recursive call + if check, see LC Q.2636
var curry = function (fn) {
  return function curried(...args) {
    if (args.length == fn.length) {
      return fn(...args);
    }
    return (...next_args) => curried(...args, ...next_args);
  };
};

module.exports = { curry };
