#include "../src/code_575.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> candyType = input["candyType"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.distributeCandies(candyType);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(575);
}