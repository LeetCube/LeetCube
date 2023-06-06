var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { timeLimit } = require(src_path(2637));
const test_cases = require(testcases_path(2637));

test_cases.forEach((test_case) => {
	eval(test_case.input.fn);
	const limited = timeLimit(fn, test_case.input.t);
	if (Object.hasOwn(test_case.output, "rejected")) {
		expect(limited(test_case.input.inputs)).to.be.rejectedWith(test_case.output.rejected);
	} else {
		expect(limited(...test_case.input.inputs)).to.eventually.equal(test_case.output.resolved);
	}
});
