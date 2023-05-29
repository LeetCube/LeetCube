#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_15.cpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    vector<vector<int>> expected = output.get<vector<vector<int>>>();
    vector<vector<int>> result = sol.threeSum(nums);

    for (auto& v : result) sort(v.begin(), v.end());

    sort(result.begin(), result.end());
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_15.json");
}