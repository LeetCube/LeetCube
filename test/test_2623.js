var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

const { memoize } = require("../src/code_2623.js");

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
