#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_12.cpp"

void test(Solution& sol, const json& input, const json& output) {
    int num = input["num"].get<int>();
    string expected = output.get<string>();
    string result = sol.intToRoman(num);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_12.json");
}