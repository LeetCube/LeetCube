#include "../src/code_338.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    vector<int> expected = output.get<vector<int>>();
    vector<int> result = sol.countBits(n);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(338);
}