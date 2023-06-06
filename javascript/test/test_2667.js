var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { createHelloWorld } = require(src_path(2667));
const test_cases = require(testcases_path(2667));

test_cases.forEach((test_case) => {
	const f = createHelloWorld();
	expect(f(...test_case.input.args)).to.equal(test_case.output);
});
