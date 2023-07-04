/**
 * @param {number} n
 * @return {string} path
 * @description since we call require in test_n.ts, path is relative to typescript/test/
 */
const src_path = (n: number) => `../src/code_${n}.ts`;
const testcases_path = (n: number) => `../../data/testcases/typescript/test_${n}.json`;

export { src_path, testcases_path };
