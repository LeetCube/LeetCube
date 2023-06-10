#include "../src/code_278.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    sol.bad = input["bad"].get<int>();
    int expected = output.get<int>();
    int result = sol.firstBadVersion(n);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(278);
}