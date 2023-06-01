#include "../../src/cpp/code_136.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums = input["nums"].get<vector<int>>();
    int expected = output.get<int>();
    int result = sol.singleNumber(nums);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_136.json");
}