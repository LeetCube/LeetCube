#include "../src/code_1780.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.checkPowersOfThree(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("../data/json_testcases/test_1780.json");
}