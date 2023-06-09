#include <algorithm>

#include "../src/code_5.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    vector<string> expected = output.get<vector<string>>();
    string result = sol.longestPalindrome(s);
    CHECK_NE(find(expected.begin(), expected.end(), result), expected.end());
}

TEST_CASE("") {
    TEST(5);
}