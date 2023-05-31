#include "../../src/cpp/code_3.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    int expected = output.get<int>();
    int result = sol.lengthOfLongestSubstring(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_3.json");
}