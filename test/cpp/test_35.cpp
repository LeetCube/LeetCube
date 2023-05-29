#include "../../src/cpp/code_35.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"];
    int expected = output.get<int>();
    int result = sol.searchInsert(nums, target);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_35.json");
}