#include "../src/code_9.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    int x = input["x"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.isPalindrome(x);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(9);
}