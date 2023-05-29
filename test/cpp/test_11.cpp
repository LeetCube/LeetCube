#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_11.cpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> height = input["height"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.maxArea(height);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_11.json");
}