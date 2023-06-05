/**
 * @param {Function} fn
 */
// this Q's straight forward, use a hashmap
function memoize(fn) {
  const m = new Map();
  return function (...args) {
    s = JSON.stringify(args);
    if (m.has(s)) {
      return m.get(s);
    }
    m.set(s, fn(...args));
    return m.get(s);
  };
}

module.exports = { memoize };
