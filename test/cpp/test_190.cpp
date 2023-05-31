#include "../../src/cpp/code_190.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    uint32_t n = input["n"].get<uint32_t>();
    uint32_t expected = output.get<uint32_t>();
    uint32_t result = sol.reverseBits(n);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_190.json");
}