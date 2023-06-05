var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { timeLimit } = require(src_path(2637));

fn = timeLimit(
  (fn = async (n) => {
    await new Promise((res) => setTimeout(res, 100));
    return n * n;
  }),
  (t = 50)
);
inputs = [5];
expect(fn(inputs)).to.be.rejectedWith("Time Limit Exceeded");

fn = timeLimit(
  (fn = async (n) => {
    await new Promise((res) => setTimeout(res, 100));
    return n * n;
  }),
  (t = 150)
);
inputs = [5];
expect(fn(...inputs)).to.eventually.equal(25);

fn = timeLimit(
  (fn = async (a, b) => {
    await new Promise((res) => setTimeout(res, 120));
    return a + b;
  }),
  (t = 150)
);
inputs = [5, 10];
expect(fn(...inputs)).to.eventually.equal(15);

fn = timeLimit(
  (fn = async () => {
    throw "Error";
  }),
  (t = 1000)
);
inputs = [];
expect(fn(...inputs)).to.be.rejectedWith("Error");
