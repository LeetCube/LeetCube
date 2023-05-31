#include "../../src/cpp/code_65.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    bool expected = output.get<bool>();
    bool result = sol.isNumber(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_65.json");
}