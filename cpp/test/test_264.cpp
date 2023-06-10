#include "../src/code_264.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    int expected = output.get<int>();
    int result = sol.nthUglyNumber(n);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(264);
}