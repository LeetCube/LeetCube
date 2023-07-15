#include "../src/code_202.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    bool expected = output.get<bool>();
    bool result = sol.isHappy(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(202);
}