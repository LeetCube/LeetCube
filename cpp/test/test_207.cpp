#include "../src/code_207.cpp"
#include "cpp_deps/boilerplate.hpp"

void test(Solution& sol, const json& input, const json& output) {
    int numCourses = input["numCourses"].get<int>();
    auto prerequisites = input["prerequisites"].get<std::vector<std::vector<int>>>();
    auto expected = output.get<bool>();
    bool result = sol.canFinish(numCourses, prerequisites);
    CHECK_EQ(result, expected);
}

// asdf
TEST_CASE("") {
    TEST(207);
}