#include "../src/code_2679.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    auto nums = input["nums"].get<std::vector<std::vector<int>>>();
    const auto expected = output.get<int>();
    const auto result = sol.matrixSum(nums);
    CHECK_EQ(expected, result);
}

TEST_CASE("") {
    TEST(2679);
}