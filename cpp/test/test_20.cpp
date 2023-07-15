#include "../src/code_20.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    bool expected = output.get<bool>();
    bool result = sol.isValid(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(20);
}