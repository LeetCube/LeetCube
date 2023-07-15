#include "../src/code_766.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> matrix = input["matrix"].get<vector<vector<int>>>();
    bool expected = output.get<bool>();
    bool result = sol.isToeplitzMatrix(matrix);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(766);
}