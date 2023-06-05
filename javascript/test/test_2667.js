var chai = require("chai");
var chaiAsPromised = require("chai-as-promised");
chai.use(chaiAsPromised);
var expect = chai.expect;

var { src_path } = require("./javascript_deps/boilerplate")
const { createHelloWorld } = require(src_path(2667));

const f = createHelloWorld();
expect(f()).to.equal("Hello World");
