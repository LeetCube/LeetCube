var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { curry } = require(src_path(2632));
const test_cases = require(testcases_path(2632));

test_cases.forEach((test_case) => {});
function sum(a, b, c) {
  return a + b + c;
}
const curriedSum = curry(sum);
expect(curriedSum(1)(2)(3)).to.equal(6);
expect(curriedSum(1, 2)(3)).to.equal(6);
expect(curriedSum()()(1, 2, 3)).to.equal(6);

fn = function life() {
  return 42;
};
const curriedLife = curry(fn);
expect(curriedLife()).to.equal(42);
