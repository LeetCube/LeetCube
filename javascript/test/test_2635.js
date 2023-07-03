var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { map } = require(src_path(2635));
const test_cases = require(testcases_path(2635));

test_cases.forEach((test_case) => {
    expect(map(test_case.input.arr, eval(test_case.input.fn))).to.eql(
        test_case.output
    );
});
