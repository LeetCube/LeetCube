#include "../../src/cpp/code_9.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    int x = input["x"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.isPalindrome(x);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_9.json");
}