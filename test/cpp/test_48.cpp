#include "../../src/cpp/code_48.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<int>> matrix = input["matrix"].get<vector<vector<int>>>();
    vector<vector<int>> expected = output.get<vector<vector<int>>>();
    sol.rotate(matrix);
    CHECK_EQ(matrix, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_48.json");
}