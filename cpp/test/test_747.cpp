#include "../src/code_747.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.dominantIndex(nums);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(747);
}