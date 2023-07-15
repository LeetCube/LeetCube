#include "../src/code_2709.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    bool expected = output.get<bool>();
    bool result = sol.canTraverseAllPairs(nums);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(2709);
}