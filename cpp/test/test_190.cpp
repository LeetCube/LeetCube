#include "../src/code_190.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    uint32_t n = input["n"].get<uint32_t>();
    uint32_t expected = output.get<uint32_t>();
    uint32_t result = sol.reverseBits(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(190);
}