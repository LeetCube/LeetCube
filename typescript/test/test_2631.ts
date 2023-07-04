import * as chai from "chai";
import * as chaiAsPromised from "chai-as-promised";
chai.use(chaiAsPromised);
var expect = chai.expect;

import { src_path, testcases_path } from "./typescript_deps/boilerplate";

async function run() {
	const { f } = await import(src_path(2631));
	const test_cases = await import(testcases_path(2631));
	test_cases.forEach((test_case: any) => {
		const fn = new Function(...test_case.input.fn);
		expect(f(test_case.input.array, fn)).to.eql(test_case.output);
	});
}

run();
