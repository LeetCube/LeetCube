#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_14.cpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<string> strs = input["strs"].get<vector<string>>();
    string expected = output.get<string>();
    string result = sol.longestCommonPrefix(strs);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_14.json");
}