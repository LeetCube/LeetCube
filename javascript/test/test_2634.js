var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { filter } = require(src_path(2634));

expect(
  filter(
    (arr = [0, 10, 20, 30]),
    (fn = function greaterThan10(n) {
      return n > 10;
    })
  )
).to.eql([20, 30]);

expect(
  filter(
    (arr = [1, 2, 3]),
    (fn = function firstIndex(n, i) {
      return i === 0;
    })
  )
).to.eql([1]);

expect(
  filter(
    (arr = [-2, -1, 0, 1, 2]),
    (fn = function plusOne(n) {
      return n + 1;
    })
  )
).to.eql([-2, 0, 1, 2]);
