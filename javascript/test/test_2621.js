var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { sleep } = require(src_path(2621));

delta = 10;
millis = 100;
t = Date.now();
expect(sleep(millis).then(() => Date.now() - t)).to.be.eventually.closeTo(
  millis,
  delta
);

millis = 200;
t = Date.now();
expect(sleep(millis).then(() => Date.now() - t)).to.be.eventually.closeTo(
  millis,
  delta
);
