#include "../../src/cpp/code_13.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    int expected = output.get<int>();
    int result = sol.romanToInt(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_13.json");
}