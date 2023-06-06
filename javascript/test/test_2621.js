var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { sleep } = require(src_path(2621));
const test_cases = require(testcases_path(2621));

const delta = 10;
test_cases.forEach((test_case) => {
	const t = Date.now();
	const millis = test_case.input.millis;
	expect(sleep(millis).then(() => Date.now() - t)).to.be.eventually.closeTo(millis, delta);
});
