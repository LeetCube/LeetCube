#include "../../src/cpp/code_16.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"].get<int>();
    int expected = output.get<int>();
    int result = sol.threeSumClosest(nums, target);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_16.json");
}