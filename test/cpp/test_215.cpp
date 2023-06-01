#include "cpp_deps/boilerplate.hpp"
#include "../../src/cpp/code_215.cpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int k = input["k"].get<int>();
    int expected = output.get<int>();
    int result = sol.findKthLargest(nums, k);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_215.json");
}