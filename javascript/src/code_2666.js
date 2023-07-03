/**
 * @param {Function} fn
 * @return {Function}
 */
// it's fine to not write `return undefined`, since that's the default
var once = function (fn) {
    let has_called = false;
    return function (...args) {
        if (!has_called) {
            has_called = true;
            return fn(...args);
        }
        return undefined;
    };
};

module.exports = { once };
