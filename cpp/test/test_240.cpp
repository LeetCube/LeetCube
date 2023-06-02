#include "../src/code_240.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> matrix = input["matrix"].get<vector<vector<int>>>();
    int target = input["target"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.searchMatrix(matrix, target);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(240);
}