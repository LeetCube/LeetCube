#include "../src/code_934.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> grid = input["grid"].get<vector<vector<int>>>();
    int expected = output.get<int>();
    int result = sol.shortestBridge(grid);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(934);
}