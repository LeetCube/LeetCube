#include "../src/code_65.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    bool expected = output.get<bool>();
    bool result = sol.isNumber(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(65);
}