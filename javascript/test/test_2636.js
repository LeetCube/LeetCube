var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { promisePool } = require(src_path(2636));
const test_cases = require(testcases_path(2636));

const delta = 10;
test_cases.forEach((test_case) => {
  const t = Date.now();
  eval(test_case.input.functions);
  expect(
    promisePool(functions, test_case.input.n).then(() => Date.now() - t)
  ).to.be.eventually.closeTo(test_case.output[1], delta);
});
