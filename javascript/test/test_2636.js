var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { promisePool } = require(src_path(2636));

delta = 10;
t = Date.now();
expect(
  promisePool(
    (functions = [
      () => new Promise((res) => setTimeout(res, 300)),
      () => new Promise((res) => setTimeout(res, 400)),
      () => new Promise((res) => setTimeout(res, 200)),
    ]),
    (n = 2)
  ).then(() => Date.now() - t)
).to.be.eventually.closeTo(500, delta);

t = Date.now();
expect(
  promisePool(
    (functions = [
      () => new Promise((res) => setTimeout(res, 300)),
      () => new Promise((res) => setTimeout(res, 400)),
      () => new Promise((res) => setTimeout(res, 200)),
    ]),
    (n = 5)
  ).then(() => Date.now() - t)
).to.be.eventually.closeTo(400, delta);

t = Date.now();
expect(
  promisePool(
    (functions = [
      () => new Promise((res) => setTimeout(res, 300)),
      () => new Promise((res) => setTimeout(res, 400)),
      () => new Promise((res) => setTimeout(res, 200)),
    ]),
    (n = 1)
  ).then(() => Date.now() - t)
).to.be.eventually.closeTo(900, delta);
