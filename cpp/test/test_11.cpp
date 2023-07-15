#include "../src/code_11.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<int> height = input["height"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.maxArea(height);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(11);
}