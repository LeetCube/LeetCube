#include "../src/code_14.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<string> strs = input["strs"].get<vector<string>>();
    string expected = output.get<string>();
    string result = sol.longestCommonPrefix(strs);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(14);
}