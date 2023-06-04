var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { createCounter } = require(src_path(2665));

counter = createCounter(5);
expect(counter.increment()).to.equal(6);
expect(counter.reset()).to.equal(5);
expect(counter.decrement()).to.equal(4);

counter = createCounter(0);
expect(counter.increment()).to.equal(1);
expect(counter.increment()).to.equal(2);
expect(counter.decrement()).to.equal(1);
expect(counter.reset()).to.equal(0);
expect(counter.reset()).to.equal(0);
