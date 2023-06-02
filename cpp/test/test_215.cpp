#include "../src/code_215.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int k = input["k"].get<int>();
    int expected = output.get<int>();
    int result = sol.findKthLargest(nums, k);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("../data/json_testcases/test_215.json");
}