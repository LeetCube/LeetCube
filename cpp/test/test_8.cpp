#include "../src/code_8.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    int expected = output.get<int>();
    int result = sol.myAtoi(s);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(8);
}