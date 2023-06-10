#include "../src/code_35.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"];
    int expected = output.get<int>();
    int result = sol.searchInsert(nums, target);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(35);
}