#include <algorithm>

#include "../../src/cpp/code_5.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    vector<string> expected = output.get<vector<string>>();
    string result = sol.longestPalindrome(s);
    CHECK_NE(find(expected.begin(), expected.end(), result), expected.end());
}

TEST_CASE("") {
    TEST("test/test_json/test_5.json");
}