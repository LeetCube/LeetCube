#include "../src/code_34.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int target = input["target"];
    vector<int> expected = output.get<vector<int>>();
    vector<int> result = sol.searchRange(nums, target);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(34);
}