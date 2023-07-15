#include "../src/code_10.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    string p = input["p"].get<string>();
    bool expected = output.get<bool>();
    bool result = sol.isMatch(s, p);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(10);
}