#include "../src/code_191.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    uint32_t u = input["u"].get<uint32_t>();
    int expected = output.get<int>();
    int result = sol.hammingWeight(u);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(191);
}