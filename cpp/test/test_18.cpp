#include "../src/code_18.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"].get<int>();
    vector<vector<int>> expected = output.get<vector<vector<int>>>();
    vector<vector<int>> result = sol.fourSum(nums, target);

    for (auto& v : result) sort(v.begin(), v.end());

    sort(result.begin(), result.end());
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(18);
}