#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_4.cpp"

void test(Solution& sol, const json& input, const json& output) {
    vector<int> nums1 = input["nums1"].get<vector<int>>();
    vector<int> nums2 = input["nums2"].get<vector<int>>();
    double expected = output.get<double>();
    double result = sol.findMedianSortedArrays(nums1, nums2);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_4.json");
}