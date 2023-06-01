#include "../../src/cpp/code_34.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"];
    vector<int> expected = output.get<vector<int>>();
    vector<int> result = sol.searchRange(nums, target);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_34.json");
}