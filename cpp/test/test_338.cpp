#include "../src/code_338.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    int n = input["n"].get<int>();
    vector<int> expected = output.get<vector<int>>();
    vector<int> result = sol.countBits(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(338);
}