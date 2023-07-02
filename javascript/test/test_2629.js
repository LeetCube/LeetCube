var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { compose } = require(src_path(2629));
const test_cases = require(testcases_path(2629));

test_cases.forEach((test_case) => {
    eval(test_case.input.functions);
    fn = compose(functions);
    expect(fn(test_case.input.x)).to.equal(test_case.output);
});
