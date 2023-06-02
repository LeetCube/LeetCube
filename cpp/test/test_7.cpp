#include "../src/code_7.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int x = input["x"].get<int>();
    int expected = output.get<int>();
    int result = sol.reverse(x);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(7);
}