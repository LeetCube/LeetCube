#include "../src/code_6.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    string s = input["s"].get<string>();
    int numRows = input["numRows"].get<int>();
    string expected = output.get<string>();
    string result = sol.convert(s, numRows);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(6);
}