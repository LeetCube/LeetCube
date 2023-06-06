var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { once } = require(src_path(2666));
const test_cases = require(testcases_path(2666));

test_cases.forEach((test_case) => {
	eval(test_case.input.fn);
	const onceFn = once(fn);
	const { calls, value } = test_case.output[0];
	var i = 0;
	for (const c of test_case.input.calls) {
		if (i < calls) {
			expect(onceFn(...c)).to.equal(value);
		} else {
			expect(onceFn(...c)).to.be.undefined;
		}
		i++;
	}
});
