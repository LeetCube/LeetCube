#include "../src/code_371.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

void test(Solution& sol, const json& input, const json& output) {
    int a = input["a"].get<int>();
    int b = input["b"].get<int>();
    int expected = output.get<int>();
    int result = sol.getSum(a, b);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(371);
}