var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { reduce } = require(src_path(2626));
const test_cases = require(testcases_path(2626));

test_cases.forEach((test_case) => {
  eval(test_case.input.fn);
  expect(reduce(test_case.input.nums, fn, test_case.input.init)).to.equal(
    test_case.output
  );
});
