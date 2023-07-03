var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path, testcases_path } = require("./javascript_deps/boilerplate");
const { memoize } = require(src_path(2623));
const test_cases = require(testcases_path(2623));

callCount = 0;
const sum = (a, b) => {
    callCount++;
    return a + b;
};
const memoizedSum = memoize(sum);
expect(memoizedSum(2, 2)).to.equal(4);
expect(callCount).to.equal(1);
expect(memoizedSum(2, 2)).to.equal(4);
expect(callCount).to.equal(1);
expect(memoizedSum(1, 2)).to.equal(3);
expect(callCount).to.equal(2);
