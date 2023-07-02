var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { filter } = require(src_path(2634));
const test_cases = require(testcases_path(2634));

test_cases.forEach((test_case) => {
  expect(filter(test_case.input.arr, eval(test_case.input.fn))).to.eql(
    test_case.output
  );
});
