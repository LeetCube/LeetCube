#include "../src/code_12.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    int num = input["num"].get<int>();
    string expected = output.get<string>();
    string result = sol.intToRoman(num);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(12);
}