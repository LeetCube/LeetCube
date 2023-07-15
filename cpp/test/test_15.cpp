#include "../src/code_15.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    vector<vector<int>> expected = output.get<vector<vector<int>>>();
    vector<vector<int>> result = sol.threeSum(nums);

    for (auto& v : result) sort(v.begin(), v.end());

    sort(result.begin(), result.end());
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(15);
}