#include "../src/code_268.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.missingNumber(nums);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(268);
}