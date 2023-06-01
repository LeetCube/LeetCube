#include <algorithm>

#include "../../src/cpp/code_17.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    string digits = input["digits"].get<string>();
    vector<string> expected = output.get<vector<string>>();
    vector<string> result = sol.letterCombinations(digits);

    sort(result.begin(), result.end());

    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_17.json");
}