#include "../src/code_357.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    int expected = output.get<int>();
    int result = sol.countNumbersWithUniqueDigits(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(357);
}