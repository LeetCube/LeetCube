#include "../src/code_665.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    bool expected = output.get<bool>();
    bool result = sol.checkPossibility(nums);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(665)
}