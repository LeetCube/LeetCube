var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { f } = require(src_path(2631));
const test_cases = require(testcases_path(2631));

test_cases.forEach((test_case) => {
    eval(test_case.input.fn);
    expect(f(test_case.input.array, fn)).to.eql(test_case.output);
});
