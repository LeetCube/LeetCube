/**
 * @param {number} n
 * @return {string} path
 * @description since we call require in test_n.js, path is relative to javascript/test/
 */
var src_path = (n) => `../src/code_${n}.js`;
var testcases_path = (n) => `../../data/testcases/test_${n}.json`;

module.exports = { src_path, testcases_path };
