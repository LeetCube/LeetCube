#include "../../src/cpp/code_934.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> grid = input["grid"].get<vector<vector<int>>>();
    int expected = output.get<int>();
    int result = sol.shortestBridge(grid);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_934.json");
}