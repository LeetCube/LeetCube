var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { compose } = require(src_path(2629));

fn = compose((functions = [(x) => x + 1, (x) => x * x, (x) => 2 * x]));
expect(fn((x = 4))).to.equal(65);

fn = compose((functions = [(x) => 10 * x, (x) => 10 * x, (x) => 10 * x]));
expect(fn((x = 1))).to.equal(1000);

fn = compose((functions = []));
expect(fn((x = 42))).to.equal(42);
