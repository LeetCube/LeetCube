#include "../src/code_9.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int x = input["x"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.isPalindrome(x);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(9);
}