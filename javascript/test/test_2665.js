var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { createCounter } = require(src_path(2665));
const test_cases = require(testcases_path(2665));

const zip = require("lodash/zip");

test_cases.forEach((test_case) => {
	const counter = createCounter(test_case.input.init);
	z = zip(test_case.input.calls, test_case.output);
	for (const [c, o] of z) {
		expect(counter[c]()).to.equal(o);
	}
});
