var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { map } = require(src_path(2635));

expect(
  map(
    (arr = [1, 2, 3]),
    (fn = function plusone(n) {
      return n + 1;
    })
  )
).to.eql([2, 3, 4]);

expect(
  map(
    (arr = [1, 2, 3]),
    (fn = function plusI(n, i) {
      return n + i;
    })
  )
).to.eql([1, 3, 5]);

expect(
  map(
    (arr = [10, 20, 30]),
    (fn = function constant() {
      return 42;
    })
  )
).to.eql([42, 42, 42]);
