var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { createCounter } = require(src_path(2620));
const test_cases = require(testcases_path(2620));

test_cases.forEach((test_case) => {
    const counter = createCounter(test_case.input.n);
    test_case.output.forEach((o) => {
        expect(counter()).to.equal(o);
    });
});
